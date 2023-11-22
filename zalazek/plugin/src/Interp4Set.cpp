#include <iostream>
#include "Interp4Set.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Set"; }
}




/*!
 * \brief
 *
 *
 */
AbstractInterp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}


/*!
 *
 */
Interp4Set::Interp4Set(): _name(""),
                            _positionOX(0),
                            _positionOY(0),
                            _positionOZ(0),
                            _angleOX(0),
                            _angleOY(0),
                            _angleOZ(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << 
          name << " " << 
          positionOX << " " << 
          positionOY << " " << 
          positionOZ << " " << 
          angleOX << " " << 
          angleOY << " " << 
          angleOZ << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Set::ExecCmd( AbstractScene      &rScn, 
                           const char         *sMobObjName,
			                     AbstractComChannel &rComChann)
{
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  return true;
}

/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  WspX[m]  WspY[m] WspZ[m]  " 
          "        KatOX  KatOY  KatOZ "  < endl;
}