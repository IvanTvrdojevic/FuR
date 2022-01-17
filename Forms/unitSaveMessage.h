#ifndef unitSaveMessageH
#define unitSaveMessageH
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
class TformSaveMessage : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelPrintMessage;
	TLabel *labelFolder;
	TButton *buttonOkay;
	TLabel *labelPrintMessage2;
	TLabel *Label1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall buttonOkayClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformSaveMessage(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformSaveMessage *formSaveMessage;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
