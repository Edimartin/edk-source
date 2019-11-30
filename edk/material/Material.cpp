#include "Material.h"

edk::material::Material::Material(){
    for(edk::uint8 i=0u;i<materialTextureCount;i++){
        //clean the textures
        this->textures[i]=0u;
    }
    this->countTextures=0u;
    this->canDelete=true;
    //ambient
    this->ambient[0] = 0.2f;
    this->ambient[1] = 0.2f;
    this->ambient[2] = 0.2f;
    this->ambient[3] = 1.0f;
    //diffuse
    this->diffuse[0] = 0.8f;
    this->diffuse[1] = 0.8f;
    this->diffuse[2] = 0.8f;
    this->diffuse[3] = 1.0f;
    //specular
    this->specular[0] = 0.0f;
    this->specular[1] = 0.0f;
    this->specular[2] = 0.0f;
    this->specular[3] = 1.0f;
    //emission
    this->emission[0] = 1.0f;
    this->emission[1] = 1.0f;
    this->emission[2] = 1.0f;
    this->emission[3] = 1.0f;
    //shinines
    this->shininess[0] = 0.0f;
    this->shininess[1] = 0.0f;
    this->shininess[2] = 0.0f;
    this->shininess[3] = 1.0f;
}
edk::material::Material::~Material(){
    if(this->canDelete){
        //remove all the textures
        this->removeAllTextures();
    }
}
//set to cantDelete
void edk::material::Material::cantDelete(){
    this->canDelete=false;
}
//draw the material parameters
void edk::material::Material::useMaterialParameters(){
    /*
    edk::GU::guEnable(GU_LIGHTING);
    edk::GU::guEnable(GU_LIGHT0);
    glLightfv(GL_LIGHT0,GL_AMBIENT,this->specular);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,this->ambient);
    */
    edk::GU::guMaterialfv32(GU_FRONT,GU_AMBIENT,this->ambient);
    edk::GU::guMaterialfv32(GU_FRONT,GU_DIFFUSE,this->diffuse);
    edk::GU::guMaterialfv32(GU_FRONT,GU_SPECULAR,this->specular);
    edk::GU::guMaterialfv32(GU_FRONT,GU_EMISSION,this->emission);
    edk::GU::guMaterialfv32(GU_FRONT,GU_SHININESS,this->shininess);
}

//load the texture
bool edk::material::Material::loadTexture(edk::char8* name,edk::uint8 position,edk::uint32 filter){
    //test the position
    if(position<materialTextureCount){
        //remove the texture
        this->removeTexture(position);
        //then load the new texture
        this->textures[position] = this->list.loadTexture(name,filter);
        if(this->textures[position]){
            this->countTextures++;
            return true;
        }
    }
    return false;
}
bool edk::material::Material::loadTexture(const char* name,edk::uint8 position,edk::uint32 filter){
    return this->loadTexture((edk::char8*) name,position,filter);
}
bool edk::material::Material::loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint8 position,edk::uint32 filter){
    //test the position
    if(position<materialTextureCount){
        //remove the texture
        this->removeTexture(position);
        //then load the new texture
        this->textures[position] = this->list.loadTextureFromMemory(name,image,size,filter);
        if(this->textures[position]){
            this->countTextures++;
            return true;
        }
    }
    return false;
}
bool edk::material::Material::loadTextureFromMemory(const char* name,edk::uint8* image,edk::uint32 size,edk::uint8 position,edk::uint32 filter){
    return loadTextureFromMemory((edk::char8*) name,image,size,position,filter);
}
bool edk::material::Material::loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint8 position,edk::uint32 filter){
    //test the position
    if(position<materialTextureCount){
        //remove the texture
        this->removeTexture(position);
        //then load the new texture
        this->textures[position] = this->list.loadTextureFromPack(pack,name,filter);
        if(this->textures[position]){
            this->countTextures++;
            return true;
        }
    }
    return false;
}
bool edk::material::Material::loadTextureFromPack(edk::pack::FilePackage* pack,const char* name,edk::uint8 position,edk::uint32 filter){
    return this->loadTextureFromPack(pack,(edk::char8*) name,position,filter);
}
//set the texture
bool edk::material::Material::setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position,edk::uint32 filter){
    //test the position
    if(position<materialTextureCount){
        //remove the texture
        this->removeTexture(position);
        //then load the new texture
        this->textures[position] = this->list.setTextureFromMemory(name,image,width,height,channels,filter);
        if(this->textures[position]){
            this->countTextures++;
            return true;
        }
    }
    return false;
}
bool edk::material::Material::setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position,edk::uint32 filter){
    return this->setTextureFromMemory((edk::char8*) name,image,width,height,channels,position,filter);
}
bool edk::material::Material::setTextureFromMemory(edk::Image2D* image,edk::uint8 position,edk::uint32 filter){
    if(image){
        return this->setTextureFromMemory(image->getName(),image->getPixels(),image->getSize().width,image->getSize().height,image->getChannels(),position,filter);
    }
    return false;
}

