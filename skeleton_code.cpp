#include <iostream>
#include <string>

class HelloWorld {
    public:
        HelloWorld() : message("Hello, 214 Project") {}

        void printMessage() {
            std::cout << message << std::endl;
        }

    private:
        const std::string message;
};

int main(int argc, char** argv) {
    HelloWorld hello;

    hello.printMessage();

    return 0;
}
