#include "XML.h"

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
#warning "            Inside XML.cpp"
#endif

edk::XML::XML()
{
    //
}
edk::XML::XML(const char* xmlCode)
{
    //parse the xmlCode
    this->parse(xmlCode);
}
edk::XML::XML(edk::char8* xmlCode)
{
    //parse the xmlCode
    this->parse(xmlCode);
}

edk::XML::~XML()
{
    //dtor
}
//Just load the file
bool edk::XML::loadFile(const char* fileName){
    //
    //else return false
    return this->loadFile((edk::char8*) fileName);
}
bool edk::XML::loadFile(edk::char8* fileName){
    //test the name of the file
    if(fileName){
        //load the file
        if((bool)this->doc.load_file((char*)fileName)){
            //then parse the XML
            return true;
        }
    }
    //else return false
    return false;
}

//parsing the xml
void edk::XML::parsing(pugi::xml_node node){
    //test if the node have a name
    if(*node.name()){
        //then print the nodeName

        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = node.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //
            attributesCount++;
        }
        //test if have attributesCount
        if(attributesCount){
            //create a new string to get the attributes and values
            edk::char8** attributes=new edk::char8*[attributesCount];
            edk::char8** values=new edk::char8*[attributesCount];
            if(attributes && values){
                //get the attributes
                pugi::xml_attribute attr = node.first_attribute();
                for (edk::uint32 i = 0u;i<attributesCount;i++){
                    //
                    //*attr.name()
                    //std::cout << " " << attr.name() << "=" << attr.value();
                    if(*attr.name()){
                        //
                        attributes[i]=(edk::char8*)attr.name();
                        values[i]=(edk::char8*)attr.value();
                    }
                    else{
                        //
                        attributes[i]=NULL;
                        values[i]=NULL;
                    }
                    //increment
                    attr = attr.next_attribute();
                }

                //Attributes copied. Did Start Element
                this->didStartElement((edk::char8*)node.name(), attributes, values, attributesCount);
            }
            //delete the attributes
            if(attributes) delete[] attributes;
            attributes=NULL;
            if(values) delete[] values;
            values=NULL;
        }
        else{
            //else dont have attributes
            this->didStartElement((edk::char8*)node.name(), NULL, NULL, 0u);
        }

        //get value
        if(*node.text()){
            //
            this->foundCharacters((edk::char8*)node.name(),(edk::char8*)node.text().as_string());
        }

        //test if have a child
        this->parsing(node.first_child());

        this->didEndElement((edk::char8*)node.name());

        //test if have a brother
        this->parsing(node.next_sibling());
    }
}



