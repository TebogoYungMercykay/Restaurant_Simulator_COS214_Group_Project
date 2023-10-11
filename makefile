main:
	g++ -g *.cpp -std=c++11 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	./main

tar:
	tar -cvz skeleton_code.cpp makefile -f SkeletonCode.tar.gz

untar:
	tar -zxvf *.tar.gz