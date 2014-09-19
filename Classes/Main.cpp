#include <string.h>
#include <iostream>
#include <map>
#include "Conversor.h"
#include "Printer.h"
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
 * Pointers to each object from the classes Conversor and Printer.
 * conver has the methods to changes a date between both calendars to long and detects the type of calendar.
 * printer has the methods to print a date using as parameters the type of calendar (bool) and the number in long.
 */
Conversor* conver;
Printer* printer;

/*
 * Method to displays different options of the program.
 */
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

/*
 * The main of the program
 */
int main(int argc, char* argv[]){
  try{
    
    if(consoleCommands(argc, argv)==0){
      // Checking if there are arguments.
      return 0;
    }
    
    conver = new Conversor();
    // Printer needs two parameters: Pointer to each map that contains the month information.
    map<string,int>* aux = conver->getHAAB();
    map<string,int>* aux2 = conver->getTzolkin();
    printer = new Printer(aux, aux2);
    string input;
    if(argc<2){
      // If the user will use the console
      cout << "Maya Conversor"<< endl;
      cout << "press :quit to leave the program"<< endl;
      cout << "Insert a date in this format: dd(number) month(string) year(number)"<<endl;
      cout << "> ";
      getline(cin, input);
      // Loop to red the dates until user introduce ":quit" in the console.
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
      // If the user put a file as parameter for the program.
      string newName = "output.txt";
      string line;
      //Reading the file.
      string directory = argv[1];
      ifstream file(directory.c_str());
      string numbLines;
      ofstream newFile(newName.c_str());
      getline(file,numbLines);
      int intLines;
      intLines = atoi(numbLines.c_str());
      newFile << numbLines << "\n";
      while(intLines > 0){
	getline(file,line);
	long result= conver->eval(line);
	vector<string> temp = conver->split(line);
	string monthT = temp.at(1);
	string resultStr = (printer->printDate(conver->isHAAB(monthT),result));
	newFile<<resultStr<<"\n";
	intLines--;
      }
      file.close();
      newFile.close();
      
    }
    return 0;
  } catch (...){
    cout << "You broke me, please check your input" << endl;
  }
}