//parser the string
bool edk::XML::parse(){
    //test if have a firstNode
    if(this->doc.first_child()){
        //
        this->parsing(this->doc.first_child());

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::XML::parse(const char* xmlCode){
    //
    return this->parse((edk::char8*) xmlCode);
}
bool edk::XML::parse(edk::char8* xmlCode){
    //first clean the XML
    this->clean();
    //test if have the code
    if(xmlCode){
        //parser the XML
        if(this->doc.load((char*)xmlCode)){
            //then parse the XML
            return this->parse();
        }
    }
    return false;
}
bool edk::XML::parseFile(const char* fileName){
    //
    return this->parseFile((edk::char8*)fileName);
}
bool edk::XML::parseFile(edk::char8* fileName){
    //test the name of the file
    if(this->loadFile(fileName)){
        //then parse the XML
        return this->parse();
    }
    //esle return false
    return false;
}

//save to a file
bool edk::XML::saveToFile(const char* fileName){
    //
    //else return false
    return this->saveToFile((edk::char8*) fileName);
}
bool edk::XML::saveToFile(edk::char8* fileName){
    //test the name of the file
    if(fileName){
        //save the file
        return (bool)this->doc.save_file((char*)fileName);
    }
    //else return false
    return false;
}

//clean the XML
void edk::XML::clean(){
    //
    this->doc.reset();
}


//print the XML on the screen
void edk::XML::print(){
    //
    doc.print(std::cout, "", pugi::format_raw);
}

//SELECT
//clean the selected
void edk::XML::cleanSelected(){
    //
    this->selected=pugi::xml_node();
}
//select the first node
edk::char8* edk::XML::selectRoot(){
    //remove the selected
    this->selected = this->doc.first_child();
    if(*selected.name()){
        return (edk::char8*)this->selected.name();
    }
    //else return NULL
    return NULL;
}
//select the nodeFather
edk::char8* edk::XML::selectFather(){
    //test if have a parent
    if(*this->selected.parent().name()){
        //select the parent
        this->selected=this->selected.parent();
        //return the name
        return (edk::char8*)this->selected.name();
    }
    //else return NULL;
    return NULL;
}
//select the brother by the name
edk::char8* edk::XML::selectBrother(const char* name){
    //
    return this->selectBrother((edk::char8*) name);
}
edk::char8* edk::XML::selectBrother(edk::char8* name){
    //test if the name exist
    if(name){
        //use a tempBrother
        pugi::xml_node brother;

        //select the previousBrother
        brother=this->selected.previous_sibling();
        while(*brother.name()){
            //test if the brother have the same name
            if(edk::String::strCompare((edk::char8*)brother.name(),name)){
                //then select the bother
                this->selected = brother;
                //reeturn the selectedName
                return (edk::char8*)this->selected.name();
            }
            //goto previous brother
            brother = brother.previous_sibling();
        }

        //else select the nextBrother
        brother = this->selected.next_sibling();
        while(*brother.name()){
            //test if the brother have the same name
            if(edk::String::strCompare((edk::char8*)brother.name(),name)){
                //then select the bother
                this->selected = brother;
                //reeturn the selectedName
                return (edk::char8*)this->selected.name();
            }

            //goto next brother
            brother = brother.next_sibling();
        }
    }
    //else return NULL
    return NULL;
}
//select the brother
edk::char8* edk::XML::selectNextBrother(){
    //test if have a bother
    if(*this->selected.next_sibling().name()){
        //then select the next
        this->selected = this->selected.next_sibling();
        //return the name
        return (edk::char8*)this->selected.name();
    }

    //else return NULL
    return NULL;
}
//select the last brother
edk::char8* edk::XML::selectLastBrother(){
    //test if have a father
    if(*this->selected.parent().name()){
        //then select the last child
        this->selected = this->selected.parent().last_child();
        //return the name
        return (edk::char8*)this->selected.name();
    }
    else{
        //else select from the doc
        //then select the last child
        this->selected = this->doc.parent().last_child();
        //return the name
        return (edk::char8*)this->selected.name();
    }
    //else return NULL
    return NULL;
}
//select the previous brother
edk::char8* edk::XML::selectPreviousBrother(){
    //test if have a previous bother
    if(*this->selected.previous_sibling().name()){
        //then select the previous
        this->selected = this->selected.previous_sibling();
        //return the name
        return (edk::char8*)this->selected.name();
    }

    //else return NULL
    return NULL;
}
//select the first brother
edk::char8* edk::XML::selectFirstBrother(){
    //test if have a father
    if(*this->selected.parent().name()){
        //then select the first child
        this->selected = this->selected.parent().first_child();
        //return the name
        return (edk::char8*)this->selected.name();
    }
    else{
        //else select from the doc
        //then select the first child
        this->selected = this->doc.parent().first_child();
        //return the name
        return (edk::char8*)this->selected.name();
    }
    //else return NULL
    return NULL;
}
//select the selected's child
edk::char8* edk::XML::selectChild(edk::uint32 id){
    //select the child
    pugi::xml_node child = this->selected.first_child();

    //count the childs
    edk::uint32 childCounter=0u;
    while(*child.name()){
        //test if have the child
        if(childCounter==id){
            //select the child
            this->selected=child;
            //return the childNane
            return (edk::char8*)child.name();
        }
        //select the child's brother
        child=child.next_sibling();
        //increment the counter
        childCounter++;
    };
    //esle return false
    return NULL;
}
edk::char8* edk::XML::selectChild(const char* name){
    return this->selectChild((edk::char8*) name);
}
edk::char8* edk::XML::selectChild(edk::char8* name){
    //test if the name exist
    if(name){
        //select the child
        pugi::xml_node child = this->selected.child((char*)name);
        if(*child.name()){
            //
            this->selected = child;
            return (edk::char8*)this->selected.name();
        }
        else if(!*this->selected.name()){
            child = this->doc.child((char*)name);
            if(*child.name()){
                //
                this->selected = child;
                return (edk::char8*)this->selected.name();
            }
        }
    }
    //esle return false
    return NULL;
}
//select the first child
edk::char8* edk::XML::selectFirstChild(){
    //test if have a first child
    pugi::xml_node child = this->selected.first_child();
    if(*child.name()){
        //then select the first child
        this->selected = child;
        //return the name selected
        return (edk::char8*)this->selected.name();
    }
    //else return NULL;
    return NULL;
}
//select the last child
edk::char8* edk::XML::selectLastChild(){
    //test if have a first child
    pugi::xml_node child = this->selected.last_child();
    if(*child.name()){
        //then select the first child
        this->selected = child;
        //return the name selected
        return (edk::char8*)this->selected.name();
    }
    //else return NULL;
    return NULL;
}
//SELECTED ADD
//add brother before the selected
bool edk::XML::addSelectedPreviousBrother(const char* name){
    //
    return this->addSelectedPreviousBrother((edk::char8*) name);
}
bool edk::XML::addSelectedPreviousBrother(edk::char8* name){
    //test if have the selected and if have the new name
    if(this->haveSelected()&&name){
        //select the parent
        pugi::xml_node father= this->selected.parent();
        if(*father.name()){
            //add to the father a child previous the selected
            return father.insert_child_before((char*)name,this->selected);
        }
        else{
            //then use the doc to add a child
            return this->doc.insert_child_before((char*)name,this->selected);
        }
    }
    //else return NULL
    return NULL;
}
//add brother after selected
bool edk::XML::addSelectedNextBrother(const char* name){
    //
    return this->addSelectedNextBrother((edk::char8*) name);
}
bool edk::XML::addSelectedNextBrother(edk::char8* name){
    //test if have the selected and if have the new name
    if(this->haveSelected()&&name){
        //select the parent
        pugi::xml_node father= this->selected.parent();
        if(*father.name()){
            //add to the father a child previous the selected
            return father.insert_child_after((char*)name,this->selected);
        }
        else{
            //then use the doc to add a child
            return this->doc.insert_child_after((char*)name,this->selected);
        }
    }
    //else return NULL
    return NULL;
}
//add childs at the beginning
bool edk::XML::addSelectedPreviousChild(const char* name){
    //
    return this->addSelectedPreviousChild((edk::char8*) name);
}
bool edk::XML::addSelectedPreviousChild(edk::char8* name){
    //test if have the new name
    if(name){
        //test if have a first child
        if(*this->selected.first_child().name()){
            //then add a child before the first
            return selected.insert_child_before((char*)name,this->selected.first_child());
        }
        else{
            //else just add a new child
            return selected.append_child((char*)name);
        }
    }
    //else return false
    return false;
}
//add childs at the end
bool edk::XML::addSelectedNextChild(const char* name){
    //
    //else return false
    return this->addSelectedNextChild((edk::char8*) name);
}
bool edk::XML::addSelectedNextChild(edk::char8* name){
    //test if have the new name
    if(name){
        if(*this->selected.name()){
            //test if have a last child
            if(*this->selected.last_child().name()){
                //then add a child before the last
                return selected.insert_child_after((char*)name,this->selected.last_child());
            }
            else{
                //else just add a new child
                return selected.append_child((char*)name);
            }
        }
        else{
            //test if have a root
            if(!*this->doc.first_child().name()){
                //add a new root
                return this->addNewRoot(name);
            }
        }
    }
    //else return false
    return false;
}
//Add a attribute at the end
bool edk::XML::addSelectedNextAttribute(const char* name,edk::uint32 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::uint32 value){
    bool ret = false;
    edk::char8* str = edk::String::uint32ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::int32 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::int32 value){
    bool ret = false;
    edk::char8* str = edk::String::int32ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::uint64 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::uint64 value){
    bool ret = false;
    edk::char8* str = edk::String::uint64ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::int64 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::int64 value){
    bool ret = false;
    edk::char8* str = edk::String::int64ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::float32 value,edk::uint32 digits){
    return this->addSelectedNextAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float32ToStr(value,digits);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::float64 value,edk::uint32 digits){
    return this->addSelectedNextAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float64ToStr(value,digits);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const char* name,const char* value){
    return this->addSelectedNextAttribute((edk::char8*) name,(edk::char8*) value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,const char* value){
    return this->addSelectedNextAttribute(name,(edk::char8*) value);
}
bool edk::XML::addSelectedNextAttribute(const char* name,edk::char8* value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::char8* value){
    //test the selected
    if (*this->selected.name()){
        if(!(*this->selected.first_attribute().name())){
            //create a new attribute
            return this->addSelectedNewAttribute(name,value);
        }
        else{
            //else add the attribute after the last
            if(this->selected.insert_attribute_after((char*)name,this->selected.last_attribute())){
                //set the attribute value
                if(this->selected.attribute((char*)name).set_value((char*)value)){
                    //return true
                    return true;
                }
                else{
                    //else remove the attribute
                    this->selected.remove_attribute((char*)name);
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::uint32 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::uint32 value){
    bool ret = false;
    edk::char8* str = edk::String::uint32ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::int32 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::int32 value){
    bool ret = false;
    edk::char8* str = edk::String::int32ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::uint64 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::uint64 value){
    bool ret = false;
    edk::char8* str = edk::String::uint64ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::int64 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::int64 value){
    bool ret = false;
    edk::char8* str = edk::String::int64ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::float32 value,edk::uint32 digits){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float32ToStr(value,digits);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::float64 value,edk::uint32 digits){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float64ToStr(value,digits);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        delete[] str;
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,const char* value){
    //
    return this->addSelectedPreviousAttribute((edk::char8*) name,(edk::char8*) value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,const char* value){
    return this->addSelectedPreviousAttribute(name,(edk::char8*) value);
}
bool edk::XML::addSelectedPreviousAttribute(const char* name,edk::char8* value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::char8* value){
    //test the selected
    if (*this->selected.name()){
        if(!(*this->selected.first_attribute().name())){
            //create a new attribute
            return this->addSelectedNewAttribute(name,value);
        }
        else{
            //else add the attribute after the last
            if(this->selected.insert_attribute_before((char*)name,this->selected.first_attribute())){
                //set the attribute value
                if(this->selected.attribute((char*)name).set_value((char*)value)){
                    //return true
                    return true;
                }
                else{
                    //else remove the attribute
                    this->selected.remove_attribute((char*)name);
                }
            }
        }
    }
    //else return false
    return false;
}
//Add a new node to the root
bool edk::XML::addRootPreviousChild(const char* name){
    //
    return this->addRootPreviousChild((edk::char8*) name);
}
bool edk::XML::addRootPreviousChild(edk::char8* name){
    //test if have a first child in root
    if (!(*doc.first_child().name())){
        //then add the new root
        return this->addNewRoot(name);
    }
    else{
        //test if the name exist
        if(name){
            //add before the first node
            return (bool)this->doc.insert_child_before((char*)name,this->doc.first_child());
        }
    }
    //else return false
    return false;
}
bool edk::XML::addRootNextChild(const char* name){
    //
    return this->addRootNextChild((edk::char8*) name);
}
bool edk::XML::addRootNextChild(edk::char8* name){
    //test if have a first child in root
    if (!(*doc.first_child().name())){
        //then add the new root
        return this->addNewRoot(name);
    }
    else{
        //test if the name exist
        if(name){
            //else add after the last node
            if(this->doc.insert_child_after((char*)name,this->doc.last_child())){
                //
                return true;
            }
        }
    }
    //else return false
    return false;
}
//SELECTED DELETE
bool edk::XML::deleteSelected(){
    //test if have a selected
    if(this->haveSelected()){
        //then select the father and remove the child
        pugi::xml_node child = this->selected;
        //test if have a parent
        if(*this->selected.parent().name()){
            this->selected=child.parent();
            //remove the child
            return this->selected.remove_child(child);
        }
        else{
            //else test if have some brother
            if(*child.next_sibling().name()){
                //select the next
                this->selected = child.next_sibling();
            }
            else if(*child.previous_sibling().name()){
                //
                this->selected = child.previous_sibling();
            }
            else{
                //clear the selected
                this->cleanSelected();
            }
            //remove the child
            return this->doc.remove_child(child);
        }
    }
    //else return false
    return false;
}
bool edk::XML::deleteSelectedAttribute(const char* name){
    //
    return this->deleteSelectedAttribute((edk::char8*) name);
}
bool edk::XML::deleteSelectedAttribute(edk::char8* name){
    //test the selected and the name
    if (*this->selected.name() && name){
        //remove the attribute
        return this->selected.remove_attribute((char*)name);
    }
    //else return false
    return false;
}
//SELECTED SET
bool edk::XML::setSelectedString(const char* string){
    //
    return this->setSelectedString((edk::char8*) string);
}
bool edk::XML::setSelectedString(edk::char8* string){
    //test if have selected
    if (this->haveSelected()){
        //set the selected string
        if(this->selected.text().set((char*)string)){
            //
            return true;
        }
    }
    //else return false
    return false;
}
//SELECTED GET
//return if have a selected
bool edk::XML::haveSelected(){
    //test if have a selected
    if(*this->selected.name()) return true;
    //else return false;
    return false;
}
//return if have attributes
bool edk::XML::haveSelectedAttributes(){
    //test if have selected
    if(this->haveSelected()){
        //test if the select have a first attribute
        if(*this->selected.first_attribute().name()){
            //return true
            return true;
        }
    }
    //else return false
    return false;
}
//test if have the attribute
bool edk::XML::haveSelectedAttribute(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //return true
                return true;
            }
        }

    }
    //else return false
    return false;
}
//return the selectedName
edk::char8* edk::XML::getSelectedName(){
    //test if have a selected
    if(this->haveSelected()){
        //return the selectedName
        return (edk::char8*)this->selected.name();
    }
    //else return NULL
    return NULL;
}
//return the string of the selected
edk::char8* edk::XML::getSelectedString(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return (edk::char8*)this->selected.text().as_string();
        }
    }
    //else return NULL
    return NULL;
}
//test if have the attribute
bool edk::XML::haveAttributeName(const char* name){
    return this->haveAttributeName((edk::char8*) name);
}
bool edk::XML::haveAttributeName(edk::char8* name){
    //test the name
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return true;
            }
        }

    }
    //else return NULL
    return false;
}
//return the attribute name
edk::char8* edk::XML::getSelectedAttributeName(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute name
                return (edk::char8*)attr.name();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return NULL;
}
//return the attribute value
edk::char8* edk::XML::getSelectedAttributeValue(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return (edk::char8*)attr.value();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return NULL;
}
//return the value by the attribute name
edk::char8* edk::XML::getSelectedAttributeValueByName(const char* name){
    //
    return this->getSelectedAttributeValueByName((edk::char8*) name);
}
edk::char8* edk::XML::getSelectedAttributeValueByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return (edk::char8*)attr.value();
            }
        }

    }
    //else return NULL
    return NULL;
}
//return the attributeID by the name
edk::uint32 edk::XML::getSelectedAttributeID(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //count the attributes
        edk::uint32 attributesCount=0u;
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the count
                return attributesCount;
            }
            //
            attributesCount++;
        }

    }
    //else return 0u;
    return 0u;
}


