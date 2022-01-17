#ifndef unitOpenNewH
#define unitOpenNewH
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
class TformOpenNew : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TLabel *labelSaveWarning;
	TLabel *labelWarning;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	bool option;
	__fastcall TformOpenNew(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformOpenNew *formOpenNew;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
