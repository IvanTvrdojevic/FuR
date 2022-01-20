//******************************************************************************
// INCLUDES
//******************************************************************************
#include "unitShowMessageCustom.h"

#include "projectGlobals.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
TXMLBinding_programData programData;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
void showMessageCustom(RADstring message, int fontSize, TColor fontColor){
	formShowMessageCustom->labelCustomMessage->Caption = message;
	formShowMessageCustom->labelCustomMessage->Font->Size = fontSize;
	formShowMessageCustom->labelCustomMessage->Font->Color = fontColor;

	formShowMessageCustom->ShowModal();
}

void showMessageCustom(int message, int fontSize, TColor fontColor){
	showMessageCustom(IntToStr(message), fontSize, fontColor);
}

void setupFormVisuals(TForm* form)
{
	form->AutoSize = True;
	form->BorderIcons = {};
	form->BorderStyle = bsSingle;
	form->Caption = "";
	form->Color = clSilver;
	form->Padding->Bottom = DEFAULT_MARGIN;
	form->Padding->Left = DEFAULT_MARGIN;
	form->Padding->Right = DEFAULT_MARGIN;
	form->Padding->Top = DEFAULT_MARGIN;
	form->Position = poScreenCenter;
}
//******************************************************************************
