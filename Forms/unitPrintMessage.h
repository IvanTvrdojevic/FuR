#ifndef unitPrintMessageH
#define unitPrintMessageH
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
class TformPrintMessage : public TForm
{
__published:	// IDE-managed Components
	TLabel *labelPrintMessage;
	TButton *Button1;
	TLabel *Label1;
	TLabel *labelPrintMessage1;
	TLabel *labelPrintMessage2;
	TButton *Button2;
	TButton *buttonMore;
	TLabel *labelFolder;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall buttonMoreClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformPrintMessage(TComponent* Owner);
	void showOrHide(TLabel* label, TButton* button);
    void changeVisibility(TLabel* label, TButton* button);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformPrintMessage *formPrintMessage;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
