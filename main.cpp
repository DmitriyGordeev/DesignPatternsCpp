#include <iostream>
#include "singleton.h"
#include "factory.h"
#include "builder.h"
#include "adapter.h"
#include "decorator.h"
#include "proxy.h"
#include "flyweight.h"
#include "chain_of_responsibility.h"
#include "controller.h"
#include "observer.h"
#include "state.h"
#include "visitor.h"


int main() {

    /* singleton example */
    auto S = Singleton::getInstance(20);
    int b = S->doSomething(10);


    /* factory example */
    auto circle = factory::Factory::create(factory::FigType::CIRCLE, 1, 1);
    auto box = factory::Factory::create(factory::FigType::BOX, 1, 1);


    /* builder example */
    builder::Person::Builder *personBuilder = builder::Person::getBuilder();
    std::unique_ptr<builder::Person> p = personBuilder->setId(11)
            ->setFirstName("FirstName")
            ->setSecondName("SecondName")
            ->setEmail("Email")
            ->build();
    delete personBuilder;


    /* adapter example */
    std::cout << "--- adapter ---" << std::endl;
    adapter::CppFunc* cppFunc = new adapter::CppFunc();
    adapter::adapterUsageExample(cppFunc);

    adapter::PyFunc* pyFunc = new adapter::PyFunc();
    std::cout << pyFunc->getFuncDef() << std::endl;
    adapter::CppFunc* adapter = new adapter::PyToCppAdapter(pyFunc);
    adapter::adapterUsageExample(adapter);
    delete cppFunc;
    delete pyFunc;
    delete adapter;


    /* decorator example */
    std::cout << "--- decorator ---" << std::endl;
    decorator::Object* obj = new decorator::Object(10, "Name");
    decorator::Decorator* decorator = new decorator::Decorator(obj);
    decorator::decoratorUsageExample(obj);
    decorator::decoratorUsageExample(decorator);
    delete obj;
    delete decorator;


    /* proxy example */
    proxy::IHeavyObject* heavyObject = new proxy::SomeHeavyObject(10);
    heavyObject->init();
    proxy::IHeavyObject* proxyHeavyObject = new proxy::ProxyHeavyObject(10);
    proxyHeavyObject->init();


    /* flyweight */
    std::cout << std::endl << "--- flyweight ---" << std::endl;
    flyweight::FlyweightFactory* ff = new flyweight::FlyweightFactory({
            {"Chevrolet", "Camaro", "black"},
            {"Aston Martin", "DB9", "silver"},
            {"BMW", "x5", "red"}});

    ff->listFlyweights();
    flyweight::addCar(*ff, "D928", "James Bond", "Aston Martin", "DB9", "silver");
    flyweight::addCar(*ff, "A672", "Lara Croft", "Mazda", "X", "red");
    delete ff;


    /* chain of responsibility */
    std::cout << std::endl << "--- chain of responsibility ---" << std::endl;
    chain_of_responsibility::BusHandler* bus = new chain_of_responsibility::BusHandler;
    chain_of_responsibility::AirplaneHandler* airplane = new chain_of_responsibility::AirplaneHandler;
    chain_of_responsibility::ShipHandler* ship = new chain_of_responsibility::ShipHandler;

    // constructing the chain:
    bus->setNext(airplane)->setNext(ship);
    // usage
    chain_of_responsibility::usageExample(*bus);



    /* controller example: */
    std::cout << std::endl << "--- controller ---" << std::endl;
    controller::ComponentA* cA = new controller::ComponentA;
    controller::ComponentB* cB = new controller::ComponentB;
    controller::RealController* rc = new controller::RealController(cA, cB);

    cA->action2();
    std::cout << std::endl;
    cB->action1();
    delete cA;
    delete cB;
    delete rc;


    /* observer */
    std::cout << std::endl << "--- observer ---" << std::endl;
    observer::Publisher publisher;
    observer::Observer o1(publisher);
    observer::Observer o2(publisher);
    observer::Observer o3(publisher);
    observer::Observer o4(publisher);

    publisher.clientCodeExample("event A");
    observer::Observer o5(publisher);
    o1.unsubscribe();
    publisher.clientCodeExample("event B");



    /* state */
    std::cout << std::endl << "--- state ---" << std::endl;
    state::Context context(new state::RealStateA);
    context.request1();
    context.request2();



    /* visitor */
    std::cout << std::endl << "--- visitor ---" << std::endl;
    visitor::XMLVisitorExample visitor;

    // simple example
    std::vector<visitor::IObject*> objects;
    objects.emplace_back(new visitor::ObjectA);
    objects.emplace_back(new visitor::ObjectB("Red", "Color"));
    objects.emplace_back(new visitor::ObjectB("Large", "Size"));
    for (auto e : objects) {
        std::cout << e->accept(&visitor) << std::endl;
    }

    for (auto e : objects)
        delete e;




    return 0;
}
