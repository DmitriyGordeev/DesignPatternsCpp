#include <iostream>
#include "singleton.h"
#include "factory.h"

int main() {

    /* singleton usage */
    auto S = Singleton::getInstance(20);
    int b = S->doSomething(10);


    /* factory usage */
    auto circle = Factory::create(FigType::CIRCLE, 1, 1);
    auto box = Factory::create(FigType::BOX, 1, 1);




    return 0;
}
