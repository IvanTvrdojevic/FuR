//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>

#include "common.h"
#include "utils.h"

#include "unitLogo.h"
#include "unitMain.h"
#include "unitOptions.h"
#include "unitSetConfigFolder.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformSetConfigFolder *formSetConfigFolder;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformSetConfigFolder::TformSetConfigFolder(TComponent* Owner)
	: TForm(Owner)
{
}

void TformSetConfigFolder::readProgramDataPath(){
	reg->Access = KEY_READ;
	reg->OpenKey(REGISTRY_KEY, true);
	programDataPath = reg->ReadString(REGISTRY_SUBKEY_PROGRAM_DATA_NAME) + "\\" + PROGRAM_FOLDER;
	reg->CloseKey();
}

AnsiString TformSetConfigFolder::getProgramDataFileName(){
    readProgramDataPath();
	return programDataPath + "\\" + PROGRAM_DATA_FILENAME;
}

void TformSetConfigFolder::setupInitialFields(){
	// Setup initial fields - list boxes like TComboBox that cant be initialized via simple
	// default value (ie for complex data types)
	addUniqueItemToComboBox(formMain->comboBoxArticleTypes, "Soja");
	addUniqueItemToComboBox(formMain->comboBoxArticleTypes, "Kukuruz");
	addUniqueItemToComboBox(formMain->comboBoxArticleTypes, "Žito");
	addUniqueItemToComboBox(formMain->comboBoxArticleTypes, "Svinje");
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// FORM CONTROLS EVENTS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void __fastcall TformSetConfigFolder::Button3Click(TObject *Sender)
{
	if(!FileOpenDialog1->Execute()) return;

	editFolder->Text = FileOpenDialog1->FileName;
	buttonOkay->Enabled = true;
}

void __fastcall TformSetConfigFolder::buttonOkayClick(TObject *Sender)
{
	reg->Access = KEY_WRITE;
	reg->OpenKey(REGISTRY_KEY, true);
	reg->WriteString(REGISTRY_SUBKEY_PROGRAM_DATA_NAME, editFolder->Text);
	reg->CloseKey();

	readProgramDataPath();

	try{
		TDirectory::CreateDirectory(programDataPath);
		programData.openFromFile(getProgramDataFileName());
	}
	catch(...){
		showMessageCustom("Nije moguce kreirati konfiguracijsku datoteku! Odaberite drugi direktorij!");
		return;
	}

	formOptions->editReceiptFilePath->Text = programDataPath;

	// init complex fields like comboboxes etc
	setupInitialFields();

	// when program is first starting or restarting due to deleted reg key or program data dir
    // in that case, update all program data XML fields -> this will result in init to default values
	programData.updateAll_programData();

	Close();
}

void __fastcall TformSetConfigFolder::FormCreate(TObject *Sender)
{
	reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;
}

void __fastcall TformSetConfigFolder::FormClose(TObject *Sender, TCloseAction &Action)

{
	formLogo->fadeTimer->Enabled = true;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************

