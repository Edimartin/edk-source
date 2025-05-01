#include "FileOBJ.h"

edk::shape::FileOBJ::StackVertex::StackVertex(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::FileOBJ::StackVertex::~StackVertex(){
    this->Destructor();
}

void edk::shape::FileOBJ::StackVertex::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
    }
}
void edk::shape::FileOBJ::StackVertex::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanVertexes();
    }
}

//clean all vertexes
void edk::shape::FileOBJ::StackVertex::cleanVertexes(){
    edk::uint32 size=this->stack.size();
    edk::shape::FileOBJ::MeshVertex* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            delete temp;
        }
    }
    this->stack.clean();
}
//get the size of the vertexes
edk::uint32 edk::shape::FileOBJ::StackVertex::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::FileOBJ::StackVertex::getSize(){
    return this->stack.size();
}

//create a new vertex in to the stack
edk::uint32 edk::shape::FileOBJ::StackVertex::newVertex(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->newVertex(x,y,z,1.f,1.f,1.f,1.f);
}
edk::uint32 edk::shape::FileOBJ::StackVertex::newVertex(edk::float32 x,
                                                        edk::float32 y,
                                                        edk::float32 z,
                                                        edk::float32 r,
                                                        edk::float32 g,
                                                        edk::float32 b
                                                        ){
    return this->newVertex(x,y,z,r,g,b,1.f);
}
edk::uint32 edk::shape::FileOBJ::StackVertex::newVertex(edk::float32 x,
                                                        edk::float32 y,
                                                        edk::float32 z,
                                                        edk::float32 r,
                                                        edk::float32 g,
                                                        edk::float32 b,
                                                        edk::float32 a
                                                        ){
    edk::shape::FileOBJ::MeshVertex* vert = new edk::shape::FileOBJ::MeshVertex;
    if(vert){
        vert->vertex.position.x = x;
        vert->vertex.position.y = y;
        vert->vertex.position.z = z;
        vert->vertex.color.r = r;
        vert->vertex.color.g = g;
        vert->vertex.color.b = b;
        vert->vertex.color.a = a;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::FileOBJ::StackVertex::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->newVertex(position.x,position.y,position.z,color.r,color.g,color.b,color.a);
}
edk::uint32 edk::shape::FileOBJ::StackVertex::newVertex(edk::shape::Vertex3D vert){
    return this->newVertex(vert.position.x,vert.position.y,vert.position.z,vert.color.r,vert.color.g,vert.color.b,vert.color.a);
}
edk::shape::Vertex3D* edk::shape::FileOBJ::StackVertex::getVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshVertex* temp = this->stack.get(position);
        if(temp){
            return temp->pointer;
        }
    }
    return NULL;
}
bool edk::shape::FileOBJ::StackVertex::haveVertex(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::FileOBJ::StackVertex::deleteVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshVertex* temp = this->stack.get(position);
        if(temp){
            if(this->stack.remove(position)){
                delete temp;
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackVertex::incrementVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshVertex* temp = this->stack.get(position);
        if(temp){
            temp->incrementUse();
            return true;
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackVertex::decrementVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshVertex* temp = this->stack.get(position);
        if(temp){
            return temp->decrementUse();
        }
    }
    return false;
}

edk::shape::FileOBJ::StackNormal::StackNormal(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::FileOBJ::StackNormal::~StackNormal(){
    this->Destructor();
}

void edk::shape::FileOBJ::StackNormal::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
    }
}

void edk::shape::FileOBJ::StackNormal::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanNormals();
    }
}

//clean all normals
void edk::shape::FileOBJ::StackNormal::cleanNormals(){
    edk::uint32 size=this->stack.size();
    edk::shape::FileOBJ::MeshNormal* temp;
    for(edk::uint32 i=0u;i<size;i++){
        if(this->stack.havePos(i)){
            temp = this->stack.get(i);
            if(temp){
                delete temp;
            }
        }
    }
    this->stack.clean();
}
//get the size of the normals
edk::uint32 edk::shape::FileOBJ::StackNormal::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::FileOBJ::StackNormal::getSize(){
    return this->stack.size();
}

