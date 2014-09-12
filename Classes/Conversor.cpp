#include "Conversor.h"
#include <map>
#include <string>

using namespace std;

Conversor::Conversor()
{
  Conversor::HAABMap.insert(pair<string,int>("pop",0));
  Conversor::HAABMap.insert(pair<string,int>("no",20));
  Conversor::HAABMap.insert(pair<string,int>("zip",40));
  Conversor::HAABMap.insert(pair<string,int>("zotz",60));
  Conversor::HAABMap.insert(pair<string,int>("tzec",80));
  Conversor::HAABMap.insert(pair<string,int>("zul",100));
  Conversor::HAABMap.insert(pair<string,int>("yoxkin",120));
  Conversor::HAABMap.insert(pair<string,int>("mol",140));
  Conversor::HAABMap.insert(pair<string,int>("chen",160));
  Conversor::HAABMap.insert(pair<string,int>("yax",180));
  Conversor::HAABMap.insert(pair<string,int>("zac",200));
  Conversor::HAABMap.insert(pair<string,int>("ceh",220));
  Conversor::HAABMap.insert(pair<string,int>("mac",240));
  Conversor::HAABMap.insert(pair<string,int>("kankin",260));
  Conversor::HAABMap.insert(pair<string,int>("muan",280));
  Conversor::HAABMap.insert(pair<string,int>("pax",300));
  Conversor::HAABMap.insert(pair<string,int>("koyab",320));
  Conversor::HAABMap.insert(pair<string,int>("cumhu",340));
  Conversor::HAABMap.insert(pair<string,int>("uayet",360));

  Conversor::TzolkinMap.insert(pair<string,int>("imix",1));
  Conversor::TzolkinMap.insert(pair<string,int>("ik",2));
  Conversor::TzolkinMap.insert(pair<string,int>("akbal",3));
  Conversor::TzolkinMap.insert(pair<string,int>("kan",4));
  Conversor::TzolkinMap.insert(pair<string,int>("chicchan",5));
  Conversor::TzolkinMap.insert(pair<string,int>("cimi",6));
  Conversor::TzolkinMap.insert(pair<string,int>("manik",7));
  Conversor::TzolkinMap.insert(pair<string,int>("lamat",8));
  Conversor::TzolkinMap.insert(pair<string,int>("muluk",9));
  Conversor::TzolkinMap.insert(pair<string,int>("ok",10));
  Conversor::TzolkinMap.insert(pair<string,int>("chuen",11));
  Conversor::TzolkinMap.insert(pair<string,int>("eb",12));
  Conversor::TzolkinMap.insert(pair<string,int>("ben",13));
  Conversor::TzolkinMap.insert(pair<string,int>("ix",14));
  Conversor::TzolkinMap.insert(pair<string,int>("mem",15));
  Conversor::TzolkinMap.insert(pair<string,int>("cib",16));
  Conversor::TzolkinMap.insert(pair<string,int>("caban",17));
  Conversor::TzolkinMap.insert(pair<string,int>("eznab",18));
  Conversor::TzolkinMap.insert(pair<string,int>("canac",19));
  Conversor::TzolkinMap.insert(pair<string,int>("eznab",20));
}

map<string, int>* Conversor::getHAAB(){
  return &(HAABMap);
}

map <string, int>* Conversor::getTzolkin(){
  return &(TzolkinMap);
}

 Conversor::~Conversor(){
  
}

long Conversor::eval(string input){
  char type;
  long result = 0;
  return result;
  //TODO}
}

bool Conversor::isHAAB(string input){
  map<string,int>::iterator it = HAABMap.find(input);
  if (it == HAABMap.end()){
    return false;
  }
  return true;
  //True for HAAB Calendar
  //False for Tzolkin
}

long Conversor::toHAAB(int day, string month, int year){
  long result = 0;
  result += (year * 260);
  int monthValue = TzolkinMap.find(month)->second;
  if((monthValue % 13 ) ==  day || monthValue == day){
    result += monthValue;
  }else{
    int sum = 0;
    int x = monthValue;
    int y = day;
    do{
      sum += 20;
      x += 7;

    }while(x % 13 != y);
    result += (sum + monthValue);
  }
  return result;
}

long Conversor::toTzolkin(int day, string month, int year){
  int monthValue = HAABMap.find(month)->second;
  long result = 0;
  result += day;
  result += monthValue;
  result += (year * 365);
  return result;
}
