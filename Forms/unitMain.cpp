//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>

#include "projectGlobals.h"

#include "unitOpenNew.h"
#include "unitClose.h"
#include "unitOptions.h"
#include "unitPrintMessage.h"
#include "unitSetPrinter.h"
#include "unitSetConfigFolder.h"
#include "unitSaveMessage.h"

#include "unitMain.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// INITIALIZATIONS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//------------------------------------------------------------------------------
// Constructor
__fastcall TformMain::TformMain(TComponent* Owner)
	: TForm(Owner)
{
	infoLabel->Caption =
"		OPG Ivan Tvrdojević\n\
		Donja Bebrina 128A\n\
		35208 Ruščica\n\
		OIB:29508517356\n\
		\n\
		Tel: 035/226-104\n\
		Mob: 0998507047\n\
		e-mail:\n\
		tvrdojevic.ivan@gmail.com";
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// New receipt
void TformMain::makeNew()
{
	programData.setFieldOf_receiptNumber();
	spinEditReceiptNumber->Value += 1;

	editCard->Text = formSetConfigFolder->mainCard->Text;

	editArticleID->Text = "";
	editQuantity->Text = "0";
	editWholesalePrice->Text = "0";
	labelNoPdv1->Caption = "";
	labelNoPdv->Caption = "";
	labelOnlyPdv->Caption = "";
	labelTotalSum->Caption = "";
	editWholesaleDiscount->Text = "0";
	editPdv->Text = "13";

	validate(editPdv, &pdv);
	validate(editQuantity, &quantity);
	validate(editWholesalePrice, &vpc);
	validate(comboBoxArticleTypes);

	TDateTime dt(2021, 1, 1);
	datePickerServiceDate->Date = dt;
	datePickerIssueDate->Date = dt;
	datePickerArrivalDate->Date = dt;

	datePickerServiceDate->Color = clRed;
	datePickerIssueDate->Color = clRed;
	datePickerArrivalDate->Color = clRed;

	programData.setFieldOf_OIBs();
	programData.setFieldOf_articleTypes();

	addUniqueItemToComboBox(comboBoxMeasureUnit, "kg");
	addUniqueItemToComboBox(comboBoxMeasureUnit, "g");
	comboBoxMeasureUnit->ItemIndex = 0;

	receiptSaved = false;
}
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//																 INITIALIZATIONS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// VALIDATIONS LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void TformMain::validate(TEdit *edit, float *var){
	validatedFloat = true;
	edit->Color = clRed;
	if(edit->Text != "" && edit->Text != "0"){
		try{
			*var = StrToFloat(edit->Text);
			edit->Color = clMoneyGreen;
		}
		catch (EConvertError &E){
			showMessageCustomWrp("Unijeli ste slovo ili broj u polje u kojem smiju biti samo brojevi i jedan decimalni zarez!");
			validatedFloat = false;
		}
	}else
		*var = 0;
}

void TformMain::validate(TComboBox *combo){
	combo->Color = clRed;
	if(combo->Text != ""){
			combo->Color = clMoneyGreen;
	}
}

void TformMain::validateDate(){
	validatedDate = true;

	if(!(datePickerServiceDate->Date <= datePickerIssueDate->Date &&
		 datePickerIssueDate->Date <= datePickerArrivalDate->Date)){
		   showMessageCustomWrp("Datum isporuke mora biti manji ili jednak od datuma izdavanja, a datum izdavanja mora biti manji ili jednak od datuma dospijeća!");
		validatedDate = false;
	}

	TDateTime initialDate(2021, 1, 1);
	if(datePickerServiceDate->Date == initialDate
		|| datePickerIssueDate->Date == initialDate
		|| datePickerArrivalDate->Date == initialDate){
		   showMessageCustomWrp("Datum izdavanja/isporuke/dospijeca nije postavljen!");
		validatedDate = false;
	}
}

void TformMain::validateDateColor(TDatePicker* checkDt){
	checkDt->Color = clMoneyGreen;
	TDateTime dt(2021, 1, 1);
	if(checkDt->Date == dt)
		checkDt->Color = clRed;
}

void TformMain::validateDateColor(){
	validateDateColor(datePickerServiceDate);
	validateDateColor(datePickerIssueDate);
	validateDateColor(datePickerArrivalDate);
}

