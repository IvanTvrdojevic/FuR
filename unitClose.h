#ifndef unitCloseH
#define unitCloseH
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
class TformClose : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelWarning;
	TButton *Button1;
	TButton *Button2;
	TLabel *labelSaveWarning;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformClose(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformClose *formClose;
//******************************************************************************
#endif
