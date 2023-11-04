#include <gtest/gtest.h>

#include "ListAndIteratorTest.cpp"
#include "TableCollectionTest.cpp"
#include "BookingTest.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
    * Using Valgrind for Memory Management:

            valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./test
                            OR
            valgrind --leak-check=full ./test

    * Using GDB for Debugging:

            g++ -g *.cpp -std=c++11 -pedantic -o test
            gdb ./test
            run

    * Test Coverage Program: https://gcc.gnu.org/onlinedocs/gcc/Gcov.html

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

            test:
                g++ --coverage *.cpp -o main
                gcov -f -m -r -j filenames_space_separated_here_with_no_file_extention
                ./main
                lcov -c -d . -o coverage.info
                genhtml coverage.info -o coverage_report

            

    * Installing GoogleTest
    $ git clone https://github.com/google/googletest.git -b v1.14.0
    $ cd googletest 
    $ cmake -B build   
    $ cd build
    $ make
    $ sudo make install

    * Compiling from the test directory
    $ cmake -B build
    $ cmake --build build

    * Running 
    $ ./build/main_test
    or 
    $ cd build && ctest

*/