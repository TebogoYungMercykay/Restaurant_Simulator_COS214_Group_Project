#include <gtest/gtest.h>
#include "../src/List/List.h"
#include "../src/List/Iterator.h"

class ListAndIteratorTest : public testing::Test {
protected:
    List<int> emptyInitially; 
    List<int> threeItemsInitially;
    Iterator<int>* emptyInitiallyIterator; 
    Iterator<int>* threeItemsInitiallyIterator;

    ListAndIteratorTest() {
        threeItemsInitially.add(1);
        threeItemsInitially.add(2);
        threeItemsInitially.add(3);

        emptyInitiallyIterator = emptyInitially.getIterator();
        threeItemsInitiallyIterator = threeItemsInitially.getIterator();
    }

    ~ListAndIteratorTest() {
        delete emptyInitiallyIterator;
        delete threeItemsInitiallyIterator;
    }
};

TEST_F(ListAndIteratorTest, CanIterate) {
    ASSERT_EQ(threeItemsInitiallyIterator->isDone(), false);

    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), i);
        threeItemsInitiallyIterator->next();
    }

    EXPECT_EQ(threeItemsInitiallyIterator->isDone(), true);
}

TEST_F(ListAndIteratorTest, StartsEmpty) {
    EXPECT_EQ(emptyInitiallyIterator->isDone(), true);
}

TEST_F(ListAndIteratorTest, CanAdd) {
    emptyInitially.add(5);
    emptyInitiallyIterator->reset();
    EXPECT_EQ(emptyInitiallyIterator->getCurrent(), 5);

    threeItemsInitially.add(5);
    threeItemsInitiallyIterator->reset();
    for (int i = 0; i < 3; i++) {
        threeItemsInitiallyIterator->next();
    }
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 5);
}

TEST_F(ListAndIteratorTest, CanRemove) {
    threeItemsInitially.remove(1);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 2);

    threeItemsInitially.remove(3);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 2);

    threeItemsInitially.remove(2);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->isDone(), true);
}

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