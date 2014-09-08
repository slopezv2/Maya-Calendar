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
  char detectType(string input);
  long toHAAB(int day, string month, int year);
  long toTzolkin(int day, string month, int year);
};
#endif
