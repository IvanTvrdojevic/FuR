//******************************************************************************
// INCLUDES
//******************************************************************************
#include "unitSetConfigFolder.h"

#include "common.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
TXMLBinding_programData* programData;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
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

void readFieldsFromProgramDataFile(){
	programData->setFileName(formSetConfigFolder->getProgramDataFileName());
	programData->readFromFile();
}

void saveFieldsToProgramDataFile()
{
	programData->setFileName(formSetConfigFolder->getProgramDataFileName());
	programData->saveToFile();
}
//******************************************************************************

