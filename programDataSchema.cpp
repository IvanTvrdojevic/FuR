
// *********************************************************************************** //
//                                                                                   
//                                 XML Data Binding                                  
//                                                                                   
//         Generated on: 1/11/2022 10:05:40 PM                                       
//       Generated from: E:\00_WORK\99_RAD\00_CPP\00_FUR\Res\programDataSchema.xml   
//   Settings stored in: E:\00_WORK\99_RAD\00_CPP\00_FUR\Res\programDataSchema.xdb   
//                                                                                   
// *********************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "programDataSchema.h"


// Global Functions 

_di_IXMLprogramDataType __fastcall GetprogramData(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLprogramDataType) Doc->GetDocBinding("programData", __classid(TXMLprogramDataType), TargetNamespace);
};

_di_IXMLprogramDataType __fastcall GetprogramData(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetprogramData(DocIntf);
};

_di_IXMLprogramDataType __fastcall LoadprogramData(const System::UnicodeString& FileName)
{
  return (_di_IXMLprogramDataType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("programData", __classid(TXMLprogramDataType), TargetNamespace);
};

_di_IXMLprogramDataType __fastcall  NewprogramData()
{
  return (_di_IXMLprogramDataType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("programData", __classid(TXMLprogramDataType), TargetNamespace);
};

// TXMLprogramDataType 

void __fastcall TXMLprogramDataType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("OIBs"), __classid(TXMLOIBsType));
  RegisterChildNode(System::UnicodeString("articleTypes"), __classid(TXMLarticleTypesType));
  Xml::Xmldoc::TXMLNode::AfterConstruction();
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_printerName()
{
  return GetChildNodes()->Nodes[System::UnicodeString("printerName")]->Text;
};

void __fastcall TXMLprogramDataType::Set_printerName(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("printerName")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_receiptFilePath()
{
  return GetChildNodes()->Nodes[System::UnicodeString("receiptFilePath")]->Text;
};

void __fastcall TXMLprogramDataType::Set_receiptFilePath(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("receiptFilePath")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_receiptFileName()
{
  return GetChildNodes()->Nodes[System::UnicodeString("receiptFileName")]->Text;
};

void __fastcall TXMLprogramDataType::Set_receiptFileName(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("receiptFileName")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_receiptDateSufix()
{
  return GetChildNodes()->Nodes[System::UnicodeString("receiptDateSufix")]->Text;
};

void __fastcall TXMLprogramDataType::Set_receiptDateSufix(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("receiptDateSufix")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_receiptNumberSufix()
{
  return GetChildNodes()->Nodes[System::UnicodeString("receiptNumberSufix")]->Text;
};

void __fastcall TXMLprogramDataType::Set_receiptNumberSufix(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("receiptNumberSufix")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_receiptNumber()
{
  return GetChildNodes()->Nodes[System::UnicodeString("receiptNumber")]->Text;
};

void __fastcall TXMLprogramDataType::Set_receiptNumber(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("receiptNumber")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_messageFontSize()
{
  return GetChildNodes()->Nodes[System::UnicodeString("messageFontSize")]->Text;
};

void __fastcall TXMLprogramDataType::Set_messageFontSize(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("messageFontSize")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLprogramDataType::Get_messageFontColor()
{
  return GetChildNodes()->Nodes[System::UnicodeString("messageFontColor")]->Text;
};

void __fastcall TXMLprogramDataType::Set_messageFontColor(System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("messageFontColor")]->NodeValue = Value;
};

_di_IXMLOIBsType __fastcall TXMLprogramDataType::Get_OIBs()
{
  return (_di_IXMLOIBsType) GetChildNodes()->Nodes[System::UnicodeString("OIBs")];
};

_di_IXMLarticleTypesType __fastcall TXMLprogramDataType::Get_articleTypes()
{
  return (_di_IXMLarticleTypesType) GetChildNodes()->Nodes[System::UnicodeString("articleTypes")];
};

// TXMLOIBsType 

void __fastcall TXMLOIBsType::AfterConstruction(void)
{
  ItemTag = "OIB";
  ItemInterface = __uuidof(Xml::Xmlintf::IXMLNode);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

System::UnicodeString __fastcall TXMLOIBsType::Get_OIB(int Index)
{
  return List->Nodes[Index]->Text;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLOIBsType::Add(const System::UnicodeString OIB)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(-1);
  item->NodeValue = OIB;
  return item;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLOIBsType::Insert(const int Index, const System::UnicodeString OIB)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(Index);
  item->NodeValue = OIB;
  return item;
};

// TXMLarticleTypesType 

void __fastcall TXMLarticleTypesType::AfterConstruction(void)
{
  ItemTag = "articleType";
  ItemInterface = __uuidof(Xml::Xmlintf::IXMLNode);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

System::UnicodeString __fastcall TXMLarticleTypesType::Get_articleType(int Index)
{
  return List->Nodes[Index]->Text;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLarticleTypesType::Add(const System::UnicodeString articleType)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(-1);
  item->NodeValue = articleType;
  return item;
};

Xml::Xmlintf::_di_IXMLNode __fastcall TXMLarticleTypesType::Insert(const int Index, const System::UnicodeString articleType)
{
  Xml::Xmlintf::_di_IXMLNode item = AddItem(Index);
  item->NodeValue = articleType;
  return item;
};
