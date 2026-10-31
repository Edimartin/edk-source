#include "RetroTileMapList.h"

edk::retro::RetroTileMapList::RetroTileMapList(){
    //
}
edk::retro::RetroTileMapList::~RetroTileMapList(){
    //
    this->clean();
}

void edk::retro::RetroTileMapList::clean(){
    edk::uint32 size = this->stack.size();
    edk::retro::RetroTileMap* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            delete temp;
        }
    }
    this->stack.clean();
}

edk::uint32 edk::retro::RetroTileMapList::size(){
    return this->stack.size();
}

//create a new tileMap
edk::uint32 edk::retro::RetroTileMapList::createNewMap(edk::retro::RetroTileSet* set,edk::size2ui32 size){
    if(set && size.width && size.height){
        //create a new tileMap
        edk::retro::RetroTileMap* map = new edk::retro::RetroTileMap;
        if(map){
            map->setTileSet(set);
            if(map->newMap(size)){
                edk::uint32 size = this->stack.size();
                edk::uint32 ret = this->stack.pushBack(map);
                if(this->stack.size()>size){
                    return ret;
                }
            }
            delete map;
        }
    }
    return 0u;
}
edk::uint32 edk::retro::RetroTileMapList::createNewMap(edk::retro::RetroTileSet* set,edk::uint32 width,edk::uint32 height){
    return this->createNewMap(set,edk::size2ui32(width,height));
}

//get the map on the position
edk::retro::RetroTileMap* edk::retro::RetroTileMapList::getMap(edk::uint32 position){
    if(this->stack.havePos(position)){
        return this->stack.get(position);
    }
    return NULL;
}