//create a new normals in to the stack
edk::uint32 edk::shape::FileOBJ::StackNormal::newNormal(edk::float32 x,
                                                        edk::float32 y,
                                                        edk::float32 z
                                                        ){
    edk::shape::FileOBJ::MeshNormal* vert = new edk::shape::FileOBJ::MeshNormal;
    if(vert){
        vert->normal.x = x;
        vert->normal.y = y;
        vert->normal.z = z;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::FileOBJ::StackNormal::newNormal(edk::vec3f32 position){
    return this->newNormal(position.x,position.y,position.z);
}
edk::uint32 edk::shape::FileOBJ::StackNormal::newNormal(edk::shape::Vector3D vert){
    return this->newNormal(vert.x,vert.y,vert.z);
}
edk::shape::Vector3D* edk::shape::FileOBJ::StackNormal::getNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshNormal* temp = this->stack.get(position);
        if(temp){
            return temp->pointer;
        }
    }
    return NULL;
}
bool edk::shape::FileOBJ::StackNormal::haveNormal(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::FileOBJ::StackNormal::deleteNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshNormal* temp = this->stack.get(position);
        if(temp){
            if(this->stack.remove(position)){
                delete temp;
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackNormal::incrementNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshNormal* temp = this->stack.get(position);
        if(temp){
            temp->incrementUse();
            return true;
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackNormal::decrementNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshNormal* temp = this->stack.get(position);
        if(temp){
            return temp->decrementUse();
        }
    }
    return false;
}

edk::shape::FileOBJ::StackUV::StackUV(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::FileOBJ::StackUV::~StackUV(){
    this->Destructor();
}

void edk::shape::FileOBJ::StackUV::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
    }
}
void edk::shape::FileOBJ::StackUV::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanUVS();
    }
}

//clean all uvs
void edk::shape::FileOBJ::StackUV::cleanUVS(){
    edk::uint32 size=this->stack.size();
    edk::shape::FileOBJ::MeshUV* temp;
    for(edk::uint32 i=0u;i<size;i++){
        if(this->stack.havePos(i)){
            temp = this->stack.get(i);
            if(temp){
                delete temp;
            }
        }
    }
    this->stack.clean();
}
//get the size of the uvs
edk::uint32 edk::shape::FileOBJ::StackUV::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::FileOBJ::StackUV::getSize(){
    return this->stack.size();
}

//create a new uv in to the stack
edk::uint32 edk::shape::FileOBJ::StackUV::newUV(edk::float32 u,
                                                edk::float32 v
                                                ){
    edk::shape::FileOBJ::MeshUV* vert = new edk::shape::FileOBJ::MeshUV;
    if(vert){
        vert->uv.u = u;
        vert->uv.v = v;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::FileOBJ::StackUV::newUV(edk::vec2f32 position){
    return this->newUV(position.x,position.y);
}
edk::uint32 edk::shape::FileOBJ::StackUV::newUV(edk::shape::UV2D vert){
    return this->newUV(vert.u,vert.v);
}
edk::shape::UV2D* edk::shape::FileOBJ::StackUV::getUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshUV* temp = this->stack.get(position);
        if(temp){
            return temp->pointer;
        }
    }
    return NULL;
}
bool edk::shape::FileOBJ::StackUV::haveUV(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::FileOBJ::StackUV::deleteUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshUV* temp = this->stack.get(position);
        if(temp){
            if(this->stack.remove(position)){
                delete temp;
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackUV::incrementUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshUV* temp = this->stack.get(position);
        if(temp){
            temp->incrementUse();
            return true;
        }
    }
    return false;
}
bool edk::shape::FileOBJ::StackUV::decrementUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::FileOBJ::MeshUV* temp = this->stack.get(position);
        if(temp){
            return temp->decrementUse();
        }
    }
    return false;
}

edk::shape::FileOBJ::StackPolygons::StackPolygons(){
    this->classThis=NULL;
    this->Constructor(false);
}
edk::shape::FileOBJ::StackPolygons::~StackPolygons(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanPolygons();
    }
}

void edk::shape::FileOBJ::StackPolygons::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->polygonSelected=NULL;
        this->idPolygon=0u;

        this->stack.Constructor();
    }
}

