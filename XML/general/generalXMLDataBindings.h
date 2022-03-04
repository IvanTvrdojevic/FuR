#ifndef generalXMLDataBindingsH
#define generalXMLDataBindingsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hrdstop
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// UPDATING LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//------------------------------------------------------------------------------
//                   update GUI field from data
template <typename T_FIELD>
void setCheckBoxFieldFromData(T_FIELD* field, String const& data, bool const& defaultValue = false);

template <typename T_FIELD>
void setValueFieldFromData(T_FIELD* field, String const& data, int const& defaultValue = 0);

template <typename T_FIELD>
void setTextFieldFromData(T_FIELD* field, String const& data, String const& defaultValue = "");

template <typename T_FIELD>
void setCaptionFieldFromData(T_FIELD* field, String const& data, String const& defaultValue = "");

template <typename T_FIELD>
void setColorPickerFieldFromData(T_FIELD* field, String const& data, TColor const& defaultValue = clBlack);

template <typename T_FIELD, typename T_ELEMENT>
void setItemsListFieldFromData(T_FIELD* field, T_ELEMENT const& element);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                   update data from GUI field
template <typename T_FIELD>
String getDataFromCheckBoxField(T_FIELD* field, bool const& defaultValue = false);

template <typename T_FIELD>
String getDataFromValueField(T_FIELD* field, int const& defaultValue = 0);

template <typename T_FIELD>
String getDataFromTextField(T_FIELD* field, String const& defaultValue = "");

template <typename T_FIELD>
String getDataFromCaptionField(T_FIELD* field, String const& defaultValue = "");

template <typename T_FIELD>
String getDataFromColorPickerField(T_FIELD* field, TColor const& defaultValue = clBlack);

template <typename T_ELEMENT, typename T_FIELD>
void getDataFromItemsListField(T_ELEMENT element, T_FIELD* field);
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															      UPDATING LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************


//******************************************************************************
// HPP IMPLEMENTATIONS FILES
//******************************************************************************
#include "generalXMLDataBindings.hpp"
//******************************************************************************

//------------------------------------------------------------------------------
#endif

