#include <iostream>
#include "singleton.h"
#include "factory.h"
#include "builder.h"
#include "adapter.h"


int main() {

    /* singleton example */
    auto S = Singleton::getInstance(20);
    int b = S->doSomething(10);


    /* factory example */
    auto circle = Factory::create(FigType::CIRCLE, 1, 1);
    auto box = Factory::create(FigType::BOX, 1, 1);


    /* builder example */
    Person::Builder *personBuilder = Person::getBuilder();
    std::unique_ptr<Person> p = personBuilder->setId(11)
            ->setFirstName("FirstName")
            ->setSecondName("SecondName")
            ->setEmail("Email")
            ->build();
    delete personBuilder;


    /* adapter example */
    CppFunc* cppFunc = new CppFunc();
    exampleUsageCode(cppFunc);

    PyFunc* pyFunc = new PyFunc();
    std::cout << pyFunc->getFuncDef() << std::endl;
    CppFunc* adapter = new PyToCppAdapter(pyFunc);
    exampleUsageCode(adapter);

    delete cppFunc;
    delete pyFunc;
    delete adapter;




    return 0;
}