void edk::shape::FileOBJ::StackPolygons::cleanPolygons(){
    edk::uint32 size = this->stack.size();
    edk::shape::FileOBJ::MeshPolygon* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            delete temp;
        }
    }
    this->stack.clean();
}
//add a new polygon
bool edk::shape::FileOBJ::StackPolygons::newPolygon(){
    edk::shape::FileOBJ::MeshPolygon* temp = new edk::shape::FileOBJ::MeshPolygon;
    if(temp){
        edk::uint32 size = this->stack.size();
        this->stack.pushBack(temp);
        if(size<this->stack.size()){
            this->polygonSelected = temp;
            this->idPolygon=size;
            return true;
        }
        delete temp;
    }
    return false;
}
edk::uint32 edk::shape::FileOBJ::StackPolygons::getSize(){
    return this->stack.size();
}
edk::uint32 edk::shape::FileOBJ::StackPolygons::size(){
    return this->stack.size();
}
bool edk::shape::FileOBJ::StackPolygons::havePolygon(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::FileOBJ::StackPolygons::selectPolygon(edk::uint32 position){
    this->polygonSelected = this->stack.get(position);
    if(this->polygonSelected){
        return true;
    }
    return false;
}
bool edk::shape::FileOBJ::StackPolygons::selectedAddVertex(edk::shape::FileOBJ::MeshVertex* vertex){
    if(this->polygonSelected){
        edk::uint32 size = this->polygonSelected->vertexes.size();
        this->polygonSelected->vertexes.pushBack(vertex);
        if(size<this->polygonSelected->vertexes.size()){
            return true;
        }
    }
    return false;
}


edk::shape::FileOBJ::TreeMaterials::TreeMaterials(){
    this->classThis=NULL;
    this->Constructor(false);
}
edk::shape::FileOBJ::TreeMaterials::~TreeMaterials(){
    if(this->classThis==this){
        this->classThis=NULL;

        this->cleanMaterials();
    }
}

void edk::shape::FileOBJ::TreeMaterials::Constructor(bool runFather){
    if(runFather){
        edk::vector::NameTree::Constructor();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->unselectMaterial();
    }
}

//clean all materials
void edk::shape::FileOBJ::TreeMaterials::cleanMaterials(){
    this->selected=NULL;
    edk::uint32 size = this->size();
    edk::shape::FileOBJ::MeshMaterial* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::shape::FileOBJ::MeshMaterial*)this->getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    this->clean();
}
bool edk::shape::FileOBJ::TreeMaterials::newMaterial(const edk::char8* name){
    return this->newMaterial((edk::char8*) name);
}
bool edk::shape::FileOBJ::TreeMaterials::newMaterial(edk::char8* name){
    if(name){
        //get the material by name
        edk::shape::FileOBJ::MeshMaterial* temp = (edk::shape::FileOBJ::MeshMaterial*)this->getElementByName(name);
        if(!temp){
            temp=new edk::shape::FileOBJ::MeshMaterial;
            if(temp){
                if(temp->setName(name)){
                    if(this->add(temp)){
                        //select the material
                        this->selected = &temp->material;
                        return true;
                    }
                }
                delete temp;
            }
        }
    }
    return false;
}
bool edk::shape::FileOBJ::TreeMaterials::selectMaterialByName(const edk::char8* name){
    return this->selectMaterialByName((edk::char8*) name);
}
bool edk::shape::FileOBJ::TreeMaterials::selectMaterialByName(edk::char8* name){
    this->selected=NULL;
    if(name){
        edk::shape::FileOBJ::MeshMaterial* temp = (edk::shape::FileOBJ::MeshMaterial*)this->getElementByName(name);
        if(temp){
            this->selected=&temp->material;
            return true;
        }
    }
    return false;
}
void edk::shape::FileOBJ::TreeMaterials::unselectMaterial(){
    this->selected=NULL;
}
edk::material::Material* edk::shape::FileOBJ::TreeMaterials::getMaterialInPosition(edk::uint32 position){
    edk::shape::FileOBJ::MeshMaterial* temp = (edk::shape::FileOBJ::MeshMaterial*)this->getElementInPosition(position);
    if(temp){
        return &temp->material;
    }
    return NULL;
}
edk::material::Material* edk::shape::FileOBJ::TreeMaterials::getMaterialByName(edk::char8* name){
    edk::shape::FileOBJ::MeshMaterial* temp = (edk::shape::FileOBJ::MeshMaterial*)this->getElementByName(name);
    if(temp){
        return &temp->material;
    }
    return NULL;
}
edk::material::Material* edk::shape::FileOBJ::TreeMaterials::getMaterialByName(const edk::char8* name){
    return this->getMaterialByName((edk::char8*) name);
}

edk::shape::FileOBJ::FileOBJ(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::FileOBJ::~FileOBJ(){
    this->Destructor();
}

void edk::shape::FileOBJ::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

    }
}
void edk::shape::FileOBJ::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->materials.cleanMaterials();
        this->polygons.cleanPolygons();
        this->uvs.cleanUVS();
        this->normals.cleanNormals();
        this->vertexes.cleanVertexes();
    }
}

