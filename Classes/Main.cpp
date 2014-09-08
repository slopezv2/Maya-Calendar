#include <string.h>
#include <iostream>
#include <map>
#include "Conversor.h"
#include "Printer.h"

using namespace std;
Conversor* conver;
Printer* printer;
int main(int argc, char* argv[]){
  conver = new Conversor();
  printer = new Printer();
  string input;
  if(argc < 2){
    cout << "Maya Conversor"<< endl;
    cout << "press :quit to leave the program"<< endl;
    cout << "Insert a date in this format: dd(number) month(string) year(number)"<<endl;
    cout << "< ";
    getline(cin, input);
    while(input.compare(":quit") != 0){
      cout << "insert a new date: "<<endl;
      cout << "< ";
      getline(cin,input);
      try{
	
      }catch(...){
	cout << "I don't know how... but you broke me!";
      }
    }
  }else{
    
  }
  return 0;
}
