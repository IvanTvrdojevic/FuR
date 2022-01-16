//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include "common.h"

#include "unitMain.h"
#include "unitOptions.h"
#include "unitSetPrinter.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformSetPrinter *formSetPrinter;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformSetPrinter::TformSetPrinter(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TformSetPrinter::FormShow(TObject *Sender)
{
	comboBoxPrinters->Items = Printer()->Printers;
}

void __fastcall TformSetPrinter::Button1Click(TObject *Sender)
{
	programData.update_printerName();
	formMain->doThePrint();

	Close();
}

void __fastcall TformSetPrinter::comboBoxPrintersChange(TObject *Sender)
{
	formOptions->comboBoxPrinters->Text = comboBoxPrinters->Text;
}
//******************************************************************************



