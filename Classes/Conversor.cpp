#include "Conversor.h"
#include <map>
#include <string>

using namespace std;

Conversor::Conversor()
{

}

Conversor::~Conversor(){

}

long Conversor::eval(string input){
  char type;
  long result = 0;
  return result;
  //TODO
}

bool Conversor::isHAAB(string input){
  return true;
  //TODO
  //True for HAAB Calendar
  //False for Tzolkin
}

long Conversor::toHAAB(int day, string month, int year){
  long result = 0;
  return result;
  //TODO
}

long Conversor::toTzolkin(int day, string month, int year){
  long result = 0;
  result += day;
  return result;
  //TODO
}

int Conversor::monthToInt(string month){
  if (month.compare("pop") == 0 ) return 0;
  else if (month.compare("no") == 0 ) return 20;
  else if (month.compare("zip") == 0 ) return 40;
  else if (month.compare("zotz") == 0 ) return 60;
  else if (month.compare("tzec") == 0 ) return 80;
  else if (month.compare("xul") == 0 ) return 100;
  else if (month.compare("yoxkin") == 0 ) return 120;
  else if (month.compare("mol") == 0 ) return 140;
  else if (month.compare("chen") == 0 ) return 160;
  else if (month.compare("yax") == 0 ) return 180;
  else if (month.compare("zac") == 0 ) return 200;
  else if (month.compare("ceh") == 0 ) return 220;
  else if (month.compare("mac") == 0 ) return 240;
  else if (month.compare("kankin") == 0 ) return 260;
  else if (month.compare("muan") == 0 ) return 280;
  else if (month.compare("pax") == 0 ) return 300;
  else if (month.compare("koyab") == 0 ) return 320;
  else if (month.compare("cumhu") == 0 ) return 340;
  else if (month.compare("uayet") == 0 ) return 360;

  //return 0;
  //TODO
 }


