#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "AbstractInterp4Command.hh"

using namespace std;
#define LINE_SIZE 1000;

class LibInterface
{
  void *plindHnd = nullptr;
  AbstractInterp4Command* (*pCreateCmd_Move)(void) = nullptr;

  public:
  AbstractInterp4Command* cmdHnd;
  
  bool Init(const char* sFileName);
  AbstractInterp4Command* CreateCmd() {assert(pCreateCmd); return pCreateCmd();}
}

bool LibInterface::Init(const char* sFileName)
{
  plindHnd = dlopen(sFileName,RTLD_LAZY);
  if(!plindHnd)
  {
    cout << "siema szefie chyba nie znaleziono biblioteki o nazwie " << sFileName << endl;
    return 0;
  }

  void *pFun = dlsym(plindHnd,"CreateCmd");
  if(!pFun)
  {
    cout <<"oj kurde chyba nie udalo sie znalezc funkcji CreateCmd sadeq" << endl;
    return 0;
  }

  pCreateCmd= reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);
  return 1;
}

bool ExecPreproceser(const char* FileName, istringstream &Istrm4Cmds)
{
  std Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream tmpStrm;

  Cmd4Preproc+= FileName;
  FILE
}


int main()
{
 
}