void TformMain::validateCard(){
	validatedCard = true;
	RADstring card = editCard->Text;

	if(card[1] == DEBUG_BEGIN[1])
		return;

	if(card[1] < 65 || card[1] > 90 || card[2] < 65 || card[2] > 90){
		showMessageCustomWrp("Pogreška pri unosu žiro računa: HR se ne nalazi na početku!");
		validatedCard = false;
	}
}

void TformMain::validateOib(){
	validatedOib = true;
	if(comboBoxOIBs->Text.Length() != 11 && comboBoxOIBs->Text != ""){
		showMessageCustomWrp("Pogreška pri unosu OIB-a: OIB se sastoji od 11 znamenki!");
		validatedOib = false;
	}
	RADstring oib = comboBoxOIBs->Text;
	for(int i = 1; i < comboBoxOIBs->Text.Length() + 1; i++){
		if (oib[i] < 48 || oib[i] > 57) {
			showMessageCustomWrp("Pogreška pri unosu OIB-a: OIB sadrzava samo brojeve!");
			validatedOib = false;
		}
	}

}

bool TformMain::validateAll(){
	if(skipValidate){
		return true;
	}

	bool retVal = true;

	validateDate();
    retVal = validatedDate;

	validateDateColor();

	validateCard();
	validateOib();

	if(!(validatedOib && validatedFloat && validatedCard)){
		retVal = false;
	}

	if(!checkEmpty()){
		retVal = false;
	}

	validate(comboBoxArticleTypes);

	return retVal;
}

bool TformMain::checkEmpty()
{
	if( editQuantity->Text == "" ||
		editWholesalePrice->Text == "" ||
		comboBoxArticleTypes->Text == "" ||
		comboBoxMeasureUnit->Text == "")
	{
		showMessageCustomWrp("Jedno od obveznih polja Vam je prazno (kolicina/VPC/vrsta robe/JM). Popravite prije nastavka!");
		return false;
	}

	return true;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															   VALIDATIONS LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// CALCULATION LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void TformMain::calculate(){
	noPdv = vpc * quantity;
	labelNoPdv->Caption = FormatFloat("#########.00", noPdv);
	labelNoPdv1->Caption =  FormatFloat("#########.00", noPdv);
	labelOnlyPdv->Caption =  FormatFloat("#########.00", noPdv * (pdv / 100));
	labelTotalSum->Caption = FormatFloat("#########.00", noPdv + noPdv * (pdv / 100));
}

void __fastcall TformMain::editPdvChange(TObject *Sender)
{
	validate(editPdv, &pdv);
	labelPdvkurco->Caption = editPdv->Text;
	calculate();
}

void __fastcall TformMain::editQuantityChange(TObject *Sender)
{
	validate(editQuantity, &quantity);
	calculate();
}

