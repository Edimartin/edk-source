#ifndef EDK_XML_H
#define EDK_XML_H

/*
Library C++ XML - Read, parse and write XML files.
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef printMessages
#pragma message "Inside XML"
#endif

#pragma once
#ifdef __linux__
#include <stdint.h>
#endif
#include "../../pugixml/pugixml.hpp"
#include "../TypeVars.h"
#include "../String.h"
#include "../DebugFile.h"
#include <iostream>

#ifdef printMessages
#pragma message "    Compiling XML"
#endif

//Define the XML types
#define EDK_XML_NULL      0x00
#define EDK_XML_UINT      0x02
#define EDK_XML_INT       0x04
#define EDK_XML_DOUBLE    0x08
#define EDK_XML_BOOL      0x10
#define EDK_XML_STRING    0x20

/*

xml_node xml_node::parent() const;
xml_node xml_node::first_child() const;
xml_node xml_node::last_child() const;
xml_node xml_node::next_sibling() const;
xml_node xml_node::previous_sibling() const;

xml_attribute xml_node::first_attribute() const;
xml_attribute xml_node::last_attribute() const;
xml_attribute xml_attribute::next_attribute() const;
xml_attribute xml_attribute::previous_attribute() const;

const char_t* xml_node::name() const;
const char_t* xml_node::value() const;

*/

namespace edk{
class XML{
public:
    XML();
    XML(const edk::char8* xmlCode);
    XML(edk::char8* xmlCode);
    virtual ~XML();

    void Constructor();
    void Constructor(const edk::char8* xmlCode);
    void Constructor(edk::char8* xmlCode);
    void Destructor();

    //Just load the file
    bool loadFile(const edk::char8* fileName);
    bool loadFile(edk::char8* fileName);
    bool loadFromMemory(edk::classID vector,edk::uint32 size);
    bool loadFromMemory(edk::char8* vector,edk::uint32 size);
    bool loadFromMemory(const edk::char8* vector,edk::uint32 size);
    bool loadString(edk::char8* str);
    bool loadString(const edk::char8* str);

    //parser the string
    bool parse();
    bool parse(const edk::char8* xmlCode);
    bool parse(edk::char8* xmlCode);
    bool parseFile(const edk::char8* fileName);
    bool parseFile(edk::char8* fileName);

    //save to a file
    bool saveToFile(const edk::char8* fileName);
    bool saveToFile(edk::char8* fileName);

    //clean the XML
    void clean();

    //print the XML on the screen
    void print();

