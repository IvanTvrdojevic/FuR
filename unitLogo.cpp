
//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "common.h"

#include "unitMain.h"
#include "unitOpenNew.h"
#include "unitLogo.h"
#include "unitClose.h"
#include "unitOptions.h"
#include "unitPrintMessage.h"
#include "unitSetPrinter.h"
#include "unitSetConfigFolder.h"
#include "unitSaveMessage.h"
#include "unitAdditionalOptions.h"
#include "unitShowMessageCustom.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformLogo *formLogo;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformLogo::TformLogo(TComponent* Owner)
	: TForm(Owner)
{
}

bool checkFirstRun()
{
	if(!(formSetConfigFolder->reg->KeyExists(REGISTRY_KEY)))
		return true;

	formSetConfigFolder->readProgramDataPath();
	if(!DirectoryExists(formSetConfigFolder->programDataPath))
		return true;

	return false;
}

void __fastcall TformLogo::fadeTimerTimer(TObject *Sender)
{
	formLogo->AlphaBlendValue -= 3;
	if(formLogo->AlphaBlendValue < 5){
		formLogo->Visible = false;
		fadeTimer->Enabled = false;

        formMain->Show();
	}
}

void __fastcall TformLogo::FormShow(TObject *Sender)
{
	setupFormVisuals(formMain);
	setupFormVisuals(formSetPrinter);
	setupFormVisuals(formSetConfigFolder);
	setupFormVisuals(formSaveMessage);
	setupFormVisuals(formPrintMessage);
	setupFormVisuals(formOptions);
	setupFormVisuals(formOpenNew);
	setupFormVisuals(formClose);
	setupFormVisuals(formAdditionalOptions);
	setupFormVisuals(formShowMessageCustom);

	formMain->Caption = "FRUTZOV UBER RACUN";
	formMain->Color =  clBtnFace;

	programData = new TXMLBinding_programData(formMain->XMLDocProgramData);

	if(checkFirstRun())
	{
		formSetConfigFolder->ShowModal();
		return;
	}

	fadeTimer->Enabled = true;
}
//******************************************************************************

