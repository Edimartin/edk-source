#ifndef BLOCKSGLSL_H
#define BLOCKSGLSL_H

#include "../TypeDefines.h"
#include "../String.h"
#include "../MemoryBuffer.h"

namespace edk{
namespace shd{
class BlocksGLSL{
public:
    BlocksGLSL();
    ~BlocksGLSL();

    void clean();

    bool addCode(const edk::char8* code);
    bool addCode(edk::char8* code);

    //test if have the code
    bool haveCode();

    edk::char8* getCodePointer();
    inline edk::uint64 getCodeSize(){
        return this->getCodeLenght();
    }
    edk::uint64 getCodeLenght();

    //print the code
    void print();
private:
    edk::MemoryBuffer<edk::char8> bufferOctos;
    edk::MemoryBuffer<edk::char8> bufferCommand;
    edk::MemoryBuffer<edk::char8> bufferFunctions;
    edk::MemoryBuffer<edk::char8> bufferMain;

    edk::MemoryBuffer<edk::char8> bufferCode;

    //test if it's a function command
    bool isFunctionLine(edk::char8* start,edk::char8* end,bool* isMain);

    //generate the code
    void generate();
};
}//end shd
}//end edk

#endif // BLOCKSGLSL_H
