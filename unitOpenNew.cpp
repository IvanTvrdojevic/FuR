//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "unitMain.h"
#include "unitOpenNew.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformOpenNew *formOpenNew;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformOpenNew::TformOpenNew(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TformOpenNew::Button1Click(TObject *Sender)
{
	formMain->makeNew();

	Close();
}

void __fastcall TformOpenNew::Button2Click(TObject *Sender)
{
	Close();
}

void __fastcall TformOpenNew::FormShow(TObject *Sender)
{
	if(!formMain->receiptSaved){
		labelSaveWarning->Font->Color = clRed;
		labelSaveWarning->Caption = "Račun nije spremljen, ako sad otvorite novi promjene će biti izgubljene!";
	}
	else{
		labelSaveWarning->Font->Color = clGreen;
		labelSaveWarning->Caption = "Trenutni račun je spremljen!";
	}
}
//******************************************************************************


