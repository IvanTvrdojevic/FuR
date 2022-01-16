
#ifndef unitShowMessageCustomH
#define unitShowMessageCustomH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Spin.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformShowMessageCustom : public TForm
{
__published:	// IDE-managed Components
	TButton *buttonOkay;
	TLabel *labelCustomMessage;
	TLabel *Label1;
	void __fastcall buttonOkayClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformShowMessageCustom(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformShowMessageCustom *formShowMessageCustom;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