//SETERS
void edk::material::Material::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0] = r;this->ambient[1] = g;this->ambient[2] = b;this->ambient[3] = a;
}
void edk::material::Material::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setAmbient(r,g,b,1.f);
}
void edk::material::Material::setAmbient(edk::color4f32 color){
    this->setAmbient(color.r,color.g,color.b,color.a);
}
void edk::material::Material::setAmbient(edk::color3f32 color){
    this->setAmbient(color.r,color.g,color.b);
}
void edk::material::Material::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->diffuse[0] = r;this->diffuse[1] = g;this->diffuse[2] = b;this->diffuse[3] = a;
}
void edk::material::Material::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setDiffuse(r,g,b,1.f);
}
void edk::material::Material::setDiffuse(edk::color4f32 color){
    this->setDiffuse(color.r,color.g,color.b,color.a);
}
void edk::material::Material::setDiffuse(edk::color3f32 color){
    this->setDiffuse(color.r,color.g,color.b);
}
void edk::material::Material::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->specular[0] = r;this->specular[1] = g;this->specular[2] = b;this->specular[3] = a;
}
void edk::material::Material::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setSpecular(r,g,b,1.f);
}
void edk::material::Material::setSpecular(edk::color4f32 color){
    this->setSpecular(color.r,color.g,color.b,color.a);
}
void edk::material::Material::setSpecular(edk::color3f32 color){
    this->setSpecular(color.r,color.g,color.b);
}
void edk::material::Material::setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->emission[0] = r;this->emission[1] = g;this->emission[2] = b;this->emission[3] = a;
}
void edk::material::Material::setEmission(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setEmission(r,g,b,1.f);
}
void edk::material::Material::setEmission(edk::color4f32 color){
    this->setEmission(color.r,color.g,color.b,color.a);
}
void edk::material::Material::setEmission(edk::color3f32 color){
    this->setEmission(color.r,color.g,color.b);
}
void edk::material::Material::setShininess(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->shininess[0] = r;this->shininess[1] = g;this->shininess[2] = b;this->shininess[3] = a;
}
void edk::material::Material::setShininess(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setShininess(r,g,b,1.f);
}
void edk::material::Material::setShininess(edk::color4f32 color){
    this->setShininess(color.r,color.g,color.b,color.a);
}
void edk::material::Material::setShininess(edk::color3f32 color){
    this->setShininess(color.r,color.g,color.b);
}

//GETERS
edk::color4f32 edk::material::Material::getAmbient(){
    return edk::color4f32(this->ambient[0u],this->ambient[1u],this->ambient[2u],this->ambient[3u]);
}
edk::color4f32 edk::material::Material::getDiffuse(){
    return edk::color4f32(this->diffuse[0u],this->diffuse[1u],this->diffuse[2u],this->diffuse[3u]);
}
edk::color4f32 edk::material::Material::getSpecular(){
    return edk::color4f32(this->specular[0u],this->specular[1u],this->specular[2u],this->specular[3u]);
}
edk::color4f32 edk::material::Material::getEmission(){
    return edk::color4f32(this->emission[0u],this->emission[1u],this->emission[2u],this->emission[3u]);
}
edk::color4f32 edk::material::Material::getShininess(){
    return edk::color4f32(this->shininess[0u],this->shininess[1u],this->shininess[2u],this->shininess[3u]);
}

//GETERS
edk::uint32 edk::material::Material::getTexture(edk::uint8 position){
    if(position < materialTextureCount){
        return this->textures[position];
    }
    return 0u;
}
//return the name of the texture
edk::char8* edk::material::Material::getTextureName(edk::uint8 position){
    if(position < materialTextureCount){
        return this->list.getTextureName(this->textures[position]);
    }
    return NULL;
}

//return the size of the texture
edk::size2ui32 edk::material::Material::getTextureSize(edk::uint8 position){
    edk::size2ui32 ret;
    if(position < materialTextureCount){
        //
        ret = this->list.getTextureSize(this->textures[position]);
    }
    return ret;
}
edk::uint32 edk::material::Material::getTextureWidth(edk::uint8 position){
    edk::uint32 ret=0u;
    if(position < materialTextureCount){
        //
        ret = this->list.getTextureSize(this->textures[position]).width;
    }
    return ret;
}
edk::uint32 edk::material::Material::getTextureHeight(edk::uint8 position){
    edk::uint32 ret=0u;
    if(position < materialTextureCount){
        //
        ret = this->list.getTextureSize(this->textures[position]).height;
    }
    return ret;
}

