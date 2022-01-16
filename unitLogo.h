#ifndef unitLogoH
#define unitLogoH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//******************************************************************************


//******************************************************************************
// CLASSES
//******************************************************************************
class TformLogo : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TTimer *fadeTimer;
	void __fastcall fadeTimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TformLogo(TComponent* Owner);
};
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern PACKAGE TformLogo *formLogo;
//******************************************************************************

//------------------------------------------------------------------------------
#endif