    //SELECT
    //clean the selected
    void cleanSelected();
    //select the first node
    edk::char8* selectRoot();
    //select the nodeFather
    edk::char8* selectFather();
    //select the brother by the name
    edk::char8* selectBrother(const edk::char8* name);
    edk::char8* selectBrother(edk::char8* name);
    //select the brother
    edk::char8* selectNextBrother();
    //select the last brother
    edk::char8* selectLastBrother();
    //select the previous brother
    edk::char8* selectPreviousBrother();
    //select the first brother
    edk::char8* selectFirstBrother();
    //select the selected's child
    edk::char8* selectChild(edk::uint32 id);
    edk::char8* selectChild(const edk::char8* name);
    edk::char8* selectChild(edk::char8* name);
    //select the first child
    edk::char8* selectFirstChild();
    //select the last child
    edk::char8* selectLastChild();
    //SELECTED ADD
    //add brother before the selected
    bool addSelectedPreviousBrother(const edk::char8* name);
    bool addSelectedPreviousBrother(edk::char8* name);
    //add brother after selected
    bool addSelectedNextBrother(const edk::char8* name);
    bool addSelectedNextBrother(edk::char8* name);
    //add childs at the beginning
    bool addSelectedPreviousChild(const edk::char8* name);
    bool addSelectedPreviousChild(edk::char8* name);
    //add childs at the end
    bool addSelectedNextChild(const edk::char8* name);
    bool addSelectedNextChild(edk::char8* name);
    bool addSelectedNextChild(const edk::char8* name,edk::uint32 value);
    bool addSelectedNextChild(edk::char8* name,edk::uint32 value);
    bool addSelectedNextChild(const edk::char8* name,edk::int32 value);
    bool addSelectedNextChild(edk::char8* name,edk::int32 value);
    bool addSelectedNextChild(const edk::char8* name,edk::uint64 value);
    bool addSelectedNextChild(edk::char8* name,edk::uint64 value);
    bool addSelectedNextChild(const edk::char8* name,edk::int64 value);
    bool addSelectedNextChild(edk::char8* name,edk::int64 value);
    bool addSelectedNextChild(const edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedNextChild(edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedNextChild(const edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedNextChild(edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedNextChild(const edk::char8* name,const edk::char8* value);
    bool addSelectedNextChild(edk::char8* name,const edk::char8* value);
    bool addSelectedNextChild(const edk::char8* name,edk::char8* value);
    bool addSelectedNextChild(edk::char8* name,edk::char8* value);
    bool addSelectedNextChild(const edk::char8* name,bool value);
    bool addSelectedNextChild(edk::char8* name,bool value);
    //Add a attribute at end and start
    bool addSelectedNextAttribute(const edk::char8* name,edk::uint32 value);
    bool addSelectedNextAttribute(edk::char8* name,edk::uint32 value);
    bool addSelectedNextAttribute(const edk::char8* name,edk::int32 value);
    bool addSelectedNextAttribute(edk::char8* name,edk::int32 value);
    bool addSelectedNextAttribute(const edk::char8* name,edk::uint64 value);
    bool addSelectedNextAttribute(edk::char8* name,edk::uint64 value);
    bool addSelectedNextAttribute(const edk::char8* name,edk::int64 value);
    bool addSelectedNextAttribute(edk::char8* name,edk::int64 value);
    bool addSelectedNextAttribute(const edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedNextAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedNextAttribute(const edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedNextAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedNextAttribute(const edk::char8* name,const edk::char8* value);
    bool addSelectedNextAttribute(edk::char8* name,const edk::char8* value);
    bool addSelectedNextAttribute(const edk::char8* name,edk::char8* value);
    bool addSelectedNextAttribute(edk::char8* name,edk::char8* value);
    bool addSelectedNextAttribute(const edk::char8* name,bool value);
    bool addSelectedNextAttribute(edk::char8* name,bool value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::uint32 value);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::uint32 value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::int32 value);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::int32 value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::uint64 value);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::uint64 value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::int64 value);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::int64 value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits=2u);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits=4u);
    bool addSelectedPreviousAttribute(const edk::char8* name,const edk::char8* value);
    bool addSelectedPreviousAttribute(edk::char8* name,const edk::char8* value);
    bool addSelectedPreviousAttribute(const edk::char8* name,edk::char8* value);
    bool addSelectedPreviousAttribute(edk::char8* name,edk::char8* value);
    bool addSelectedPreviousAttribute(const edk::char8* name,bool value);
    bool addSelectedPreviousAttribute(edk::char8* name,bool value);
    //Add a new node to the root after and before
    bool addRootPreviousChild(const edk::char8* name);
    bool addRootPreviousChild(edk::char8* name);
    bool addRootNextChild(const edk::char8* name);
    bool addRootNextChild(edk::char8* name);
    //SELECTED DELETE
    bool deleteSelected();
    bool deleteSelectedAttribute(const edk::char8* name);
    bool deleteSelectedAttribute(edk::char8* name);
    //SELECTED SET
    bool setSelectedString(const edk::char8* string);
    bool setSelectedString(edk::char8* string);
    bool setSelectedString(edk::uint32 string);
    bool setSelectedString(edk::int32 string);
    bool setSelectedString(edk::uint64 string);
    bool setSelectedString(edk::int64 string);
    bool setSelectedString(edk::float32 string,edk::uint32 digits=2u);
    bool setSelectedString(edk::float64 string,edk::uint32 digits=4u);
    //SELECTED GET
    //return if have a selected
    bool haveSelected();
    //return if have attributes
    bool haveSelectedAttributes();
    //test if have the attribute
    bool haveSelectedAttribute(edk::char8* name);
    bool haveSelectedAttribute(const edk::char8* name);
    //return the selectedName
    edk::char8* getSelectedName();
    //return the string of the selected
    edk::char8* getSelectedString();
    edk::int32 getSelectedStringAsInt32();
    edk::uint32 getSelectedStringAsUint32();
    edk::int64 getSelectedStringAsInt64();
    edk::uint64 getSelectedStringAsUint64();
    edk::float32 getSelectedStringAsFloat32();
    edk::float64 getSelectedStringAsFloat64();
    bool getSelectedStringAsBool();
    //return the type of the selected string
    edk::uint8 getSelectedStringType();
    //test if have the attribute
    bool haveAttributeName(const edk::char8* name);
    bool haveAttributeName(edk::char8* name);
    //return the attribute name
    edk::char8* getSelectedAttributeName(edk::uint32 id);
    //return the attribute value
    edk::char8* getSelectedAttributeValue(edk::uint32 id);
    edk::int32 getSelectedAttributeValueAsInt32(edk::uint32 id);
    edk::uint32 getSelectedAttributeValueAsUint32(edk::uint32 id);
    edk::int64 getSelectedAttributeValueAsInt64(edk::uint32 id);
    edk::uint64 getSelectedAttributeValueAsUint64(edk::uint32 id);
    edk::float32 getSelectedAttributeValueAsFloat32(edk::uint32 id);
    edk::float64 getSelectedAttributeValueAsFloat64(edk::uint32 id);
    bool getSelectedAttributeValueAsBool(edk::uint32 id);
    //return the attribute type
    edk::uint8 getSelectedAttributeType(edk::uint32 id);
    //return the value by the attribute name
    edk::char8* getSelectedAttributeValueByName(const edk::char8* name);
    edk::char8* getSelectedAttributeValueByName(edk::char8* name);
    edk::int32 getSelectedAttributeValueAsInt32ByName(const edk::char8* name);
    edk::int32 getSelectedAttributeValueAsInt32ByName(edk::char8* name);
    edk::uint32 getSelectedAttributeValueAsUint32ByName(const edk::char8* name);
    edk::uint32 getSelectedAttributeValueAsUint32ByName(edk::char8* name);
    edk::int64 getSelectedAttributeValueAsInt64ByName(const edk::char8* name);
    edk::int64 getSelectedAttributeValueAsInt64ByName(edk::char8* name);
    edk::uint64 getSelectedAttributeValueAsUint64ByName(const edk::char8* name);
    edk::uint64 getSelectedAttributeValueAsUint64ByName(edk::char8* name);
    edk::float32 getSelectedAttributeValueAsFloat32ByName(const edk::char8* name);
    edk::float32 getSelectedAttributeValueAsFloat32ByName(edk::char8* name);
    edk::float64 getSelectedAttributeValueAsFloat64ByName(const edk::char8* name);
    edk::float64 getSelectedAttributeValueAsFloat64ByName(edk::char8* name);
    bool getSelectedAttributeValueAsBoolByName(const edk::char8* name);
    bool getSelectedAttributeValueAsBoolByName(edk::char8* name);
    //return the attributeID by the name
    edk::uint32 getSelectedAttributeID(edk::char8* name);

    //COMPARE
    bool compareSelectedName(edk::char8* compare);
    bool compareSelectedName(const edk::char8* compare);

    //Parser Virtual Functions
    virtual void didStartElement(edk::char8* name, edk::char8** attributes, edk::char8** values, edk::uint8* types, edk::uint32 attributesCount);
    virtual void foundCharacters(edk::char8* name,edk::char8* string,edk::uint8 type);
    virtual void didEndElement(edk::char8* name);
protected:
    //return the string type
    static edk::uint8 getStringType(const edk::char8* str);
    static edk::uint8 getStringType(edk::char8* str);
private:

    //using PugiXML
    pugi::xml_document doc;

    pugi::xml_node selected;
    pugi::xml_node nodePrint;

    //parsing the xml
    void parsing(pugi::xml_node node);
    //add a root cleaning the code
    bool addNewRoot(edk::char8* name);
    bool addSelectedNewAttribute(edk::char8* name,edk::char8* value);

    void printNewLineSpaces(edk::uint32 spaces);
    void recursivePrint(edk::uint32 indent,pugi::xml_node nodePrint);
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // XMLPARSER_H
