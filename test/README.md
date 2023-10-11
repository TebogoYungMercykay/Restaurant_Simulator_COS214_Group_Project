## Restaurant Simulator - Test

The "test" directory is dedicated to testing our "Restaurant Simulator". In this folder, you'll find unit tests, integration tests, and test data to ensure the robustness and correctness of our Implementation. Testing is a crucial part of our development process, so please contribute to and run tests as needed. For guidance on testing procedures, consult with our team members.

- ## Requirements before Testing Code:

  - Install an `IDE` that compiles and runs C++ code.

    - 1st Recommendation: `VS Code`
    - 2nd Recommendation: `IntelliJ IDEA`
    - 3rd Recommendation: `Visual Studio`
  - Setup Video:

    - Title: How to set up WSL Ubuntu terminal shell and run it from Visual Studio Code
    - Video Link: [Youtube-Video-Link](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s)
    - Installing Coverage (Linux (Debian/Ubuntu)):
      - sudo apt-get update
      - sudo apt-get install gcov
      - sudo apt-get install lcov
      - which gcov
      - which lcov
    - Installing Valgrind (Linux (Debian/Ubuntu)):
      - sudo apt-get install valgrind
  - ###### NB: The makefile is included to compile and run the code on the terminal.


    - ###### `Commands:=`

      - `make` (to build the main executable).
      - `make clean` (to clean up generated files).
      - `make run` (to run the program with valgrind (assuming you have installed `valgrind`)).
      - `make tar` (to create a tarball of your project).
      - `make untar` (to extract the contents of the `tarball`).
      - `make coverage` (to generate coverage reports (assuming you have installed `lcov`)).

      ---

      ```C++
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
          gcov -f -m -r -j term polynomial univariate bivariate linear quadratic circle ellipse
          ./main
          lcov -c -d . -o coverage.info
          genhtml coverage.info -o coverage_report

      ```

---

<p align="center">The End, Thank You</p>

---
