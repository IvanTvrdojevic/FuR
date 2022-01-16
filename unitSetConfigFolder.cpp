//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <System.IOUtils.hpp>

#include "common.h"

#include "unitLogo.h"
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
	TDirectory::CreateDirectory(programDataPath);

	// call this so all fields are set to default values
	readFieldsFromProgramDataFile();

	formOptions->editReceiptFilePath->Text = programDataPath;
    saveFieldsToProgramDataFile();

	formLogo->fadeTimer->Enabled = true;

	Close();
}

void __fastcall TformSetConfigFolder::FormCreate(TObject *Sender)
{
	reg = new TRegistry(KEY_READ);
	reg->RootKey = HKEY_CURRENT_USER;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************