//load the mtlFile
bool edk::shape::FileOBJ::loadMTL(const edk::char8* fileName,edk::shape::FileOBJ::TreeMaterials* materials){
    return this->loadMTL((edk::char8*) fileName,materials);
}
bool edk::shape::FileOBJ::loadMTL(edk::char8* fileName,edk::shape::FileOBJ::TreeMaterials* materials){
    if(fileName && materials){
        //open the file
        edk::File file;
        if(file.openTextFile(fileName)){
            edk::char8 c;
            edk::char8* str;
            edk::char8* temp;
            //edk::int32 illum=0u;

            edk::float32 Ns=0.f;
            //edk::float32 Ni=0.f;

            edk::color3f32 Ka,Kd,Ks,Ke;
            edk::Name mapKd,mapBump,mapKa;

            //edk::float32 dValue=0.f;

            edk::char8* folder = edk::String::strFolderName(fileName);


            edk::char8* limits = (edk::char8*)malloc(3u);
            if(limits){
                limits[0u]=13u;
                limits[1u]=10u;
                limits[2u]=0u;
                while(!file.endOfFile()){
                    c = file.readTextChar();
                    switch(c){
                    case '#':
                        //comentario
                        str = file.readTextString(limits,false);
                        if(str){
                            free(str);
                        }
                        //printf("\nComentario");fflush(stdout);
                        break;
                    case 'n':
                        //newmtl - name of the material
                        if(file.readTextChar() == 'e'){
                            if(file.readTextChar() == 'w'){
                                if(file.readTextChar() == 'm'){
                                    if(file.readTextChar() == 't'){
                                        if(file.readTextChar() == 'l'){
                                            if(file.readTextChar() == ' '){
                                                //find the material name
                                                str = file.readTextString(limits,false);
                                                if(str){

                                                    //test if aready have a material
                                                    if(materials->selected){
                                                        //copy the values for the material
                                                        materials->selected->loadTexture(mapKd.getName(),0u);
                                                        materials->selected->loadTexture(mapKa.getName(),1u);
                                                        materials->selected->loadTexture(mapBump.getName(),2u);
                                                        materials->selected->setAmbient(Ka);
                                                        materials->selected->setDiffuse(Kd);
                                                        materials->selected->setSpecular(Ks);
                                                        materials->selected->setEmission(Ke);
                                                        materials->selected->setShininess(Ns);
                                                        materials->unselectMaterial();
                                                    }

                                                    //printf("\nNEW Material name == '%s'",str);fflush(stdout);
                                                    materials->newMaterial(str);

                                                    free(str);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;

                    case 'i':
                        //illum
                        if(file.readTextChar() == 'l'){
                            if(file.readTextChar() == 'l'){
                                if(file.readTextChar() == 'u'){
                                    if(file.readTextChar() == 'm'){
                                        if(file.readTextChar() == ' '){
                                            //read the ilum value
                                            str = file.readTextString(limits,false);
                                            if(str){
                                                //illum = edk::String::strToInt32(str);
                                                //printf("\nIllum == '%s' [%d]",str,illum);fflush(stdout);
                                                free(str);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    case 'N':
                        //Ns
                        if(file.readTextChar() == 's'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    Ns = edk::String::strToFloat32(str);
                                    //printf("\nNs == '%s' [%.2f]",str,Ns);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        else if(file.readTextChar() == 'i'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    //Ni = edk::String::strToFloat32(str);
                                    //printf("\nNi == '%s' [%.2f]",str,Ni);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        break;
                    case 'd':
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString(limits,false);
                            if(str){
                                //dValue = edk::String::strToFloat32(str);
                                //printf("\nd == '%s' [%.2f]",str,dValue);fflush(stdout);
                                free(str);
                            }
                        }
                        break;
                    case 'K':
                        c = file.readTextChar();
                        //Ka
                        if(c == 'a'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    temp = str;
                                    if(*temp){
                                        Ka.r = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ka.g = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ka.b = edk::String::strToFloat32(temp);
                                    }
                                    //printf("\nKa == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ka.r,Ka.g,Ka.b);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        //Kd
                        else if(c == 'd'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    temp = str;
                                    if(*temp){
                                        Kd.r = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Kd.g = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Kd.b = edk::String::strToFloat32(temp);
                                    }
                                    //printf("\nKd == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Kd.r,Kd.g,Kd.b);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        //Ks
                        else if(c == 's'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    temp = str;
                                    if(*temp){
                                        Ks.r = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ks.g = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ks.b = edk::String::strToFloat32(temp);
                                    }
                                    //printf("\nKs == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ks.r,Ks.g,Ks.b);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        //Ke
                        else if(c == 'e'){
                            if(file.readTextChar() == ' '){
                                //read the ilum value
                                str = file.readTextString(limits,false);
                                if(str){
                                    temp = str;
                                    if(*temp){
                                        Ke.r = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ke.g = edk::String::strToFloat32(temp);
                                    }
                                    //search for the ' ';
                                    while(*temp){
                                        if(*temp==' '){
                                            temp++;
                                            break;
                                        }
                                        temp++;
                                    }
                                    if(*temp){
                                        Ke.b = edk::String::strToFloat32(temp);
                                    }
                                    //printf("\nKe == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ke.r,Ke.g,Ke.b);fflush(stdout);
                                    free(str);
                                }
                            }
                        }
                        break;
                    case 'm':
                        //textures
                        if(file.readTextChar() == 'a'){
                            if(file.readTextChar() == 'p'){
                                if(file.readTextChar() == '_'){
                                    c = file.readTextChar();
                                    if(c == 'K'){
                                        c = file.readTextChar();
                                        if(c == 'd'){
                                            if(file.readTextChar() == ' '){
                                                //texture Kd
                                                str = file.readTextString(limits,false);
                                                if(str){
                                                    if(folder){
                                                        temp = edk::String::strCatMulti(folder,str,NULL);
                                                        if(temp){
                                                            mapKd.setName(temp);
                                                            //printf("\nTexture Kd == '%s' == '%s'",temp,mapKd.getName());fflush(stdout);
                                                            free(temp);
                                                        }
                                                    }
                                                    else{
                                                        mapKd.setName(str);
                                                        //printf("\nTexture Kd == '%s' == '%s'",str,mapKd.getName());fflush(stdout);
                                                    }
                                                    free(str);
                                                }
                                            }
                                        }
                                        else if(c == 'a'){
                                            if(file.readTextChar() == ' '){
                                                //texture Ka
                                                str = file.readTextString(limits,false);
                                                if(str){
                                                    if(folder){
                                                        temp = edk::String::strCatMulti(folder,str,NULL);
                                                        if(temp){
                                                            mapKa.setName(temp);
                                                            //printf("\nTexture Ka == '%s' == '%s'",temp,mapKa.getName());fflush(stdout);
                                                            free(temp);
                                                        }
                                                    }
                                                    else{
                                                        mapKa.setName(str);
                                                        //printf("\nTexture Ka == '%s' == '%s'",str,mapKa.getName());fflush(stdout);
                                                    }
                                                    free(str);
                                                }
                                            }
                                        }
                                    }
                                    else if(c == 'B'){
                                        if(file.readTextChar() == 'u'){
                                            if(file.readTextChar() == 'm'){
                                                if(file.readTextChar() == 'p'){
                                                    if(file.readTextChar() == ' '){
                                                        //texture bumpMap
                                                        str = file.readTextString(limits,false);
                                                        if(str){
                                                            if(folder){
                                                                temp = edk::String::strCatMulti(folder,str,NULL);
                                                                if(temp){
                                                                    mapBump.setName(temp);
                                                                    //printf("\nTexture Bump == '%s' == '%s'",temp,mapBump.getName());fflush(stdout);
                                                                    free(temp);
                                                                }
                                                            }
                                                            else{
                                                                mapBump.setName(str);
                                                                //printf("\nTexture Bump == '%s' == '%s'",str,mapBump.getName());fflush(stdout);
                                                            }
                                                            free(str);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                free(limits);
            }
            if(folder){
                free(folder);
            }
            materials->selected->loadTexture(mapKd.getName(),0u);
            materials->selected->loadTexture(mapKa.getName(),1u);
            materials->selected->loadTexture(mapBump.getName(),2u);
            materials->selected->setAmbient(Ka);
            materials->selected->setDiffuse(Kd);
            materials->selected->setSpecular(Ks);
            materials->selected->setEmission(Ke);
            materials->selected->setShininess(Ns);

            file.closeFile();
            return true;
        }
    }
    return false;
}


//OBJ
bool edk::shape::FileOBJ::objAddFile(const edk::char8* fileName){
    return this->objAddFile((edk::char8*) fileName);
}
bool edk::shape::FileOBJ::objAddFile(edk::char8* fileName){
    this->vertexes.cleanVertexes();
    this->uvs.cleanUVS();
    this->normals.cleanNormals();
    this->materials.cleanMaterials();
    if(fileName){
        edk::uint32 sizeName = edk::String::strSize(fileName);
        if(sizeName){
            //open the file
            edk::File file;

            edk::char8* newFileName = NULL;

            edk::char8* limits = (edk::char8*)malloc(3u);
            if(limits){
                limits[0u]=13u;
                limits[1u]=10u;
                limits[2u]=0u;

                //test if the fileName have the .obj in the end
                //printf("\nFilename == '%s'",fileName);fflush(stdout);
                if(edk::String::strHaveInsideEnd(fileName,".obj")){
                    //just copy the name
                    newFileName = edk::String::strCopy(fileName);
                }
                else{
                    //concat the name
                    if(fileName[sizeName-1u]=='.'){
                        newFileName = edk::String::strCatMulti(fileName,"obj",NULL);
                    }
                    else{
                        newFileName = edk::String::strCatMulti(fileName,".obj",NULL);
                    }
                }

                if(file.openTextFile(newFileName)){
                    bool ret = true;
                    edk::char8 c;
                    edk::char8* str;
                    edk::char8* temp;
                    edk::char8* ve;
                    edk::uint8 read;
                    edk::uint32 v,n,p;
                    edk::float32 x,y,z;
                    edk::shape::Polygon3D poly;

                    edk::shape::Vertex3D* vert=NULL;
                    edk::shape::Vector3D* norm=NULL;
                    edk::shape::UV2D* uvVert=NULL;

                    edk::vector::Stack<edk::uint32> sv(1000u),sp(1000u),sn(1000u);

                    edk::shape::Mesh3D* mesh = NULL;
                    //bool smooth = false;
                    edk::uint32 countMeshes = 0u;

                    edk::char8* folder = edk::String::strFolderName(newFileName);

                    while(!file.endOfFile()){
                        c = file.readTextChar();
                        switch(c){
                        case '#':
                            //comentario
                            str = file.readTextString(limits,false);
                            if(str){
                                free(str);
                            }
                            //printf("\nComentario");
                            break;
                            //mtllib cubes.mtl
                        case 'm':
                            if(file.readTextChar() == 't'){
                                if(file.readTextChar() == 'l'){
                                    if(file.readTextChar() == 'l'){
                                        if(file.readTextChar() == 'i'){
                                            if(file.readTextChar() == 'b'){
                                                if(file.readTextChar() == ' '){
                                                    //readthe mtlFile
                                                    str = file.readTextString(limits,false);
                                                    if(str){
                                                        //test if have the folder
                                                        if(folder){
                                                            //concat to generate the mtl new name
                                                            temp = edk::String::strCatMulti(folder,str,NULL);
                                                            if(temp){
                                                                //printf("\nTry load MTL == '%s'",temp);fflush(stdout);

                                                                if(this->loadMTL(temp,&this->materials)){
                                                                    //printf("\nMTL LIB == '%s'",temp);fflush(stdout);
                                                                }
                                                                else{
                                                                    //printf("\nERROR: Can't load MTL == '%s'",temp);fflush(stdout);
                                                                }

                                                                free(temp);
                                                            }
                                                        }
                                                        else{
                                                            //printf("\nTry load MTL == '%s'",str);fflush(stdout);

                                                            if(this->loadMTL(str,&this->materials)){
                                                                //printf("\nMTL LIB == '%s'",str);fflush(stdout);
                                                            }
                                                            else{
                                                                //printf("\nERROR: Can't load MTL == '%s'",str);fflush(stdout);
                                                            }

                                                        }
                                                        free(str);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 'o':
                            //Object
                            if(file.readTextChar() == ' '){
                                str = file.readTextString(limits,false);
                                if(str){
                                    //printf("\nNEW OBJECT NAME == '%s'",str);fflush(stdout);
                                    free(str);

                                    mesh=this->allocMeshForOBJ();
                                    if(mesh){
                                        countMeshes++;
                                    }
                                }
                            }
                            break;
                        case 'g':
                            //Group
                            str = file.readTextString(limits,false);
                            if(str){
                                free(str);
                            }
                            break;
                        case 'v':
                            if(!mesh){
                                mesh=this->allocMeshForOBJ();
                                if(mesh){
                                    countMeshes++;
                                }
                            }
                            c = file.readTextChar();
                            if(c == ' '){
                                //read the entire phrase
                                str = file.readTextString(limits,false);
                                if(str){
                                    if(edk::String::strSize(str)){
                                        //printf("\nStr == '%s'",str);fflush(stdout);
                                        edk::uint8 pos=1u;
                                        temp = str;
                                        while(*temp){
                                            if(*temp!=' '){
                                                switch(pos){
                                                case 1u:
                                                    //read the value
                                                    x = edk::String::strToFloat32(temp);
                                                    pos++;
                                                    break;
                                                case 2u:
                                                    //read the value
                                                    y = edk::String::strToFloat32(temp);
                                                    pos++;
                                                    break;
                                                case 3u:
                                                    //read the value
                                                    z = edk::String::strToFloat32(temp);
                                                    pos++;
                                                    break;
                                                }
                                                //search for the next space ' '
                                                while(*temp){
                                                    if(*temp==' '){
                                                        break;
                                                    }
                                                    temp++;
                                                }
                                            }
                                            else{
                                                temp++;
                                            }
                                        }
                                    }
                                    free(str);
                                }
                                //printf("\nNEW Vertex %.2f %.2f %.2f",x,y,z);fflush(stdout);
                                this->vertexes.newVertex(x,y,z,1,1,1,1);
                            }
                            else if(c == 't'){
                                if(file.readTextChar() == ' '){
                                    //read the entire phrase
                                    str = file.readTextString(limits,false);
                                    if(str){
                                        if(edk::String::strSize(str)){
                                            //printf("\nStr == '%s'",str);fflush(stdout);
                                            edk::uint8 pos=1u;
                                            temp = str;
                                            while(*temp){
                                                if(*temp!=' '){
                                                    switch(pos){
                                                    case 1u:
                                                        //read the value
                                                        x = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    case 2u:
                                                        //read the value
                                                        y = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    case 3u:
                                                        //read the value
                                                        z = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    }
                                                    //search for the next space ' '
                                                    while(*temp){
                                                        if(*temp==' '){
                                                            break;
                                                        }
                                                        temp++;
                                                    }
                                                }
                                                else{
                                                    temp++;
                                                }
                                            }
                                        }
                                        free(str);
                                    }
                                    //printf("\nNEW Vertex Texture %.2f %.2f",x,y);
                                    this->uvs.newUV(x,y);
                                }
                            }
                            else if(c == 'n'){
                                if(file.readTextChar() == ' '){
                                    //read the entire phrase
                                    str = file.readTextString(limits,false);
                                    if(str){
                                        if(edk::String::strSize(str)){
                                            //printf("\nStr == '%s'",str);fflush(stdout);
                                            edk::uint8 pos=1u;
                                            temp = str;
                                            while(*temp){
                                                if(*temp!=' '){
                                                    switch(pos){
                                                    case 1u:
                                                        //read the value
                                                        x = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    case 2u:
                                                        //read the value
                                                        y = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    case 3u:
                                                        //read the value
                                                        z = edk::String::strToFloat32(temp);
                                                        pos++;
                                                        break;
                                                    }
                                                    //search for the next space ' '
                                                    while(*temp){
                                                        if(*temp==' '){
                                                            break;
                                                        }
                                                        temp++;
                                                    }
                                                }
                                                else{
                                                    temp++;
                                                }
                                            }
                                        }
                                        free(str);
                                    }
                                    //printf("\nNEW Vertex Normal %.2f %.2f %.2f",x,y,z);fflush(stdout);
                                    this->normals.newNormal(x,y,z);
                                }
                            }
                            break;
                        case 's':
                            if(!mesh){
                                mesh=this->allocMeshForOBJ();
                                if(mesh){
                                    countMeshes++;
                                }
                            }
                            if(file.readTextChar() == ' '){
                                str = file.readTextString(limits,false);
                                if(str){
                                    if(str[0u]=='o'){
                                        if(str[1u]=='f'){
                                            if(str[2u]=='f'){
                                                //
                                                //printf("\nSMOOTH FALSE '%s'",str);
                                                //smooth=false;
                                            }
                                        }
                                    }
                                    else if(str[0u]=='0'){
                                        //
                                        //printf("\nSMOOTH FALSE '%s'",str);
                                        //smooth=false;
                                    }
                                    else if(str[0u]=='1'){
                                        //
                                        //printf("\nSMOOTH TRUE '%s'",str);
                                        //smooth=true;
                                    }
                                    free(str);
                                }
                            }
                            else{
                                str = file.readTextString(limits,false);
                                if(str){
                                    free(str);
                                }
                            }
                            break;
                        case 'f':
                            if(!mesh){
                                mesh=this->allocMeshForOBJ();
                                if(mesh){
                                    countMeshes++;
                                }
                            }
                            if(file.readTextChar() == ' '){
                                //
                                str = file.readTextString(limits,true);
                                if(str){
                                    ve = temp = str;
                                    read = 0u;
                                    v=p=n=0u;
                                    //printf("\n");

                                    //printf("\nTEMP == '%s'",temp);fflush(stdout);


                                    while(*temp){
                                        switch(*temp){
                                        case '/':
                                            //set the end of the string
                                            *temp = '\0';
                                            if(ve<temp){
                                                switch(read){
                                                case 0u:
                                                    v = edk::String::strToInt64(ve);
                                                    break;
                                                case 1u:
                                                    p = edk::String::strToInt64(ve);
                                                    break;
                                                case 2u:
                                                    n = edk::String::strToInt64(ve);
                                                    break;
                                                }
                                            }
                                            *temp = '/';
                                            //
                                            switch(read){
                                            case 0u:
                                                read = 1u;
                                                break;
                                            case 1u:
                                                read = 2u;
                                                break;
                                            case 2u:
                                                read = 3u;
                                                break;
                                            }


                                            ve = temp+1u;
                                            break;
                                        case ' ':
                                        case '\n':
                                            *temp = '\0';
                                            if(ve<temp){
                                                switch(read){
                                                case 0u:
                                                    v = edk::String::strToInt64(ve);
                                                    read = 1u;
                                                    break;
                                                case 1u:
                                                    p = edk::String::strToInt64(ve);
                                                    read = 2u;
                                                    break;
                                                case 2u:
                                                    n = edk::String::strToInt64(ve);
                                                    read = 3u;
                                                    break;
                                                }


                                                switch(read){
                                                case 1u:

                                                    //printf(" Face %u",v);
                                                    if(v){
                                                        sv.pushBack(v);
                                                        sp.pushBack(0u);
                                                        sn.pushBack(0u);
                                                    }
                                                    break;
                                                case 2u:

                                                    //printf(" Face %u/%u",v,p);
                                                    if(v){
                                                        sv.pushBack(v);
                                                        sp.pushBack(p);
                                                        sn.pushBack(0u);
                                                    }
                                                    break;
                                                case 3u:

                                                    //printf(" Face %u/%u/%u",v,p,n);
                                                    if(v){
                                                        sv.pushBack(v);
                                                        sp.pushBack(p);
                                                        sn.pushBack(n);
                                                    }
                                                    break;
                                                }
                                                v=p=n=0u;
                                                read=0u;
                                            }
                                            *temp = ' ';

                                            ve = temp+1u;
                                            break;
                                        default:
                                            break;
                                        }

                                        temp++;
                                    }

                                    edk::uint32 size = sv.size();
                                    if(size){
                                        //printf("\nNEW FACE size[%u]",size);fflush(stdout);

                                        //create a new polygon
                                        poly.clean();
                                        if(poly.createPolygon(size)){
                                            //
                                            /*
                                    mesh->selectedPolygonSetSmooth(smooth);
                                    if(smooth){
                                        mesh->selectedPolygonUpdateNormal();
                                    }
                                    else{
                                        mesh->selectedPolygonSetNormalFlat(mesh->getNormal(sn.get(0u)-1u-countN));
                                    }


                                    edk::shape::Vertex3D* vert=NULL;
                                    edk::shape::Vertex3D* norm=NULL;
                                    edk::shape::UV2D* uvVert=NULL;
                                    */
                                            for(edk::uint32 i=0u;i<size;i++){
                                                v = sv.get(i);
                                                p = sp.get(i);
                                                n = sn.get(i);
                                                //printf(" %u/%u/%u",v,p,n);fflush(stdout);
                                                if(v){
                                                    vert = this->vertexes.getVertex(v-1u);
                                                    if(vert){
                                                        poly.setVertexPosition(i,vert->position.x,vert->position.y,vert->position.z);
                                                    }
                                                    if(p){
                                                        uvVert = this->uvs.getUV(p-1u);
                                                        if(uvVert){
                                                            poly.setVertexUV(i,uvVert->u,uvVert->v);
                                                        }
                                                        if(n){
                                                            norm = this->normals.getNormal(n-1u);
                                                            if(norm){
                                                                poly.setVertexNormal(i,norm->x,norm->y,norm->z);
                                                            }
                                                        }
                                                    }
                                                    else{
                                                        if(n){
                                                            norm = this->normals.getNormal(n-1u);
                                                            if(norm){
                                                                poly.setVertexNormal(i,norm->x,norm->y,norm->z);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }

                                        //add the polygon into the mesh
                                        mesh->triangularizateFromPolygon(poly);
                                        //mesh->addPolygon(poly);
                                    }

                                    sv.clean();
                                    sp.clean();
                                    sn.clean();

                                    free(str);
                                }
                            }
                            else{
                                str = file.readTextString(limits,false);
                                if(str){
                                    free(str);
                                }
                            }
                            break;
                        case 'u':
                            if(file.readTextChar() == 's'){
                                if(file.readTextChar() == 'e'){
                                    if(file.readTextChar() == 'm'){
                                        if(file.readTextChar() == 't'){
                                            if(file.readTextChar() == 'l'){
                                                if(file.readTextChar() == ' '){
                                                    //readthe mtlFile
                                                    str = file.readTextString(limits,false);
                                                    if(str){
                                                        //printf("\nUSE MTL == '%s'",str);
                                                        if(mesh){
                                                            //set the material
                                                            mesh->material.cloneFrom(this->materials.getMaterialByName(str));
                                                        }
                                                        free(str);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                    }
                    if(folder){
                        free(folder);
                    }

                    file.closeFile();

                    this->vertexes.cleanVertexes();
                    this->uvs.cleanUVS();
                    this->normals.cleanNormals();
                    this->materials.cleanMaterials();

                    if(newFileName){
                        free(newFileName);
                    }
                    free(limits);
                    return ret;
                }
                free(limits);
            }
        }
    }
    return false;
}
