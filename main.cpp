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
    Person::Builder* personBuilder = Person::getBuilder();
    Person* p = personBuilder->setId(11)
                ->setFirstName("FirstName")
                ->setSecondName("SecondName")
                ->setEmail("Email")
                ->build();

    delete personBuilder;

    return 0;
}
