//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "projectGlobals.h"

#include "unitMain.h"
#include "unitAdditionalOptions.h"
#include "unitSetConfigFolder.h"

#include "unitOptions.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformOptions *formOptions;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformOptions::TformOptions(TComponent* Owner)
	: TForm(Owner)
{
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// UPDATING LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void TformOptions::updateReceiptFileNameWitouthExt(){
	labelReceiptFileName->Caption = editReceiptFileName->Text;

	if(checkBoxReceiptDateSufix->Checked){
		labelReceiptFileName->Caption = labelReceiptFileName->Caption + "_" + formMain->datePickerIssueDate->Date.FormatString(L"yyyy-mm-dd");
	}

	if(checkBoxReceiptNumberSufix->Checked){
		labelReceiptFileName->Caption = labelReceiptFileName->Caption + "_" + formMain->spinEditReceiptNumber->Value;
	}
}

AnsiString TformOptions::getReceiptFileNameWitouthExt(){
	updateReceiptFileNameWitouthExt();
	return editReceiptFilePath->Text + "\\" + labelReceiptFileName->Caption;
}

void TformOptions::updateDependentFormFields(){
	comboBoxPrinters->Items = Printer()->Printers;
	comboBoxPrinters->ItemIndex = -1;
	for (int i = 0; i < Printer()->Printers->Count - 1; i++){
		if(comboBoxPrinters->Text == comboBoxPrinters->Items->Strings[i]){
			comboBoxPrinters->ItemIndex = i;
			break;
		}
	}

	labelReceiptFilePath->Caption = editReceiptFilePath->Text;
	updateReceiptFileNameWitouthExt();

    labelProgramDataFilePath->Caption = formSetConfigFolder->getProgramDataFileName();
}

void TformOptions::resetFormProgramDataFields(){
	programData.setFieldOf_printerName();
	programData.setFieldOf_receiptFilePath();
	programData.setFieldOf_receiptFileName();
	programData.setFieldOf_receiptDateSufix();
	programData.setFieldOf_receiptNumberSufix();
}

void TformOptions::saveFormProgramDataFields(){
	programData.update_printerName();
	programData.update_receiptFilePath();
	programData.update_receiptFileName();
	programData.update_receiptDateSufix();
	programData.update_receiptNumberSufix();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															      UPDATING LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// FORM CONTROLS EVENTS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void __fastcall TformOptions::FormShow(TObject *Sender)
{
	updateDependentFormFields();
}

void __fastcall TformOptions::btnSetReceiptFolderClick(TObject *Sender)
{
	FileOpenDialog1->DefaultFolder = editReceiptFilePath->Text;
	if(!FileOpenDialog1->Execute()) return;

	editReceiptFilePath->Text = FileOpenDialog1->FileName;
	labelReceiptFilePath->Caption = editReceiptFilePath->Text;
}

void __fastcall TformOptions::editReceiptFileNameChange(TObject *Sender)
{
	updateReceiptFileNameWitouthExt();
}

void __fastcall TformOptions::checkBoxReceiptNumberSufixClick(TObject *Sender)
{
	updateReceiptFileNameWitouthExt();
}

void __fastcall TformOptions::btnAdditionalOptionsClick(TObject *Sender)
{
	formAdditionalOptions->ShowModal();
}

void __fastcall TformOptions::btnSaveClick(TObject *Sender)
{
	saveFormProgramDataFields();

	Close();
}

void __fastcall TformOptions::btnCancelClick(TObject *Sender)
{
	resetFormProgramDataFields();

	Close();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************

