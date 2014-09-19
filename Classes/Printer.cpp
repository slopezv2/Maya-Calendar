#include "Printer.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

Printer::Printer(map<string,int>* pHAAB, map<string,int>* pTzolkin)
{
  // pointers to each map to search the months.
  Printer::HAAB = pHAAB;
  Printer::Tzolkin = pTzolkin;
}

Printer::~Printer(){
  
}

/*
 * Method to print the date in whatever of the two formats
 * Parameters are bool for the type and long for the date in days.
 */
string Printer::printDate(bool type,long date){
  if(!type){
    // If it's to HAAB format.
    int year = (date / 365);
    int rest = date % 365;
    int monthVa = rest / 20;
    int day = (rest % 20) - 1;
    if(rest % 20 == 0){
      day = 19;
      monthVa -= 1;
    }
    string monthS= "             ";
    map<string, int>::iterator it;
    // Search the month string in map.
    for(it = HAAB->begin(); it != HAAB->end();++it){
      if((it->second) == (monthVa*20)){
	monthS = it->first;
      }
    }
    cout << day<<" "<<monthS<<" "<<year<<endl;
    stringstream stream;
    string data;
    stream << day << " " << monthS <<" " <<year;
    data = stream.str();
    return data;
  }else{
    // for Tzolkin format
    int year = (date / 260);
    int rest = date % 260;
    int monthValue = rest % 20;
    string monthS = "             ";
    map<string, int>::iterator it;
    // Search the month in string using map
    for(it = Tzolkin->begin(); it != Tzolkin->end();++it){
      if(it->second == monthValue){
        monthS = it -> first;
      }
    }
    int iterator = rest / 20;
    int day = (monthValue % 13);
    for(int i = 0; i < iterator;i++){
      if(day + 7 == 13){
	day = 13;
      }else{
	day = (day + 7) % 13;
      }
    }
    cout << day << " " << monthS <<" " <<year << endl;
    stringstream stream;
    string data;
    stream << day << " " << monthS <<" " <<year;
    data = stream.str();
    // Return the date in "dd month yy" format
    return data;
  }
}