//remove the texture
bool edk::material::Material::removeTexture(edk::uint8 position){
    bool ret=false;
    //test if have the position
    if(position < materialTextureCount){
        //
        ret = this->list.removeTexture(this->textures[position]);
        if(ret)
            if(this->countTextures) this->countTextures--;
        this->textures[position]=0u;
    }
    return ret;
}
void edk::material::Material::removeAllTextures(){
    //remove all the textures
    for(edk::uint8 i=0u;i<materialTextureCount;i++){
        //clean the textures
        this->removeTexture(i);
    }
}
//delete the texture
bool edk::material::Material::deleteTexture(edk::uint8 position){
    bool ret=false;
    //test if have the position
    if(position < materialTextureCount){
        //
        ret = this->list.deleteTexture(this->textures[position]);
        if(this->countTextures) this->countTextures--;
        this->textures[position]=0u;
    }
    return ret;
}
//test if have texture
bool edk::material::Material::haveTexture(){
    return (bool)this->countTextures;
}
bool edk::material::Material::haveOneTexture(){
    if(this->countTextures==1u && this->textures[0u])
        return true;
    return false;
}

//DRAW
//draw the material
void edk::material::Material::drawStart(){
    //test if have a texture
    if(this->haveTexture()) this->drawStartWithMultiTexture();
    else                    this->drawNoTexture();
}
void edk::material::Material::drawEnd(){
    //test if have a texture
    this->drawEndWithTexture();
}
void edk::material::Material::drawNoTexture(){
    this->useMaterialParameters();
}
void edk::material::Material::drawStartWithOneTexture(){
    edk::GU::guEnable(GU_TEXTURE_2D);

    //edk::GU_GLSL::guActiveTexture(GU_TEXTURE0);
    //set the texture
    edk::GU::guUseTexture2D(this->textures[0u]);

    //draw the material parameters
    this->useMaterialParameters();
}
void edk::material::Material::drawStartWithOneTexture(edk::uint32 position){
    edk::GU::guEnable(GU_TEXTURE_2D);

    //edk::GU_GLSL::guActiveTexture(GU_TEXTURE0);
    //set the texture
    if(position<materialTextureCount)
        edk::GU::guUseTexture2D(this->textures[position]);
    else
        edk::GU::guUseTexture2D(this->textures[0u]);

    //draw the material parameters
    this->useMaterialParameters();
}
void edk::material::Material::drawStartWithMultiTexture(){
    edk::GU::guEnable(GU_TEXTURE_2D);
    //set the textures

    if(edk::GU_GLSL::guShaderInitiate()){
        for(edk::uint8 i=materialTextureCount-1u;i>0u;i--){

            //clean the textures
            edk::GU_GLSL::guActiveTexture(GU_TEXTURE0+i);
            edk::GU::guUseTexture2D(this->textures[i]);
        }
        edk::GU_GLSL::guActiveTexture(GU_TEXTURE0);
    }
    //set the zero texture
    edk::GU::guUseTexture2D(this->textures[0u]);

    //draw the material parameters
    this->useMaterialParameters();
}
void edk::material::Material::drawEndWithTexture(){
    //disable the texture
    edk::GU::guDisable(GU_TEXTURE_2D);
}

