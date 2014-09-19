#ifndef Conversor_h
#define Conversor_h
#include <map>
#include <string>
#include <iostream>
#include <vector>

using  namespace std;

/*
 * Conversor Definition
 */
class Conversor{
 public:
  Conversor();
  ~Conversor();
  long eval(string input);
  map<string, int>* getHAAB();
  map<string, int>* getTzolkin();
  bool isHAAB(string input);
  vector<string> split(string input);
 private:
  long TzolkinToLong(int day, string month, int year);
  long HAABToLong(int day, string month, int year);
  map<string,int> HAABMap;
  map<string, int> TzolkinMap;
};
#endif
