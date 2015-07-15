#ifndef EDK_XML_H
#define EDK_XML_H

/*
Library C++ XML - Read, parse and write XML files.
Copyright (C) 1013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside XML"
#endif

#pragma once
#ifdef __linux__
#include <stdint.h>
#endif
#include "../../pugixml/pugixml.hpp"
#include "../TypeVars.h"
#include "../String.h"
#include <iostream>

#ifdef printMessages
#warning "    Compiling XML"
#endif

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
        XML(const char* xmlCode);
        XML(edk::char8* xmlCode);
        virtual ~XML();

		//Just load the file
		bool loadFile(const char* fileName);
		bool loadFile(edk::char8* fileName);

        //parser the string
        bool parse();
        bool parse(const char* xmlCode);
        bool parse(edk::char8* xmlCode);
        bool parseFile(const char* fileName);
        bool parseFile(edk::char8* fileName);

        //save to a file
        bool saveToFile(const char* fileName);
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
        edk::char8* selectBrother(const char* name);
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
        edk::char8* selectChild(const char* name);
        edk::char8* selectChild(edk::char8* name);
        //select the first child
        edk::char8* selectFirstChild();
        //select the last child
        edk::char8* selectLastChild();
        //SELECTED ADD
        //add brother before the selected
        bool addSelectedPreviousBrother(const char* name);
        bool addSelectedPreviousBrother(edk::char8* name);
        //add brother after selected
        bool addSelectedNextBrother(const char* name);
        bool addSelectedNextBrother(edk::char8* name);
        //add childs at the beginning
        bool addSelectedPreviousChild(const char* name);
        bool addSelectedPreviousChild(edk::char8* name);
        //add childs at the end
        bool addSelectedNextChild(const char* name);
        bool addSelectedNextChild(edk::char8* name);
		//Add a attribute at end and start
		bool addSelectedNextAttribute(const char* name,const char* value);
		bool addSelectedNextAttribute(edk::char8* name,edk::char8* value);
		bool addSelectedPreviousAttribute(const char* name,const char* value);
		bool addSelectedPreviousAttribute(edk::char8* name,edk::char8* value);
        //Add a new node to the root after and before
        bool addRootPreviousChild(const char* name);
        bool addRootPreviousChild(edk::char8* name);
        bool addRootNextChild(const char* name);
        bool addRootNextChild(edk::char8* name);
        //SELECTED DELETE
        bool deleteSelected();
		bool deleteSelectedAttribute(const char* name);
		bool deleteSelectedAttribute(edk::char8* name);
		//SELECTED SET
		bool setSelectedString(const char* string);
		bool setSelectedString(edk::char8* string);
        //SELECTED GET
        //return if have a selected
        bool haveSelected();
        //return if have attributes
        bool haveSelectedAttributes();
        //test if have the attribute
        bool haveSelectedAttribute(edk::char8* name);
        //return the selectedName
        edk::char8* getSelectedName();
        //return the string of the selected
        edk::char8* getSelectedString();
        //test if have the attribute
        bool haveAttributeName(const char* name);
        bool haveAttributeName(edk::char8* name);
        //return the attribute name
        edk::char8* getSelectedAttributeName(edk::uint32 id);
        //return the attribute value
        edk::char8* getSelectedAttributeValue(edk::uint32 id);
        //return the value by the attribute name
        edk::char8* getSelectedAttributeValueByName(const char* name);
        edk::char8* getSelectedAttributeValueByName(edk::char8* name);
        //return the attributeID by the name
        edk::uint32 getSelectedAttributeID(edk::char8* name);

        //Parser Virtual Functions
        virtual void didStartElement(edk::char8* name, edk::char8** attributes, edk::char8** values, edk::uint32 attributesCount);
        virtual void foundCharacters(edk::char8* name,edk::char8* string);
        virtual void didEndElement(edk::char8* name);
    protected:
    private:

    //using PugiXML
    pugi::xml_document doc;

    pugi::xml_node selected;

    //parsing the xml
    void parsing(pugi::xml_node node);
	//add a root cleaning the code
	bool addNewRoot(edk::char8* name);
	bool addSelectedNewAttribute(edk::char8* name,edk::char8* value);
};
}//end namespace edk

#endif // XMLPARSER_H
