
// *********************************************************************************************** //
//                                                                                               
//                                       XML Data Binding                                        
//                                                                                               
//         Generated on: 1/20/2022 9:48:38 PM                                                    
//       Generated from: E:\00_WORK\99_RAD\00_CPP\00_FUR\XML\programData\programDataSchema.xml   
//   Settings stored in: E:\00_WORK\99_RAD\00_CPP\00_FUR\XML\programData\programDataSchema.xdb   
//                                                                                               
// *********************************************************************************************** //

#ifndef   programDataSchemaH
#define   programDataSchemaH

#include <System.hpp>
#include <System.Variants.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLprogramDataType;
typedef System::DelphiInterface<IXMLprogramDataType> _di_IXMLprogramDataType;
__interface IXMLOIBsType;
typedef System::DelphiInterface<IXMLOIBsType> _di_IXMLOIBsType;
__interface IXMLarticleTypesType;
typedef System::DelphiInterface<IXMLarticleTypesType> _di_IXMLarticleTypesType;

// IXMLprogramDataType 

__interface INTERFACE_UUID("{971A3D06-8EB7-44EB-95E5-232E8E71F8AF}") IXMLprogramDataType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_printerName() = 0;
  virtual System::UnicodeString __fastcall Get_receiptFilePath() = 0;
  virtual System::UnicodeString __fastcall Get_receiptFileName() = 0;
  virtual System::UnicodeString __fastcall Get_receiptDateSufix() = 0;
  virtual System::UnicodeString __fastcall Get_receiptNumberSufix() = 0;
  virtual System::UnicodeString __fastcall Get_receiptNumber() = 0;
  virtual System::UnicodeString __fastcall Get_messageFontSize() = 0;
  virtual System::UnicodeString __fastcall Get_messageFontColor() = 0;
  virtual _di_IXMLOIBsType __fastcall Get_OIBs() = 0;
  virtual _di_IXMLarticleTypesType __fastcall Get_articleTypes() = 0;
  virtual void __fastcall Set_printerName(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_receiptFilePath(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_receiptFileName(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_receiptDateSufix(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_receiptNumberSufix(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_receiptNumber(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_messageFontSize(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_messageFontColor(System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString printerName = { read=Get_printerName, write=Set_printerName };
  __property System::UnicodeString receiptFilePath = { read=Get_receiptFilePath, write=Set_receiptFilePath };
  __property System::UnicodeString receiptFileName = { read=Get_receiptFileName, write=Set_receiptFileName };
  __property System::UnicodeString receiptDateSufix = { read=Get_receiptDateSufix, write=Set_receiptDateSufix };
  __property System::UnicodeString receiptNumberSufix = { read=Get_receiptNumberSufix, write=Set_receiptNumberSufix };
  __property System::UnicodeString receiptNumber = { read=Get_receiptNumber, write=Set_receiptNumber };
  __property System::UnicodeString messageFontSize = { read=Get_messageFontSize, write=Set_messageFontSize };
  __property System::UnicodeString messageFontColor = { read=Get_messageFontColor, write=Set_messageFontColor };
  __property _di_IXMLOIBsType OIBs = { read=Get_OIBs };
  __property _di_IXMLarticleTypesType articleTypes = { read=Get_articleTypes };
};

// IXMLOIBsType 

__interface INTERFACE_UUID("{51BE9A13-62B1-4AEF-98AE-FFFF79997B32}") IXMLOIBsType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_OIB(int Index) = 0;
  // Methods & Properties 
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString OIB) = 0;
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString OIB) = 0;
  __property System::UnicodeString OIB[int Index] = { read=Get_OIB };/* default */
};

// IXMLarticleTypesType 

__interface INTERFACE_UUID("{531AD3E3-FEA5-4ED6-A366-5D1DE07DC623}") IXMLarticleTypesType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_articleType(int Index) = 0;
  // Methods & Properties 
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString articleType) = 0;
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString articleType) = 0;
  __property System::UnicodeString articleType[int Index] = { read=Get_articleType };/* default */
};

// Forward Decls 

class TXMLprogramDataType;
class TXMLOIBsType;
class TXMLarticleTypesType;

// TXMLprogramDataType 

class TXMLprogramDataType : public Xml::Xmldoc::TXMLNode, public IXMLprogramDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLprogramDataType 
  virtual System::UnicodeString __fastcall Get_printerName();
  virtual System::UnicodeString __fastcall Get_receiptFilePath();
  virtual System::UnicodeString __fastcall Get_receiptFileName();
  virtual System::UnicodeString __fastcall Get_receiptDateSufix();
  virtual System::UnicodeString __fastcall Get_receiptNumberSufix();
  virtual System::UnicodeString __fastcall Get_receiptNumber();
  virtual System::UnicodeString __fastcall Get_messageFontSize();
  virtual System::UnicodeString __fastcall Get_messageFontColor();
  virtual _di_IXMLOIBsType __fastcall Get_OIBs();
  virtual _di_IXMLarticleTypesType __fastcall Get_articleTypes();
  virtual void __fastcall Set_printerName(System::UnicodeString Value);
  virtual void __fastcall Set_receiptFilePath(System::UnicodeString Value);
  virtual void __fastcall Set_receiptFileName(System::UnicodeString Value);
  virtual void __fastcall Set_receiptDateSufix(System::UnicodeString Value);
  virtual void __fastcall Set_receiptNumberSufix(System::UnicodeString Value);
  virtual void __fastcall Set_receiptNumber(System::UnicodeString Value);
  virtual void __fastcall Set_messageFontSize(System::UnicodeString Value);
  virtual void __fastcall Set_messageFontColor(System::UnicodeString Value);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLOIBsType 

class TXMLOIBsType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLOIBsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLOIBsType 
  virtual System::UnicodeString __fastcall Get_OIB(int Index);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString OIB);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString OIB);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLarticleTypesType 

class TXMLarticleTypesType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLarticleTypesType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLarticleTypesType 
  virtual System::UnicodeString __fastcall Get_articleType(int Index);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Add(const System::UnicodeString articleType);
  virtual Xml::Xmlintf::_di_IXMLNode __fastcall Insert(const int Index, const System::UnicodeString articleType);
public:
  virtual void __fastcall AfterConstruction(void);
};

// Global Functions 

_di_IXMLprogramDataType __fastcall GetprogramData(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLprogramDataType __fastcall GetprogramData(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLprogramDataType __fastcall LoadprogramData(const System::UnicodeString& FileName);
_di_IXMLprogramDataType __fastcall  NewprogramData();

#define TargetNamespace ""

#endif