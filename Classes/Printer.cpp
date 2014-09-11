#include "Printer.h"
#include <string>
#include <map>

using namespace std;

Printer::Printer(map<string,int>* pHAAB, map<string,int>* pTzolkin)
{
  HAAB = pHAAB;
  Tzolkin = pTzolkin;
}

Printer::~Printer(){

}

void Printer::printDate(bool type,long date){
  //TODO
}