//Parser Virtual Functions
void edk::XML::didStartElement(edk::char8* name, edk::char8** attributes, edk::char8** values, edk::uint32 attributesCount){
    //test if have the name
    if(name){
        //
//        printf("\nDid Start Element '%s'"
//               ,name
//               );

        //test the attributes
        for(edk::uint32 i=0u;i<attributesCount;i++){
            //
            if(attributes[i] && values[i]){
                //
//                printf("\n    count %u attribute '%s' value '%s'"
//                       ,i
//                       ,attributes[i]
//                       ,values[i]
//                       );
            }
        }
    }
}
void edk::XML::foundCharacters(edk::char8* name,edk::char8* string){
    //
    //test if have the name
    if(name){
        //
        //test if have the characters
        if(string){
            //
//            printf("\n    Found Characters '%s' in '%s'"
//                   ,string
//                   ,name
//                   );
        }
    }
}
void edk::XML::didEndElement(edk::char8* name){
    //test if have the name
    if(name){
        //
//        printf("\nDid End Element '%s'"
//               ,name
//               );
    }
}
//add a root cleaning the code
bool edk::XML::addNewRoot(edk::char8* name){
    bool ret=false;
    if (name){
        if (this->doc.append_child((char*)name)){
            return true;
        }
    }
    return ret;
}
bool edk::XML::addSelectedNewAttribute(edk::char8* name,edk::char8* value){
    //test the strings and selected
    if (this->selected && name && value){
        //
        if(this->selected.append_attribute((char*)name)){
            //load the attribute to set the value
            //set the attribute value
            if(this->selected.attribute((char*)name).set_value((char*)value)){
                //return true
                return true;
            }
            else{
                //else remove the attribute
                this->selected.remove_attribute((char*)name);
            }
        }
        else{
            return false;
        }
    }
    return false;
}
