MayaCalendar: Main.o Conversor.o Printer.o 
	g++ -g -o MayaCalendar Main.o Conversor.o Printer.o
	@echo "Termino de generar MayaCalendar."


Main.o: Main.cpp Conversor.h Printer.h
	g++ -g -c Main.cpp

Conversor.o: Conversor.cpp Conversor.h 
	g++ -g -c Conversor.cpp

Printer.o: Printer.cpp Printer.h
	g++ -g -c Printer.cpp

clean:
	rm -f *.o
	rm -f MayaCalendar
