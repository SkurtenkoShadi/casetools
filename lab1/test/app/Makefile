main: main.o
	g++ -L../lib/ -o main main.o -lhead 
	#export LD_LIBRARY_PATH=../lib/:$LD_LIBRARY_PATH

main.o: main.cpp
	g++ -I. -I../lib/ -c main.cpp

clean:
	rm *.o main