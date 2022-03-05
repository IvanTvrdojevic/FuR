//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>

#include "utils.h"
#include "common.h"

#include "unitMain.h"               //Main

#include "unitOpenNew.h"            //OpenNew
#include "unitLogo.h"               //Logo
#include "unitClose.h"              //Close
#include "unitOptions.h"            //Options
#include "unitPrintMessage.h"       //PrintMessage
#include "unitSetPrinter.h"         //SetPrinter
#include "unitSetConfigFolder.h"    //SetConfigFolder
#include "unitSaveMessage.h"        //SaveMessage
#include "unitShowMessageCustom.h"  //ShowMessageCustom

using namespace std;
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
	spinEditReceiptNumber->Value += 1;

	editCard->Text = formSetConfigFolder->mainCard->Text;

	editArticleID->Text = "";
	editQuantity->Text = "0";
    comboBoxMeasureUnit->Text = "";
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

	comboBoxArticleTypes->ItemIndex = -1;
	addUniqueItemToComboBox(comboBoxArticleTypes, "Soja");
	addUniqueItemToComboBox(comboBoxArticleTypes, "Kukuruz");
	addUniqueItemToComboBox(comboBoxArticleTypes, "Žito");
	addUniqueItemToComboBox(comboBoxArticleTypes, "Svinje");

	comboBoxMeasureUnit->ItemIndex = -1;
	addUniqueItemToComboBox(comboBoxMeasureUnit, "kg");
	addUniqueItemToComboBox(comboBoxMeasureUnit, "g");
	comboBoxMeasureUnit->ItemIndex = 0;
	// calling manually update on string grid since comboBoxMeasureUnitChange
	// is not triggered when itemIndex change is done from code
    // MOST LIKELY C++ Builder BUG!!!
	StringGrid1->Cells[3][StringGrid1->Row] = comboBoxMeasureUnit->Text;

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
	AnsiString card = editCard->Text;

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
	AnsiString oib = comboBoxOIBs->Text;
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
	labelNoPdv->Caption = FormatFloat("#########.00", noPdv) + " kn";
	labelNoPdv1->Caption =  FormatFloat("#########.00", noPdv) + " kn";
	labelOnlyPdv->Caption =  FormatFloat("#########.00", noPdv * (pdv / 100)) + " kn";
	labelTotalSum->Caption = FormatFloat("#########.00", noPdv + noPdv * (pdv / 100)) + " kn";

    StringGrid1->Cells[5][StringGrid1->Row] = labelNoPdv->Caption;
}

void __fastcall TformMain::editPdvChange(TObject *Sender)
{
	validate(editPdv, &pdv);
	labelPdvkurco->Caption = editPdv->Text;
	calculate();
}

void __fastcall TformMain::editQuantityChange(TObject *Sender)
{
	StringGrid1->Cells[2][StringGrid1->Row] = editQuantity->Text;
	validate(editQuantity, &quantity);
	calculate();
}

