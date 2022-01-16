#ifndef unitSetPrinterH
#define unitSetPrinterH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformSetPrinter : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label3;
	TComboBox *comboBoxPrinters;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall comboBoxPrintersChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformSetPrinter(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformSetPrinter *formSetPrinter;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
