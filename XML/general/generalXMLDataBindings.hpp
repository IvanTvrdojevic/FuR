//******************************************************************************
// METHODS
//******************************************************************************

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// UPDATING LOGIC
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//------------------------------------------------------------------------------
//                   update GUI field from data
template <typename T_FIELD>
void setCheckBoxFieldFromData(T_FIELD* field, String const& data, bool const& defaultValue){
	if(field == NULL) return;

	field->Checked = data == "" ? defaultValue : StrToBool(data);
}

template <typename T_FIELD>
void setValueFieldFromData(T_FIELD* field, String const& data, int const& defaultValue){
	if(field == NULL) return;

	field->Value = data == "" ? defaultValue : StrToInt(data);
}

template <typename T_FIELD>
void setTextFieldFromData(T_FIELD* field, String const& data, String const& defaultValue){
	if(field == NULL) return;

	field->Text = data == "" ? defaultValue : data;
}

template <typename T_FIELD>
void setCaptionFieldFromData(T_FIELD* field, String const& data, String const& defaultValue){
	if(field == NULL) return;

	field->Caption = data == "" ? defaultValue : data;
}

template <typename T_FIELD>
void setColorPickerFieldFromData(T_FIELD* field, String const& data, TColor const& defaultValue){
	if(field == NULL) return;

	field->Selected = data == "" ? defaultValue : StringToColor(data);
}

template <typename T_FIELD, typename T_ELEMENT>
void setItemsListFieldFromData(T_FIELD* field, T_ELEMENT const& element){
	if(field == NULL) return;
	if(element == NULL) return;

	field->Items->Clear();

	for(int i = 0; i < element->Count; i++)
		field->Items->Add(element->Nodes[i]->Text);

	field->ItemIndex = -1;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                   update data from GUI field
template <typename T_FIELD>
String getDataFromCheckBoxField(T_FIELD* field, bool const& defaultValue){
	if(field == NULL) return BoolToStr(defaultValue, true);

	return BoolToStr(field->Checked, true);
}

template <typename T_FIELD>
String getDataFromValueField(T_FIELD* field, int const& defaultValue){
	if(field == NULL) return IntToStr(defaultValue);

	return IntToStr(field->Value);
}

template <typename T_FIELD>
String getDataFromTextField(T_FIELD* field, String const& defaultValue){
	if(field == NULL) return defaultValue;

	return field->Text;
}

template <typename T_FIELD>
String getDataFromCaptionField(T_FIELD* field, String const& defaultValue){
	if(field == NULL) return defaultValue;

	return field->Caption;
}

template <typename T_FIELD>
String getDataFromColorPickerField(T_FIELD* field, TColor const& defaultValue){
	if(field == NULL) return ColorToString(defaultValue);

	return ColorToString(field->Selected);
}

template <typename T_ELEMENT, typename T_FIELD>
void getDataFromItemsListField(T_ELEMENT element, T_FIELD* field){
	if(field == NULL) return;
	if(element == NULL) return;

	element->Clear();

	for(int i = 0; i < field->Items->Count; i++)
		element->Add(field->Items->Strings[i]);

	return;
}
//------------------------------------------------------------------------------

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															      UPDATING LOGIC
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************





