#include <uostream> 
#include <sstream>
#include <map>
#include <vector> 
#include <memory>
#include "LibInterface.hh"

class Set4LibInterfaces
{
    std::map<std::string,std::shared_ptr<LibInterface>> _libSet; // chyba powinno byc multimap
    AbstrackInterp4Command* _pCmd;

    public:

    bool init(std::vector<std::string> plugins);
    bool ExecCmd(std::istream &commands, AbstrackMobileObj* pMobObj, int socket);

};