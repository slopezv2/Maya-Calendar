#include <string.h>
#include <iostream>
#include <map>
#include "Conversor.h"
#include "Printer.h"

using namespace std;
Conversor* conver;
Printer* printer;

int consoleCommands(int argc, char* argv[]){
  if(argc > 1){
    if((strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"-h")) == 0 || (strcmp(argv[1],"-?")==0)){
      cout << "Usage: ./MayaCalendar [Command] [FileName]" << endl;
      cout << "  -h     -?     --help     Shows description of all the commands from the command prompt." << endl;
      cout << "  -v            --version  Shows version information of the proyect." <<endl;
      cout << "  -a            --about    Displays information about the Calc proyect and its funcionality." << endl;
      return 0;
    } else if((strcmp(argv[1],"--version")==0) || (strcmp(argv[1],"-v")==0)){
      cout << "Version Beta" << endl;
      return 0;
    } else if((strcmp(argv[1],"--about")==0) || (strcmp(argv[1],"-a")==0)){
      cout << "Maya Calendar is a program that converts dates between the Mayan HAAB calendar to Tzolkin and viceversa." << endl;
      cout << "Software by Sebastian Lopez and Juan Manuel Mejía." << endl;
      cout << "2014." << endl;
      return 0;
    }
  } else {
    return 2;
  }
}

int main(int argc, char* argv[]){
  try{
    
    if(consoleCommands(argc, argv)==0){
      return 0;
    }
    
    conver = new Conversor();
    map<string,int>* aux = conver->getHAAB();
    map<string,int>* aux2 = conver->getTzolkin();
    printer = new Printer(aux, aux2);
    string input;
    if(argc<2){
      cout << "Maya Conversor"<< endl;
      cout << "press :quit to leave the program"<< endl;
      cout << "Insert a date in this format: dd(number) month(string) year(number)"<<endl;
      cout << "> ";
      getline(cin, input);
      while(input.compare(":quit") != 0){
	long result= conver->eval(input);
	cout <<"Long:"<<result<<endl;
	vector<string> temp = conver->split(input);
	string monthT = temp.at(1);
	printer->printDate(conver->isHAAB(monthT),result);
	cout << "insert a new date: "<<endl;
	cout << "> ";
	getline(cin,input);
      }
    } else {
      //Lectura del Fichero
    }
    return 0;
  } catch (...){
    cout << "Dono bro, u f*cked" << endl;
  }
}
