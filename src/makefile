main:
	g++ -g *.cpp -std=c++11 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Code.tar.gz

untar:
	tar -zxvf *.tar.gz
