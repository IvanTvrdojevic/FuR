//******************************************************************************
// INCLUDES
//******************************************************************************
#include "generalXMLDataBindings.h"

#include "projectGlobals.h"

#include "unitMain.h"
#include "unitOptions.h"
#include "unitAdditionalOptions.h"

#include "programDataBindings.h"
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
TXMLBinding_programData::TXMLBinding_programData(){
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// UPDATING LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//------------------------------------------------------------------------------
//                   set GUI fields from data
void TXMLBinding_programData::setFieldOf_printerName(){
   setTextFieldFromData(formOptions->comboBoxPrinters, programData->printerName);
}

void TXMLBinding_programData::setFieldOf_receiptFilePath(){
   setTextFieldFromData(formOptions->editReceiptFilePath, programData->receiptFilePath);
}

void TXMLBinding_programData::setFieldOf_receiptFileName(){
   setTextFieldFromData(formOptions->editReceiptFileName, programData->receiptFileName, RECEIPT_NAME);
}

void TXMLBinding_programData::setFieldOf_receiptDateSufix(){
   setCheckBoxFieldFromData(formOptions->checkBoxReceiptDateSufix, programData->receiptDateSufix, RECEIPT_SUFFIX_ENABLE);
}

void TXMLBinding_programData::setFieldOf_receiptNumberSufix(){
   setCheckBoxFieldFromData(formOptions->checkBoxReceiptNumberSufix, programData->receiptNumberSufix, RECEIPT_SUFFIX_ENABLE);
}

void TXMLBinding_programData::setFieldOf_receiptNumber(){
   setValueFieldFromData(formMain->spinEditReceiptNumber, programData->receiptNumber, RECEIPT_START_NUMBER);
}

void TXMLBinding_programData::setFieldOf_messageFontSize(){
   setValueFieldFromData(formAdditionalOptions->spinEditMessageFontSize, programData->messageFontSize, DEFAULT_MESSAGE_FONT_SIZE);
}

void TXMLBinding_programData::setFieldOf_messageFontColor(){
   setColorPickerFieldFromData(formAdditionalOptions->colorListBoxMessageFontColor, programData->messageFontColor, DEFAULT_MESSAGE_FONT_COLOR);
}

void TXMLBinding_programData::setFieldOf_OIBs(){
   setItemsListFieldFromData(formMain->comboBoxOIBs, programData->OIBs);
}

void TXMLBinding_programData::setFieldOf_articleTypes(){
   setItemsListFieldFromData(formMain->comboBoxArticleTypes, programData->articleTypes);
}

void TXMLBinding_programData::setAllFieldsOf_programData(){
	setFieldOf_printerName();
	setFieldOf_receiptFilePath();
	setFieldOf_receiptFileName();
	setFieldOf_receiptDateSufix();
	setFieldOf_receiptNumberSufix();
	setFieldOf_receiptNumber();
	setFieldOf_messageFontSize();
	setFieldOf_messageFontColor();
	setFieldOf_OIBs();
	setFieldOf_articleTypes();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                   update programData from GUI fields
void TXMLBinding_programData::update_printerName(){
	programData->printerName = getDataFromTextField(formOptions->comboBoxPrinters);
}

void TXMLBinding_programData::update_receiptFilePath(){
	programData->receiptFilePath = getDataFromTextField(formOptions->editReceiptFilePath);
}

void TXMLBinding_programData::update_receiptFileName(){
    programData->receiptFileName = getDataFromTextField(formOptions->editReceiptFileName, RECEIPT_NAME);
}

void TXMLBinding_programData::update_receiptDateSufix(){
    programData->receiptDateSufix = getDataFromCheckBoxField(formOptions->checkBoxReceiptDateSufix, RECEIPT_SUFFIX_ENABLE);
}

void TXMLBinding_programData::update_receiptNumberSufix(){
	programData->receiptNumberSufix = getDataFromCheckBoxField(formOptions->checkBoxReceiptNumberSufix, RECEIPT_SUFFIX_ENABLE);
}

void TXMLBinding_programData::update_receiptNumber(){
	programData->receiptNumber = getDataFromValueField(formMain->spinEditReceiptNumber, RECEIPT_START_NUMBER);
}

void TXMLBinding_programData::update_messageFontSize(){
	programData->messageFontSize = getDataFromValueField(formAdditionalOptions->spinEditMessageFontSize, DEFAULT_MESSAGE_FONT_SIZE);

}

void TXMLBinding_programData::update_messageFontColor(){
	programData->messageFontColor = getDataFromColorPickerField(formAdditionalOptions->colorListBoxMessageFontColor, DEFAULT_MESSAGE_FONT_COLOR);
}

void TXMLBinding_programData::update_OIBs(){
	getDataFromItemsListField(programData->OIBs, formMain->comboBoxOIBs);
}

void TXMLBinding_programData::update_articleTypes(){
   getDataFromItemsListField(programData->articleTypes, formMain->comboBoxArticleTypes);
}

void TXMLBinding_programData::updateAll_programData(){
	update_printerName();
	update_receiptFilePath();
	update_receiptFileName();
	update_receiptDateSufix();
	update_receiptNumberSufix();
	update_receiptNumber();
	update_messageFontSize();
	update_messageFontColor();
	update_OIBs();
	update_articleTypes();
}
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															      UPDATING LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// OPEN/SAVE LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool TXMLBinding_programData::openFromFile(String fileName)
{
	CoInitializeEx(NULL, 0);
	XMLDocument = interface_cast<Xmlintf::IXMLDocument>(new TXMLDocument(NULL));
	XMLDocument->Active = true;

	try{
		if(FileExists(fileName))
			XMLDocument->LoadFromFile(fileName);
	}
	catch(...){
		return false;
	}

	this->programData = GetprogramData(XMLDocument);
	setAllFieldsOf_programData();

	return true;
}

void TXMLBinding_programData::saveToFile(String fileName)
{
	String xmlStr;
	XMLDocument->SaveToXML(xmlStr);
	xmlStr = FormatXMLData(xmlStr);

	TStringList *list = new TStringList;
	list->Add(xmlStr);
	list->SaveToFile(fileName, TEncoding::UTF8);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															     OPEN/SAVE LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************


