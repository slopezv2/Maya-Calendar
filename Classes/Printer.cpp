#include "Printer.h"
#include <string>
#include <map>

using namespace std;

Printer::Printer(map<string,int>* pHAAB, map<string,int>* pTzolkin)
{
  Printer::HAAB = pHAAB;
  Printer::Tzolkin = pTzolkin;
}

Printer::~Printer(){
  
}

void Printer::printDate(bool type,long date){
  //TODO
  if(type){
    int year = date / 365;
    int rest = date % 365;
    int month = rest / 20;
    int day = rest % 20;
    string monthS;
    map<string, int>::iterator it;
    for(it = HAAB->begin(); it != HAAB->end();++it){
      if(it->second == month){
	monthS = it -> first;
	it = HAAB->end();
      }
    }
    cout << "" + day + " " + monthS + " " + year << endl;
  }else{

  }
}