void __fastcall TformMain::editWholesalePriceChange(TObject *Sender)
{
	validate(editWholesalePrice, &vpc);
	calculate();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															   CALCULATION LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PRINTING LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//------------------------------------------------------------------------------
// Printing to canvas
void TformMain::printReceipt(){

	Printer()->BeginDoc();
	try {
		//setup background
		Printer()->Canvas->StretchDraw(
			Rect(0, 0, pgWidth, pgHeight),
			imageFirstPage->Picture->Graphic);
		//place text
		Printer()->Canvas->Brush->Style = bsClear;
		Printer()->Canvas->Font = fontDlgPrint->Font;
		Printer()->Canvas->TextOut(2900, 2675, IntToStr(spinEditReceiptNumber->Value) + "/1/1");
		Printer()->Canvas->TextOut(3180, 2940, datePickerServiceDate->Date);
		Printer()->Canvas->TextOut(3180, 3060, timePickerIssueTime->Time);
		Printer()->Canvas->TextOut(3180, 3180, datePickerArrivalDate->Date);
		Printer()->Canvas->TextOut(3180, 3300, datePickerServiceDate->Date);
		Printer()->Canvas->TextOut(3180, 3650, editCard->Text);
		Printer()->Canvas->TextOut(1010, 3965, comboBoxOIBs->Text);
		Printer()->Canvas->TextOut(700, 4565, editArticleID->Text);
		Printer()->Canvas->TextOut(1350, 4565, comboBoxArticleTypes->Text);
		Printer()->Canvas->TextOut(2200, 4565, editQuantity->Text);
		Printer()->Canvas->TextOut(2535, 4565, comboBoxMeasureUnit->Text);
		Printer()->Canvas->TextOut(2790, 4565, editWholesalePrice->Text);
		Printer()->Canvas->TextOut(3430, 4565, "string neki bezveze "); //editPdv->Text
		Printer()->Canvas->TextOut(4075, 4565, labelNoPdv->Caption);
		Printer()->Canvas->TextOut(4075, 5220, labelNoPdv1->Caption);
		Printer()->Canvas->TextOut(4075, 5360, labelOnlyPdv->Caption);
		Printer()->Canvas->TextOut(4075, 5470, labelTotalSum->Caption);
	}
	__finally {
		Printer()->EndDoc();
	}
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Device printing
void TformMain::printToFile(){
	// get receipt path
	RADstring receiptPrintFileName = formOptions->getReceiptFileNameWitouthExt() + ".pdf";

	// convert wstring to wchar_t array
	wcscpy(outFileName, strConvert(receiptPrintFileName).c_str());

	// set print filename
	THandle DeviceMode;
	TCHAR Device[80], Driver[80], Port[80];
	Printer()->PrinterIndex = Printer()->Printers->IndexOf("Microsoft Print to PDF");
	Printer()->GetPrinter(Device, Driver, Port, DeviceMode);
	Printer()->SetPrinter(Device, Driver, outFileName, DeviceMode);

	pgWidth = Printer()->PageWidth;
	pgHeight = Printer()->PageHeight;

	printReceipt();
}

void TformMain::printWithPrinter(){
	Printer()->PrinterIndex = Printer()->Printers->IndexOf(formOptions->comboBoxPrinters->Text);
	Printer()->Copies = spinEditCopies->Value;
	printReceipt();
}

void TformMain::doThePrint(){
	if(formOptions->comboBoxPrinters->Text == "")
	{
		formSetPrinter->ShowModal();
		return;
	}

	printToFile();
	printWithPrinter();
}
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															      PRINTING LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PROGRAM DATA LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void TformMain::saveFormProgramDataFields(){
	addUniqueItemToComboBox(comboBoxOIBs);
	addUniqueItemToComboBox(comboBoxArticleTypes);

	programData.update_receiptNumber();
	programData.update_OIBs();
	programData.update_articleTypes();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															  PROGRAM DATA LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// RECEIPT LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

RADstring TformMain::getReceiptFileName(){
	return formOptions->getReceiptFileNameWitouthExt() + RECEIPT_EXTENSION;
}

//------------------------------------------------------------------------------
//                   update receipt fields from receipt file
void TformMain::updateFieldsFromReceipt(_di_IXMLreceiptType receipt){
	spinEditReceiptNumber->Value = receipt->number;
	datePickerServiceDate->Date = receipt->serviceDate;
	datePickerIssueDate->Date = receipt->issueDate;
	timePickerIssueTime->Time = timePickerIssueTime->Time;
	datePickerArrivalDate->Date = receipt->arrivalDate;
	editCard->Text = receipt->card;
	comboBoxOIBs->Text = receipt->OIB;
	editArticleID->Text = receipt->articleID;
	comboBoxArticleTypes->Text = receipt->articleType;
	editQuantity->Text = receipt->quantity;
	comboBoxMeasureUnit->Text = receipt->measureUnit;
	editWholesalePrice->Text = receipt->wholesalePrice;
	editWholesaleDiscount->Text = receipt->wholesaleDiscount;
	editPdv->Text = receipt->pdv;
}

void TformMain::openReceipt(){
	_di_IXMLreceiptType receipt = Loadreceipt(FileOpenDialog1->FileName);
	updateFieldsFromReceipt(receipt);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                   update receipt file from receipt fields
void TformMain::saveReceipt(){
	_di_IXMLreceiptType receipt = Getreceipt(XMLDocReceipt);

	receipt->number = spinEditReceiptNumber->Value;
	receipt->serviceDate = datePickerServiceDate->Date;
	receipt->issueDate = datePickerIssueDate->Date;
	receipt->issueTime = timePickerIssueTime->Time;
	receipt->arrivalDate = datePickerArrivalDate->Date;
	receipt->card = editCard->Text;
	receipt->OIB = comboBoxOIBs->Text;
	receipt->articleID = editArticleID->Text;
	receipt->articleType = comboBoxArticleTypes->Text;
	receipt->quantity = editQuantity->Text.ToDouble();
	receipt->measureUnit = comboBoxMeasureUnit->Text;
	receipt->wholesalePrice = editWholesalePrice->Text.ToDouble();
	receipt->wholesaleDiscount = editWholesaleDiscount->Text.ToDouble();
	receipt->pdv = editPdv->Text.ToDouble();

	XMLDocReceipt->SaveToFile(getReceiptFileName());
	receiptSaved = True;
}
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															   	   RECEIPT LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// FORM CONTROLS EVENTS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void __fastcall TformMain::buttonNewClick(TObject *Sender)
{
	formOpenNew->ShowModal();
}

void __fastcall TformMain::btnPrintClick(TObject *Sender)
{
	if(!validateAll()) return;

	doThePrint();

	saveReceipt();
	saveFormProgramDataFields();

	formPrintMessage->ShowModal();
}

void __fastcall TformMain::buttonSaveClick(TObject *Sender)
{
	if(!validateAll()) return;

	saveReceipt();
    saveFormProgramDataFields();

	formSaveMessage->ShowModal();
}

void __fastcall TformMain::buttonOpenClick(TObject *Sender)
{
	FileOpenDialog1-> DefaultFolder = formOptions->editReceiptFilePath->Text;
	FileOpenDialog1->FileTypes->Items[0]->FileMask = RECEIPT_MASK;
	if(!FileOpenDialog1->Execute()) return;

	openReceipt();

	validateAll();
}

void __fastcall TformMain::TimerTimer(TObject *Sender)
{
	if(checkBoxTime->State == cbUnchecked){
		timePickerIssueTime->Time = GetTime();
	}
}

void __fastcall TformMain::checkBoxTimeClick(TObject *Sender)
{
	timePickerIssueTime->Enabled = (checkBoxTime->State == cbChecked);
}

void __fastcall TformMain::datePickerServiceDateChange(TObject *Sender)
{
	datePickerServiceDate->Color = clMoneyGreen;
	datePickerIssueDate->Date = datePickerServiceDate->Date;
	datePickerArrivalDate->Date = IncMonth(datePickerServiceDate->Date, 1);
}

void __fastcall TformMain::datePickerIssueDateChange(TObject *Sender)
{
	datePickerIssueDate->Color = clMoneyGreen;
}

void __fastcall TformMain::datePickerArrivalDateChange(TObject *Sender)
{
	datePickerArrivalDate->Color = clMoneyGreen;
}

void __fastcall TformMain::Button1Click(TObject *Sender)
{
	formClose->ShowModal();
}

void __fastcall TformMain::Button3Click(TObject *Sender)
{
	formOptions->ShowModal();
}

void __fastcall TformMain::FormShow(TObject *Sender)
{
	makeNew();
}

void __fastcall TformMain::comboBoxArticleTypesChange(TObject *Sender)
{
	validate(comboBoxArticleTypes);
}

void __fastcall TformMain::editCardChange(TObject *Sender)
{
	if(editCard->Text == DEBUG_MEMO) Memo1->Show();
	if(editCard->Text == DEBUG_NOVAL) skipValidate = true;
	if(editCard->Text == DEBUG_ENABLEOUT) enableDbgOut = true;

	if(editCard->Text == DEBUG_DISABLE)
	{
		Memo1->Hide();
		skipValidate = false;
	}

	if(editCard->Text == DEBUG_RESET)
	{
		formSetConfigFolder->readProgramDataPath();
		TDirectory::Delete(formSetConfigFolder->programDataPath, true);
		formSetConfigFolder->reg->DeleteKey(REGISTRY_KEY);
		Application->Terminate();
	}
}

void __fastcall TformMain::checkBoxIssueDateClick(TObject *Sender)
{
	datePickerIssueDate->Enabled = (checkBoxIssueDate->State == cbChecked);
	if(!datePickerIssueDate->Enabled)
		datePickerIssueDate->Color = clBtnFace;
}

void __fastcall TformMain::checkBoxArrivalDateClick(TObject *Sender)
{
	datePickerArrivalDate->Enabled = (checkBoxArrivalDate->State == cbChecked);
	if(!datePickerArrivalDate->Enabled)
		datePickerArrivalDate->Color = clBtnFace;
}

void __fastcall TformMain::FormCreate(TObject *Sender)
{
	int diff = comboBoxArticleTypes->Left - (editArticleID->Left + editArticleID->Width);

	StringGrid1->ColWidths[0] = editArticleID->Width + diff/2;
	StringGrid1->ColWidths[1] = comboBoxArticleTypes->Width + diff;
	StringGrid1->ColWidths[2] = editQuantity->Width + diff;
	StringGrid1->ColWidths[3] = comboBoxMeasureUnit->Width + diff;
	StringGrid1->ColWidths[4] = editWholesalePrice->Width + diff;
	StringGrid1->ColWidths[5] = labelNoPdv->Width + diff;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************

