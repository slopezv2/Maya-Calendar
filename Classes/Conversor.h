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
  
 private:
  bool isHAAB(string input);
  long toHAAB(int day, string month, int year);
  long toTzolkin(int day, string month, int year);
  int monthToInt(string month);
};
#endif
