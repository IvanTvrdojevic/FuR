//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "projectGlobals.h"

#include "unitMain.h"
#include "unitSetConfigFolder.h"

#include "unitClose.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformClose *formClose;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformClose::TformClose(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TformClose::Button1Click(TObject *Sender)
{
	programData.saveToFile(formSetConfigFolder->getProgramDataFileName());
	Application->Terminate();
}

void __fastcall TformClose::Button2Click(TObject *Sender)
{
	formClose->Close();
}

void __fastcall TformClose::FormShow(TObject *Sender)
{
	if(!formMain->receiptSaved){
		labelSaveWarning->Font->Color = clRed;
		labelSaveWarning->Caption = "Račun nije spremljen, ako sad zatvorite program promjene će biti izgubljene!";
	}
	else{
		labelSaveWarning->Font->Color = clGreen;
		labelSaveWarning->Caption = "Trenutni račun je spremljen!";
	}
}
//******************************************************************************


