#ifdef Conversor_h
#define Conversor_h
#include <map>
#include <string>


class Conversor{
 public:
  Conversor();
  long eval(string input);
  
 private:
  char detectType(string input);
  long toHAAB(int day, string month, int year);
  long toTzolkin(int day, string month, int year);
};
#endif
