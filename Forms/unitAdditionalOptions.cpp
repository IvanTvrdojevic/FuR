//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "programDataBindings.h"
#include "common.h"

#include "unitMain.h"
#include "unitAdditionalOptions.h"
#include "unitSetConfigFolder.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformAdditionalOptions *formAdditionalOptions;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformAdditionalOptions::TformAdditionalOptions(TComponent* Owner)
	: TForm(Owner)
{
}

void TformAdditionalOptions::resetFormProgramDataFields(){
	programData.setFieldOf_messageFontSize();
	programData.setFieldOf_messageFontColor();
}

void TformAdditionalOptions::saveFormProgramDataFields(){
	programData.update_messageFontSize();
	programData.update_messageFontColor();
}

void __fastcall TformAdditionalOptions::btnSaveClick(TObject *Sender)
{
	saveFormProgramDataFields();

	Close();
}

void __fastcall TformAdditionalOptions::btnCancelClick(TObject *Sender)
{
	resetFormProgramDataFields();

	Close();
}//******************************************************************************

