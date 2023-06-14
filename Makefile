project1: main.o point.o fraction.o
	g++ -o project1 main.cc point.cc fraction.cc

main.o:	main.cc point.h fraction.h
	g++ -c main.cc

point.o: point.cc point.h fraction.h 
	g++ -c point.cc

fraction.o: fraction.cc	fraction.h
	g++ -c fraction.cc