#include <iostream>
#include "singleton.h"


int main() {

    auto S = Singleton::getInstance(20);
    int b = S->doSomething(10);


    return 0;
}
