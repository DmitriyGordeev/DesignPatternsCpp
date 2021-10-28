#include <iostream>
#include "singleton.h"
#include "factory.h"
#include "builder.h"

int main() {

    /* singleton usage */
    auto S = Singleton::getInstance(20);
    int b = S->doSomething(10);

    /* factory usage */
    auto circle = Factory::create(FigType::CIRCLE, 1, 1);
    auto box = Factory::create(FigType::BOX, 1, 1);

    /* builder */
    NestedObject1* n1 = new NestedObject1();
    NestedObject2* n2 = new NestedObject2();
    std::unique_ptr<SomeComplexObject> instance1 = SomeComplexObject::buildType1(n1, n2);


    return 0;
}