//XML
bool edk::material::Material::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"material_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the material
                        edk::char8* temp=NULL;
                        edk::char8* nameTemp=NULL;
                        edk::char8* iTemp=NULL;

                        //COLORS
                        if(xml->addSelectedNextChild("ambient")){
                            if(xml->selectChild("ambient")){
                                //write the attributes
                                for(edk::uint32 i=0u;i<4u;i++){
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                        if(nameTemp){
                                            temp=edk::String::float32ToStr(ambient[i]);
                                            if(temp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] temp;
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("diffuse")){
                            if(xml->selectChild("diffuse")){
                                //write the attributes
                                for(edk::uint32 i=0u;i<4u;i++){
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                        if(nameTemp){
                                            temp=edk::String::float32ToStr(diffuse[i]);
                                            if(temp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] temp;
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("specular")){
                            if(xml->selectChild("specular")){
                                //write the attributes
                                for(edk::uint32 i=0u;i<4u;i++){
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                        if(nameTemp){
                                            temp=edk::String::float32ToStr(specular[i]);
                                            if(temp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] temp;
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("emission")){
                            if(xml->selectChild("emission")){
                                //write the attributes
                                for(edk::uint32 i=0u;i<4u;i++){
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                        if(nameTemp){
                                            temp=edk::String::float32ToStr(emission[i]);
                                            if(temp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] temp;
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("shininess")){
                            if(xml->selectChild("shininess")){
                                //write the attributes
                                for(edk::uint32 i=0u;i<4u;i++){
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                        if(nameTemp){
                                            temp=edk::String::float32ToStr(shininess[i]);
                                            if(temp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] temp;
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }

                        //save textures
                        edk::uint32 textureID = 0u;
                        edk::char8* idTemp;
                        edk::uint32 filter=0u;
                        for(edk::uint32 i=0u;i<materialTextureCount;i++){
                            if(this->textures[i]){
                                textureID = this->textures[i];
                                //test if have the textureName
                                temp = this->list.getTextureName(textureID);
                                filter = this->list.getTextureFilter(textureID);
                                if(temp){
                                    //save the texture
                                    idTemp = edk::String::int64ToStr(i);
                                    if(idTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"texture_",idTemp);
                                        if(nameTemp){
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    xml->setSelectedString(temp);
                                                    //save the filter
                                                    temp = edk::String::uint32ToStr(filter);
                                                    if(temp){
                                                        xml->addSelectedNextAttribute((edk::char8*)"filter",temp);
                                                        delete[] temp;
                                                    }
                                                    xml->selectFather();
                                                }
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] idTemp;
                                    }
                                    temp=NULL;
                                }
                            }
                        }

                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::material::Material::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"material_",nameID);
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;
                    edk::char8* nameTemp = NULL;
                    edk::char8* iTemp = NULL;
                    //
                    if(xml->selectChild("ambient")){
                        //set the ambient attributes
                        for(edk::uint32 i=0u;i<4u;i++){
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                if(nameTemp){
                                    this->ambient[i] = edk::String::strToFloat32(xml->getSelectedAttributeValueByName(nameTemp));
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                        }
                        xml->selectFather();
                    }
                    if(xml->selectChild("diffuse")){
                        //set the diffuse attributes
                        for(edk::uint32 i=0u;i<4u;i++){
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                if(nameTemp){
                                    this->diffuse[i] = edk::String::strToFloat32(xml->getSelectedAttributeValueByName(nameTemp));
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                        }
                        xml->selectFather();
                    }
                    if(xml->selectChild("specular")){
                        //set the specular attributes
                        for(edk::uint32 i=0u;i<4u;i++){
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                if(nameTemp){
                                    this->specular[i] = edk::String::strToFloat32(xml->getSelectedAttributeValueByName(nameTemp));
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                        }
                        xml->selectFather();
                    }
                    if(xml->selectChild("emission")){
                        //set the emission attributes
                        for(edk::uint32 i=0u;i<4u;i++){
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                if(nameTemp){
                                    this->emission[i] = edk::String::strToFloat32(xml->getSelectedAttributeValueByName(nameTemp));
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                        }
                        xml->selectFather();
                    }
                    if(xml->selectChild("shininess")){
                        //set the shininess attributes
                        for(edk::uint32 i=0u;i<4u;i++){
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"value",iTemp);
                                if(nameTemp){
                                    this->shininess[i] = edk::String::strToFloat32(xml->getSelectedAttributeValueByName(nameTemp));
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                        }
                        xml->selectFather();
                    }

                    this->removeAllTextures();
                    //load the textures
                    edk::char8* idTemp;
                    for(edk::uint32 i=0u;i<materialTextureCount;i++){
                        //load the texture
                        idTemp = edk::String::int64ToStr(i);
                        if(idTemp){
                            nameTemp = edk::String::strCat((edk::char8*)"texture_",idTemp);
                            if(nameTemp){
                                if(xml->selectChild(nameTemp)){
                                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                                    if(temp){
                                        this->loadTexture(temp,i,
                                                          edk::String::strToInt64(xml->getSelectedAttributeValueByName("filter"))
                                                          );
                                        delete[] temp;
                                    }
                                    xml->selectFather();
                                }
                                delete[] nameTemp;
                            }
                            delete[] idTemp;
                        }
                    }

                    xml->selectFather();
                    ret=true;
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}

//TEMP
void edk::material::Material::printTexture(edk::uint8 position){
    if(position < materialTextureCount) printf("%u",this->textures[position]);
}
void edk::material::Material::printAmbient(){
    printf("\nAmbient");
    for(edk::uint8 i= 0u;i<4u;i++){
        printf(" %.2f"
               ,this->ambient[i]
               );
    }
    fflush(stdout);
}
