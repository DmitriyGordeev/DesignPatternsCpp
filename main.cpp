#include <iostream>
#include "singleton.h"
#include "factory.h"
#include "builder.h"
#include "adapter.h"
#include "decorator.h"
#include "proxy.h"


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
    std::cout << "--- adapter ---" << std::endl;
    CppFunc* cppFunc = new CppFunc();
    adapterUsageExample(cppFunc);

    PyFunc* pyFunc = new PyFunc();
    std::cout << pyFunc->getFuncDef() << std::endl;
    CppFunc* adapter = new PyToCppAdapter(pyFunc);
    adapterUsageExample(adapter);

    delete cppFunc;
    delete pyFunc;
    delete adapter;


    /* decorator example */
    std::cout << "--- decorator ---" << std::endl;
    Object* obj = new Object(10, "Name");
    Decorator* decorator = new Decorator(obj);
    decoratorUsageExample(obj);
    decoratorUsageExample(decorator);
    delete obj;
    delete decorator;


    /* proxy example */
    proxy::IHeavyObject* heavyObject = new proxy::SomeHeavyObject(10);
    heavyObject->init();

    proxy::IHeavyObject* proxyHeavyObject = new proxy::ProxyHeavyObject(10);
    proxyHeavyObject->init();


    return 0;
}
