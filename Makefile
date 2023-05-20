main.exe: *.cpp
	g++ -Wall -std=c++11 -o main.exe *.cpp
clean:
	rm -f main.exe