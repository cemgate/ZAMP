#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH
#include "AbstrackInterp4Command.hh"

#include <iostream>
#include <string.h>
#include <dlfcn.h>

class LibInterface 
{
    public:
    ~LibInterface(){};
    LibInterface(){};

    std::string CmdName();

    bool init(std::string libName);

    void* libHandler;
    const char* (*pGetCmdName)(void);
    AbstrackInterp4Command* (*pCreateCmd)(void);
    AbstrackInterp4Command* (*pPrintCmd)(void);
    AbstrackInterp4Command* (*pReadParams)(std::istream&);
}

#endif

