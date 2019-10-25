#ifndef FILENODE_H
#define FILENODE_H

#include "../NameClass.h"
#include "../TypeVars.h"
#include "../File.h"

namespace edk{
namespace pack{
class FileNode{
public:
    FileNode();
    virtual ~FileNode();

    //set the fileName
    bool setFileName(edk::char8* str);
    bool setFileName(const edk::char8* str);
    //return the fileName
    edk::char8* getFileName();
    edk::char8* getStrName();
    //clean the name
    void cleanName();
    void clean();

    void setPosition(edk::uint64 position);
    edk::uint64 getPosition();
    void setFileSize(edk::uint64 fileSize);
    edk::uint64 getFileSize();

    //return the size of the node
    edk::uint64 getSize();
    edk::uint64 size();

    //return true if this fileNode is bigger then the other node
    bool biggerThan(edk::pack::FileNode* node);
    bool equalThan(edk::pack::FileNode* node);

    void print();

    //write the node to the file
    bool writeFile(edk::File* file);
    bool readFile(edk::File* file);
private:
    edk::Name str;
    edk::Name fileName;
    edk::uint64 position;
    edk::uint64 fileSize;
};
}
}

#endif // FILENODE_H
