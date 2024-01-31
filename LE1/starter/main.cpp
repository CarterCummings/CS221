#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"

int main() {
    StackArrayDouble<int> stack;

    // Testing the dynamic stack
    for (int i = 1; i <= 10; ++i) {
        stack.push(i);
    }

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    return 0;
}