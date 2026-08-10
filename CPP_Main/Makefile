output: main.o data.o
	g++ main.o data.o -o output

main.o: main.cpp
	g++ -c main.cpp

data.o: data.cpp
	g++ -c data.cpp

clean:
	rm -f *.o