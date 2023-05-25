all: src/*.cpp src/*.h
	g++ -Wall -std=c++11 -o main.exe src/*.cpp
run: main.exe
	./main.exe > image.ppm
clean: main.exe
	rm -f main.exe