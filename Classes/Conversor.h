#ifndef Conversor_h
#define Conversor_h
#include <map>
#include <string>

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
  long toHAAB(int day, string month, int year);
  long toTzolkin(int day, string month, int year);
  map<string,int> HAABMap;
  map<string, int> TzolkinMap;
};
#endif
