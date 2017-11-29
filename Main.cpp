#include <memory>
#include <iostream>
#include "Signal.hpp"

void slotFunc(int a, int b) {
    std::cout << "a + b: " << a + b << std::endl;
}

void slotFunc1(int a, int b) {
    std::cout << "a - b: " << a - b << std::endl;
}

class A {
public:
    void testSlot(int a, int b) { std::cout << "a * b: " << a * b << std::endl; }
    void testSlot1(int a, int b) { std::cout << "a / b: " << a / b << std::endl; }
};

int main(int argc, char *argv[]) {
    (void)argc; (void)argv;

    // Global function
    {
        simpleSignal::Signal<void(int, int)> signal;
        signal.connect(slotFunc);
        signal.connect(slotFunc1);
        signal.emit(20, 10);
    }

    // Member function
    {
        simpleSignal::Signal<void(int, int)> signal;
        A a;
        signal.connect(&a, &A::testSlot);
        signal.connect(&a, &A::testSlot1);
        signal.emit(20, 10);
    }

    // Lambda
    {
        simpleSignal::Signal<void(int, int)> signal;
        signal.connect([](int a, int b) { std::cout << "a b " << a << "  " << b << std::endl;});
        signal.emit(20, 10);
    }

    return 0;
}