void __fastcall TformMain::editWholesalePriceChange(TObject *Sender)
{
	StringGrid1->Cells[4][StringGrid1->Row] = editWholesalePrice->Text;
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
		Printer()->Canvas->TextOut(3430, 4565, editPdv->Text);
		Printer()->Canvas->TextOut(4075, 4565, labelNoPdv->Caption);
		Printer()->Canvas->TextOut(4075, 5220, labelNoPdv1->Caption);
		Printer()->Canvas->TextOut(4075, 5355, labelOnlyPdv->Caption);
		Printer()->Canvas->TextOut(3770, 5355, labelPdvkurco->Caption);
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
	AnsiString receiptPrintFileName = formOptions->getReceiptFileNameWitouthExt() + ".pdf";

	// convert ansistring to wstring
	string tmpStr = string(receiptPrintFileName.c_str(), receiptPrintFileName.Length());
	wstring tmpWStr = wstring(tmpStr.begin(), tmpStr.end());

	// convert wstring to wchar_t array
	wcscpy(outFileName, tmpWStr.c_str());

	// set print filename
	THandle DeviceMode;
	wchar_t Device[80], Driver[80], Port[80];
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
// RECEIPT LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

AnsiString TformMain::getReceiptFileName(){
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
	comboBoxArticleTypes->ItemIndex = receipt->articleType;
	editQuantity->Text = receipt->quantity;
	comboBoxMeasureUnit->ItemIndex = receipt->measureUnit;
	editWholesalePrice->Text = receipt->wholesalePrice;
	editWholesaleDiscount->Text = receipt->wholesaleDiscount;
	editPdv->Text = receipt->pdv;
}

void TformMain::openReceipt(){
	_di_IXMLreceiptType receipt = Loadreceipt(FileOpenDialog1->FileName);

	spinEditReceiptNumber->Value = receipt->number;
	datePickerServiceDate->Date = receipt->serviceDate;
	datePickerIssueDate->Date = receipt->issueDate;
	timePickerIssueTime->Time = timePickerIssueTime->Time;
	datePickerArrivalDate->Date = receipt->arrivalDate;
	editCard->Text = receipt->card;
	comboBoxOIBs->Text = receipt->OIB;
	editArticleID->Text = receipt->articleID;
	comboBoxArticleTypes->ItemIndex = receipt->articleType;
	editQuantity->Text = receipt->quantity;
	comboBoxMeasureUnit->ItemIndex = receipt->measureUnit;
	editWholesalePrice->Text = receipt->wholesalePrice;
	editWholesaleDiscount->Text = receipt->wholesaleDiscount;
	editPdv->Text = receipt->pdv;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                   update receipt file from receipt fields
void TformMain::saveReceiptToFile(AnsiString fileName)
{
	XMLDocReceipt->SaveToFile(fileName);
}

void TformMain::saveReceipt(){
	DBG_MSG("getReceiptFileName " + getReceiptFileName());
	DBG_MSG("getProgramDataFileName " + formSetConfigFolder->getProgramDataFileName());

	_di_IXMLreceiptType receipt = Getreceipt(XMLDocReceipt);

	receipt->number = spinEditReceiptNumber->Value;
	receipt->serviceDate = datePickerServiceDate->Date;
	receipt->issueDate = datePickerIssueDate->Date;
	receipt->issueTime = timePickerIssueTime->Time;
	receipt->arrivalDate = datePickerArrivalDate->Date;
	receipt->card = editCard->Text;
	receipt->OIB = comboBoxOIBs->Text;
	receipt->articleID = editArticleID->Text;
	receipt->articleType = comboBoxArticleTypes->ItemIndex;
	receipt->quantity = editQuantity->Text.ToDouble();
	receipt->measureUnit = comboBoxMeasureUnit->ItemIndex;
	receipt->wholesalePrice = editWholesalePrice->Text.ToDouble();
	receipt->wholesaleDiscount = editWholesaleDiscount->Text.ToDouble();
	receipt->pdv = editPdv->Text.ToDouble();

	saveReceiptToFile(getReceiptFileName());
	receiptSaved = True;

	addUniqueItemToComboBox(comboBoxOIBs);
	addUniqueItemToComboBox(comboBoxArticleTypes);
	saveFieldsToProgramDataFile();
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

void __fastcall TformMain::buttonPrintClick(TObject *Sender)
{
	if(!validateAll()) return;

	doThePrint();

	saveReceipt();

	formPrintMessage->ShowModal();
}

void __fastcall TformMain::buttonSaveClick(TObject *Sender)
{
	if(!validateAll()) return;

	saveReceipt();

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
	readFieldsFromProgramDataFile();
	makeNew();
}

void __fastcall TformMain::comboBoxArticleTypesChange(TObject *Sender)
{
	StringGrid1->Cells[1][StringGrid1->Row] = comboBoxArticleTypes->Text;
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

void __fastcall TformMain::editArticleIDChange(TObject *Sender)
{
	 StringGrid1->Cells[0][StringGrid1->Row] = editArticleID->Text;
}

void __fastcall TformMain::comboBoxMeasureUnitChange(TObject *Sender)
{
	StringGrid1->Cells[3][StringGrid1->Row] = comboBoxMeasureUnit->Text;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************
