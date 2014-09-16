#ifndef Conversor_h
#define Conversor_h
#include <map>
#include <string>
#include <iostream>
#include <vector>

using  namespace std;

class Conversor{
 public:
  Conversor();
  ~Conversor();
  long eval(string input);
  map<string, int>* getHAAB();
  map<string, int>* getTzolkin();
  bool isHAAB(string input);
 private:
  vector<string> split(string input);
  long TzolkinToLong(int day, string month, int year);
  long HAABToLong(int day, string month, int year);
  map<string,int> HAABMap;
  map<string, int> TzolkinMap;
};
#endif
