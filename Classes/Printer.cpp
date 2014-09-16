#include "Printer.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

Printer::Printer(map<string,int>* pHAAB, map<string,int>* pTzolkin)
{
  Printer::HAAB = pHAAB;
  Printer::Tzolkin = pTzolkin;
}

Printer::~Printer(){
  
}

void Printer::printDate(bool type,long date){
  if(!type){
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
    cout << day << " " << monthS <<" " <<year << endl;
  }else{
    int year = date / 220;
    int rest = date % 220;
    int monthValue = rest % 20;
    string monthS;
    map<string, int>::iterator it;
    for(it = Tzolkin->begin(); it != Tzolkin->end();++it){
      if(it->second == monthValue){
        monthS = it -> first;
	it = Tzolkin->end();
      }
    }

    int iterator = rest / 20;
    int day = monthValue;
    for(int i = 0; i < iterator;i++){
      if(day + 7 == 13){
	day = 13;
      }else{
	day = (day + 7) % 13;
      }
    }
    cout << "Mi mes: "<< monthS << endl;
    cout << day << " " << monthS <<" " <<year << endl;

  }
}
