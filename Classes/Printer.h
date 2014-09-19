#ifndef Printer_h
#define Printer_h
#include <map>
#include <string>

using namespace std;
/*
 * Definition for Printer Class.
 */
class Printer{
 public:
  Printer(map<string,int>* pHAAB, map<string,int>* pTzolkin);
  ~Printer();
  string printDate(bool type,long date);
 private:
  map<string,int>* HAAB;
  map<string,int>* Tzolkin;  
  
};
#endif

