#include "XML.h"

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
#pragma message "            Inside XML.cpp"
#endif

edk::XML::XML(){
    this->classThis=NULL;
    this->Constructor();
}
edk::XML::XML(const edk::char8* xmlCode){
    this->classThis=NULL;
    this->Constructor(xmlCode);
}
edk::XML::XML(edk::char8* xmlCode){
    this->classThis=NULL;
    this->Constructor(xmlCode);
}

edk::XML::~XML(){
    this->Destructor();
}

void edk::XML::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::XML::Constructor(const edk::char8* xmlCode){
    if(this->classThis!=this){
        this->classThis=this;
        //parse the xmlCode
        this->parse(xmlCode);
    }
}
void edk::XML::Constructor(edk::char8* xmlCode){
    if(this->classThis!=this){
        this->classThis=this;
        //parse the xmlCode
        this->parse(xmlCode);
    }
}
void edk::XML::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//Just load the file
bool edk::XML::loadFile(const edk::char8* fileName){
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
bool edk::XML::loadFromMemory(edk::classID vector,edk::uint32 size){
    //test the name of the file
    if(vector && size){
        //load the file
        if((bool)this->doc.load_buffer(vector,size)){
            //then parse the XML
            return true;
        }
    }
    //else return false
    return false;
}

bool edk::XML::loadFromMemory(edk::char8* vector,edk::uint32 size){
    return this->loadFromMemory((edk::classID) vector,size);
}
bool edk::XML::loadFromMemory(const edk::char8* vector,edk::uint32 size){
    return this->loadFromMemory((edk::classID) vector,size);
}
bool edk::XML::loadString(edk::char8* str){
    return this->loadFromMemory(str,edk::String::strSize(str));
}
bool edk::XML::loadString(const edk::char8* str){
    return this->loadString((edk::char8*) str);
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
            edk::char8** attributes= (edk::char8**)malloc(sizeof(edk::char8*) * (attributesCount));
            edk::char8** values= (edk::char8**)malloc(sizeof(edk::char8*) * (attributesCount));
            edk::uint8* types= (edk::uint8*)malloc(sizeof(edk::uint8) * (attributesCount));
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
                        types[i]=edk::XML::getStringType(values[i]);
                    }
                    else{
                        //
                        attributes[i]=NULL;
                        values[i]=NULL;
                        types[i]=EDK_XML_NULL;
                    }
                    //increment
                    attr = attr.next_attribute();
                }

                //Attributes copied. Did Start Element
                this->didStartElement((edk::char8*)node.name(), attributes, values, types, attributesCount);
            }
            //delete the attributes
            if(attributes){
                free(attributes);
            }
            attributes=NULL;
            if(values){
                free(values);
            }
            values=NULL;
            if(types){
                free(types);
            }
            types=NULL;
        }
        else{
            //else dont have attributes
            this->didStartElement((edk::char8*)node.name(), NULL, NULL, NULL, 0u);
        }

        //get value
        if(*node.text()){
            //
            this->foundCharacters((edk::char8*)node.name(),(edk::char8*)node.text().as_string(),edk::XML::getStringType((edk::char8*)node.text().as_string()));
        }

        //test if have a child
        this->parsing(node.first_child());

        this->didEndElement((edk::char8*)node.name());

        //test if have a brother
        this->parsing(node.next_sibling());
    }
}
bool edk::XML::addSelectedNewAttribute(edk::char8* name,edk::char8* value){
    //test the strings and selected
    if(this->selected && name && value){
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

void edk::XML::printNewLineSpaces(edk::uint32 spaces){
    printf("\n");
    for(edk::uint32 i=0u;i<spaces;i++){
        printf(" ");
    }
}
void edk::XML::recursivePrint(edk::uint32 indent,pugi::xml_node nodePrint){
    while(!nodePrint.empty()){
        //print the name
        this->printNewLineSpaces(indent*4u);
        printf("<'%s'",nodePrint.name());fflush(stdout);

        bool haveAtt=false;

        //print the attributes
        for(pugi::xml_attribute attr = nodePrint.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            this->printNewLineSpaces((indent+1u)*4u);
            printf("'%s':'%s'",(edk::char8*)attr.name(),(edk::char8*)attr.value());fflush(stdout);
            haveAtt=true;
        }
        //print the string
        if(haveAtt){
            this->printNewLineSpaces(indent*4u);
            printf(">");fflush(stdout);
        }
        else{
            printf(">");fflush(stdout);
        }

        if(*nodePrint.text()){
            //return the text
            printf(" '%s' ",nodePrint.text().as_string());fflush(stdout);
        }
        if(!nodePrint.first_child().empty()){
            //go to the next brother
            this->recursivePrint(indent+1u,nodePrint.first_child());
        }

        this->printNewLineSpaces(indent*4u);
        printf("</'%s'>",nodePrint.name());fflush(stdout);

        nodePrint = nodePrint.next_sibling();
    }
}

//return the string type
edk::uint8 edk::XML::getStringType(const edk::char8* str){
    return edk::XML::getStringType((edk::char8*) str);
}
edk::uint8 edk::XML::getStringType(edk::char8* str){
    if(str){
        if(*str){
            //test the first character
            if(*str=='-'){
                str++;
                //could it be an int
                edk::uint32 havePointer=0u;
                while(*str){
                    //test if it's NOT a number
                    if(*str<'0' || *str>'9'){
                        //then test if it's a pointer
                        if(*str=='.'){
                            //test if the next is a number
                            str++;
                            if(*str){
                                if(*str<'0' || *str>'9'){
                                    //then it's a string
                                    return EDK_XML_STRING;
                                }
                            }
                            else{
                                //else it's a string
                                return EDK_XML_STRING;
                            }
                            //it's a pointer
                            havePointer++;
                            //just continue
                            continue;
                        }
                        else{
                            //else it's a string
                            return EDK_XML_STRING;
                        }
                    }
                    str++;
                }
                //test how many pointers it have
                if(havePointer){
                    //test if have one pointer
                    if(havePointer==1u){
                        //else it's a double
                        return EDK_XML_DOUBLE;
                    }
                    else{
                        //else it's a string
                        return EDK_XML_STRING;
                    }
                }
                else{
                    //it's a int
                    return EDK_XML_INT;
                }
            }
            else if((*str>='0' && *str<='9') || *str=='+'){
                str++;
                //could it be an uint
                edk::uint32 havePointer=0u;
                while(*str){
                    //test if it's NOT a number
                    if(*str<'0' || *str>'9'){
                        //then test if it's a pointer
                        if(*str=='.'){
                            //test if the next is a number
                            str++;
                            if(*str){
                                if(*str<'0' || *str>'9'){
                                    //then it's a string
                                    return EDK_XML_STRING;
                                }
                            }
                            else{
                                //else it's a string
                                return EDK_XML_STRING;
                            }
                            //it's a pointer
                            havePointer++;
                            //just continue
                            continue;
                        }
                        else{
                            //else it's a string
                            return EDK_XML_STRING;
                        }
                    }
                    str++;
                }
                //test how many pointers it have
                if(havePointer){
                    //test if have one pointer
                    if(havePointer==1u){
                        //else it's a double
                        return EDK_XML_DOUBLE;
                    }
                    else{
                        //else it's a string
                        return EDK_XML_STRING;
                    }
                }
                else{
                    //it's a int
                    return EDK_XML_UINT;
                }
            }
            else if(*str=='t'||*str=='T'){
                //coult it be bool
                str++;
                if(*str=='r'){
                    str++;
                    if(*str=='u'){
                        str++;
                        if(*str=='e'){
                            str++;
                            if(*str=='\0'){
                                //it's a boolean
                                return EDK_XML_BOOL;
                            }
                        }
                    }
                }
                //it's a string
                return EDK_XML_STRING;
            }
            else if(*str=='f'||*str=='F'){
                //coult it be bool
                str++;
                if(*str=='a'){
                    str++;
                    if(*str=='l'){
                        str++;
                        if(*str=='s'){
                            str++;
                            if(*str=='e'){
                                str++;
                                if(*str=='\0'){
                                    //it's a boolean
                                    return EDK_XML_BOOL;
                                }
                            }
                        }
                    }
                }
                //it's a string
                return EDK_XML_STRING;
            }
            else{
                //it's a string
                return EDK_XML_STRING;
            }
        }
    }
    return EDK_XML_NULL;
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
bool edk::XML::parse(const edk::char8* xmlCode){
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
bool edk::XML::parseFile(const edk::char8* fileName){
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
bool edk::XML::saveToFile(const edk::char8* fileName){
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
    //doc.print(std::cout, "", pugi::format_indent);

    this->nodePrint = this->doc.first_child();
    if(this->nodePrint.name()){
        this->recursivePrint(0u,this->nodePrint);
    }
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
edk::char8* edk::XML::selectBrother(const edk::char8* name){
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
edk::char8* edk::XML::selectChild(const edk::char8* name){
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
bool edk::XML::addSelectedPreviousBrother(const edk::char8* name){
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
bool edk::XML::addSelectedNextBrother(const edk::char8* name){
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
bool edk::XML::addSelectedPreviousChild(const edk::char8* name){
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
bool edk::XML::addSelectedNextChild(const edk::char8* name){
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
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::uint32 value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::uint32 value){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        if(*this->selected.name()){
            //test if have a last child
            if(*this->selected.last_child().name()){
                //then add a child before the last
                if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
            else{
                //else just add a new child
                if((temp = selected.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
        else{
            //test if have a root
            if(!*this->doc.first_child().name()){
                //add a new root
                if((temp = this->doc.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::int32 value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::int32 value){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        if(*this->selected.name()){
            //test if have a last child
            if(*this->selected.last_child().name()){
                //then add a child before the last
                if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
            else{
                //else just add a new child
                if((temp = selected.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
        else{
            //test if have a root
            if(!*this->doc.first_child().name()){
                //add a new root
                if((temp = this->doc.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::uint64 value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::uint64 value){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        edk::char8* str = edk::String::uint64ToStr(value);
        if(str){
            if(*this->selected.name()){
                //test if have a last child
                if(*this->selected.last_child().name()){
                    //then add a child before the last
                    if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
                else{
                    //else just add a new child
                    if((temp = selected.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            else{
                //test if have a root
                if(!*this->doc.first_child().name()){
                    //add a new root
                    if((temp = this->doc.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            free(str);
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::int64 value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::int64 value){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        edk::char8* str = edk::String::int64ToStr(value);
        if(str){
            if(*this->selected.name()){
                //test if have a last child
                if(*this->selected.last_child().name()){
                    //then add a child before the last
                    if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
                else{
                    //else just add a new child
                    if((temp = selected.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            else{
                //test if have a root
                if(!*this->doc.first_child().name()){
                    //add a new root
                    if((temp = this->doc.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            free(str);
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::float32 value,edk::uint32 digits){
    return this->addSelectedNextChild((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::float32 value,edk::uint32 digits){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        edk::char8* str = edk::String::float32ToStr(value,digits);
        if(str){
            if(*this->selected.name()){
                //test if have a last child
                if(*this->selected.last_child().name()){
                    //then add a child before the last
                    if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
                else{
                    //else just add a new child
                    if((temp = selected.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            else{
                //test if have a root
                if(!*this->doc.first_child().name()){
                    //add a new root
                    if((temp = this->doc.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            free(str);
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::float64 value,edk::uint32 digits){
    return this->addSelectedNextChild((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::float64 value,edk::uint32 digits){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        edk::char8* str = edk::String::float64ToStr(value,digits);
        if(str){
            if(*this->selected.name()){
                //test if have a last child
                if(*this->selected.last_child().name()){
                    //then add a child before the last
                    if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
                else{
                    //else just add a new child
                    if((temp = selected.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
            else{
                //test if have a root
                if(!*this->doc.first_child().name()){
                    //add a new root
                    if((temp = this->doc.append_child((char*)name))){
                        //set the text
                        temp.text().set(str);
                        free(str);
                        //return true;
                        return true;
                    }
                }
            }
        }
        free(str);
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,const edk::char8* value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,const edk::char8* value){
    return this->addSelectedNextChild(name,(edk::char8*) value);
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,edk::char8* value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,edk::char8* value){
    //test if have the new name
    if(name){
        pugi::xml_node temp;
        if(*this->selected.name()){
            //test if have a last child
            if(*this->selected.last_child().name()){
                //then add a child before the last
                if((temp = selected.insert_child_after((char*)name,this->selected.last_child()))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
            else{
                //else just add a new child
                if((temp = selected.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
        else{
            //test if have a root
            if(!*this->doc.first_child().name()){
                //add a new root
                if((temp = this->doc.append_child((char*)name))){
                    //set the text
                    temp.text().set(value);
                    //return true;
                    return true;
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::XML::addSelectedNextChild(const edk::char8* name,bool value){
    return this->addSelectedNextChild((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextChild(edk::char8* name,bool value){
    return this->addSelectedNextChild(name,value?(edk::char8*)"true":(edk::char8*)"false");
}
//Add a attribute at the end
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::uint32 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::uint32 value){
    bool ret = false;
    edk::char8* str = edk::String::uint32ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::int32 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::int32 value){
    bool ret = false;
    edk::char8* str = edk::String::int32ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::uint64 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::uint64 value){
    bool ret = false;
    edk::char8* str = edk::String::uint64ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::int64 value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::int64 value){
    bool ret = false;
    edk::char8* str = edk::String::int64ToStr(value);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::float32 value,edk::uint32 digits){
    return this->addSelectedNextAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float32ToStr(value,digits);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::float64 value,edk::uint32 digits){
    return this->addSelectedNextAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float64ToStr(value,digits);
    if(str){
        ret = this->addSelectedNextAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,const edk::char8* value){
    return this->addSelectedNextAttribute((edk::char8*) name,(edk::char8*) value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,const edk::char8* value){
    return this->addSelectedNextAttribute(name,(edk::char8*) value);
}
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,edk::char8* value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,edk::char8* value){
    //test the selected
    if(*this->selected.name()){
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
bool edk::XML::addSelectedNextAttribute(const edk::char8* name,bool value){
    return this->addSelectedNextAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedNextAttribute(edk::char8* name,bool value){
    return this->addSelectedNextAttribute(name,value?(edk::char8*)"true":(edk::char8*)"false");
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::uint32 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::uint32 value){
    bool ret = false;
    edk::char8* str = edk::String::uint32ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::int32 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::int32 value){
    bool ret = false;
    edk::char8* str = edk::String::int32ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::uint64 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::uint64 value){
    bool ret = false;
    edk::char8* str = edk::String::uint64ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::int64 value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::int64 value){
    bool ret = false;
    edk::char8* str = edk::String::int64ToStr(value);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::float32 value,edk::uint32 digits){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::float32 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float32ToStr(value,digits);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::float64 value,edk::uint32 digits){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value,digits);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::float64 value,edk::uint32 digits){
    bool ret = false;
    edk::char8* str = edk::String::float64ToStr(value,digits);
    if(str){
        ret = this->addSelectedPreviousAttribute(name,str);
        free(str);
    }
    return ret;
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,const edk::char8* value){
    //
    return this->addSelectedPreviousAttribute((edk::char8*) name,(edk::char8*) value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,const edk::char8* value){
    return this->addSelectedPreviousAttribute(name,(edk::char8*) value);
}
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,edk::char8* value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,edk::char8* value){
    //test the selected
    if(*this->selected.name()){
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
bool edk::XML::addSelectedPreviousAttribute(const edk::char8* name,bool value){
    return this->addSelectedPreviousAttribute((edk::char8*) name,value);
}
bool edk::XML::addSelectedPreviousAttribute(edk::char8* name,bool value){
    return this->addSelectedPreviousAttribute(name,value?(edk::char8*)"true":(edk::char8*)"false");
}
//Add a new node to the root
bool edk::XML::addRootPreviousChild(const edk::char8* name){
    //
    return this->addRootPreviousChild((edk::char8*) name);
}
bool edk::XML::addRootPreviousChild(edk::char8* name){
    //test if have a first child in root
    if(!(*doc.first_child().name())){
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
bool edk::XML::addRootNextChild(const edk::char8* name){
    //
    return this->addRootNextChild((edk::char8*) name);
}
bool edk::XML::addRootNextChild(edk::char8* name){
    //test if have a first child in root
    if(!(*doc.first_child().name())){
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
bool edk::XML::deleteSelectedAttribute(const edk::char8* name){
    //
    return this->deleteSelectedAttribute((edk::char8*) name);
}
bool edk::XML::deleteSelectedAttribute(edk::char8* name){
    //test the selected and the name
    if(*this->selected.name() && name){
        //remove the attribute
        return this->selected.remove_attribute((char*)name);
    }
    //else return false
    return false;
}
//SELECTED SET
bool edk::XML::setSelectedString(const edk::char8* string){
    //
    return this->setSelectedString((edk::char8*) string);
}
bool edk::XML::setSelectedString(edk::char8* string){
    //test if have selected
    if(this->haveSelected()){
        //set the selected string
        if(this->selected.text().set((char*)string)){
            //
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::uint32 string){
    //test if have selected
    if(this->haveSelected()){
        //set the selected string
        if(this->selected.text().set(string)){
            //
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::int32 string){
    //test if have selected
    if(this->haveSelected()){
        //set the selected string
        if(this->selected.text().set(string)){
            //
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::uint64 string){
    //test if have selected
    if(this->haveSelected()){
        //we need to convert the int64 to string
        edk::char8* str = edk::String::uint64ToStr(string);
        if(str){
            bool ret = false;
            //set the selected string
            if(this->selected.text().set(str)){
                ret = true;
            }
            free(str);
            return ret;
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::int64 string){
    //test if have selected
    if(this->haveSelected()){
        //we need to convert the int64 to string
        edk::char8* str = edk::String::int64ToStr(string);
        if(str){
            bool ret = false;
            //set the selected string
            if(this->selected.text().set(str)){
                ret = true;
            }
            free(str);
            return ret;
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::float32 string,edk::uint32 digits){
    //test if have selected
    if(this->haveSelected()){
        //we need to convert the int64 to string
        edk::char8* str = edk::String::float32ToStr(string,digits);
        if(str){
            //set the selected string
            if(this->selected.text().set(str)){
                //
                free(str);
                return true;
            }
            free(str);
        }
    }
    //else return false
    return false;
}
bool edk::XML::setSelectedString(edk::float64 string,edk::uint32 digits){
    //test if have selected
    if(this->haveSelected()){
        //we need to convert the int64 to string
        edk::char8* str = edk::String::float64ToStr(string,digits);
        if(str){
            //set the selected string
            if(this->selected.text().set(str)){
                //
                free(str);
                return true;
            }
            free(str);
        }
    }
    //else return false
    return false;
}
//SELECTED GET
//return if have a selected
bool edk::XML::haveSelected(){
    //test if have a selected
    if(*this->selected.name()){
        return true;
    }
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
            return (edk::char8*)this->selected.text().as_string();
        }
    }
    //else return NULL
    return NULL;
}
edk::int32 edk::XML::getSelectedStringAsInt32(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_int();
        }
    }
    //else return NULL
    return 0;
}
edk::uint32 edk::XML::getSelectedStringAsUint32(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_uint();
        }
    }
    //else return NULL
    return 0;
}
edk::int64 edk::XML::getSelectedStringAsInt64(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_int();
        }
    }
    //else return NULL
    return 0;
}
edk::uint64 edk::XML::getSelectedStringAsUint64(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_uint();
        }
    }
    //else return NULL
    return 0;
}
edk::float32 edk::XML::getSelectedStringAsFloat32(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_float();
        }
    }
    //else return NULL
    return 0;
}
edk::float64 edk::XML::getSelectedStringAsFloat64(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_double();
        }
    }
    //else return NULL
    return 0;
}
bool edk::XML::getSelectedStringAsBool(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return this->selected.text().as_bool();
        }
    }
    //else return NULL
    return false;
}
//return the type of the selected string
edk::uint8 edk::XML::getSelectedStringType(){
    //test if habe a selectedNode
    if(this->haveSelected()){
        //test if have a text
        if(*this->selected.text()){
            //return the text
            return edk::XML::getStringType(this->selected.text().as_string());
        }
    }
    //else return NULL
    return EDK_XML_NULL;
}
//test if have the attribute
bool edk::XML::haveAttributeName(const edk::char8* name){
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
edk::int32 edk::XML::getSelectedAttributeValueAsInt32(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_int();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0;
}
edk::uint32 edk::XML::getSelectedAttributeValueAsUint32(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_uint();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0u;
}
edk::int64 edk::XML::getSelectedAttributeValueAsInt64(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_int();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0;
}
edk::uint64 edk::XML::getSelectedAttributeValueAsUint64(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_uint();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0u;
}
edk::float32 edk::XML::getSelectedAttributeValueAsFloat32(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_float();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0.f;
}
edk::float64 edk::XML::getSelectedAttributeValueAsFloat64(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_double();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return 0.0;
}
bool edk::XML::getSelectedAttributeValueAsBool(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return attr.as_bool();
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return false;
}
//return the attribute type
edk::uint8 edk::XML::getSelectedAttributeType(edk::uint32 id){
    //test if have a selected
    if(this->haveSelected()){
        //count the attributes
        edk::uint32 attributesCount=0u;
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if this is the ID
            if(id==attributesCount){
                //then find the attribute

                //return the attribute value
                return edk::XML::getStringType(attr.value());
            }
            //increment the attributesCount
            attributesCount++;
        }
    }
    //else return NULL
    return EDK_XML_NULL;
}
//return the value by the attribute name
edk::char8* edk::XML::getSelectedAttributeValueByName(const edk::char8* name){
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
edk::int32 edk::XML::getSelectedAttributeValueAsInt32ByName(const edk::char8* name){
    return getSelectedAttributeValueAsInt32ByName((edk::char8*) name);
}
edk::int32 edk::XML::getSelectedAttributeValueAsInt32ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_int();
            }
        }

    }
    //else return NULL
    return 0;
}
edk::uint32 edk::XML::getSelectedAttributeValueAsUint32ByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsUint32ByName((edk::char8*) name);
}
edk::uint32 edk::XML::getSelectedAttributeValueAsUint32ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_uint();
            }
        }

    }
    //else return NULL
    return 0u;
}
edk::int64 edk::XML::getSelectedAttributeValueAsInt64ByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsInt64ByName((edk::char8*) name);
}
edk::int64 edk::XML::getSelectedAttributeValueAsInt64ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_int();
            }
        }

    }
    //else return NULL
    return 0;
}
edk::uint64 edk::XML::getSelectedAttributeValueAsUint64ByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsUint64ByName((edk::char8*) name);
}
edk::uint64 edk::XML::getSelectedAttributeValueAsUint64ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_uint();
            }
        }

    }
    //else return NULL
    return 0u;
}
edk::float32 edk::XML::getSelectedAttributeValueAsFloat32ByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsFloat32ByName((edk::char8*) name);
}
edk::float32 edk::XML::getSelectedAttributeValueAsFloat32ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_float();
            }
        }

    }
    //else return NULL
    return 0.f;
}
edk::float64 edk::XML::getSelectedAttributeValueAsFloat64ByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsFloat64ByName((edk::char8*) name);
}
edk::float64 edk::XML::getSelectedAttributeValueAsFloat64ByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_double();
            }
        }

    }
    //else return NULL
    return 0.0;
}
bool edk::XML::getSelectedAttributeValueAsBoolByName(const edk::char8* name){
    return this->getSelectedAttributeValueAsBoolByName((edk::char8*) name);
}
bool edk::XML::getSelectedAttributeValueAsBoolByName(edk::char8* name){
    //test if have selected and if name is valid
    if(this->haveSelected() && name){
        //find the nameValue
        for(pugi::xml_attribute attr = this->selected.first_attribute(); *attr.name(); attr = attr.next_attribute()){
            //test if the name are equal
            if(edk::String::strCompare((edk::char8*)name,(edk::char8*)attr.name())){
                //find and return the value
                return attr.as_bool();
            }
        }

    }
    //else return NULL
    return false;
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

//COMPARE
bool edk::XML::compareSelectedName(edk::char8* compare){
    //test if have a selected
    if(this->haveSelected() && compare){
        //return the selectedName
        return edk::String::strCompare(compare,(edk::char8*)this->selected.name());
    }
    //else return NULL
    return false;
}
bool edk::XML::compareSelectedName(const edk::char8* compare){
    return this->compareSelectedName((edk::char8*) compare);
}


//Parser Virtual Functions
void edk::XML::didStartElement(edk::char8* name, edk::char8** attributes, edk::char8** values, edk::uint8* types, edk::uint32 attributesCount){
    //test if have the name
    if(name){
        //
        //        printf("\nDid Start Element '%s'"
        //               ,name
        //               );

        //test the attributes
        for(edk::uint32 i=0u;i<attributesCount;i++){
            //
            if(attributes[i] && values[i] && types[i]){
                //                printf("\n    count %u attribute '%s' value '%s'"
                //                       ,i
                //                       ,attributes[i]
                //                       ,values[i]
                //                       );
                //                switch(types[i]){
                //                case EDK_XML_NULL:
                //                    printf(" type NULL");
                //                    break;
                //                case EDK_XML_UINT:
                //                    printf(" type UINT");
                //                    break;
                //                case EDK_XML_INT:
                //                    printf(" type INT");
                //                    break;
                //                case EDK_XML_DOUBLE:
                //                    printf(" type DOUBLE");
                //                    break;
                //                case EDK_XML_STRING:
                //                    printf(" type STRING");
                //                    break;
                //                case EDK_XML_BOOL:
                //                    printf(" type BOOL");
                //                    break;
                //                }
            }
        }
    }
}
void edk::XML::foundCharacters(edk::char8* name,edk::char8* string,edk::uint8){
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
    if(name){
        if(this->doc.append_child((char*)name)){
            return true;
        }
    }
    return ret;
}
