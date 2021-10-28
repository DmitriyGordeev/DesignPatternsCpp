#ifndef DESIGNPATTERNSCPP_DECORATOR_H
#define DESIGNPATTERNSCPP_DECORATOR_H

#include <iostream>

class IObject {
public:
    virtual std::string definition() const = 0;
};

class Object: public IObject {
public:
    Object(int id, const std::string& name): _id(id), _name(name) {}

    std::string definition() const override {
        return "Object.{" + std::to_string(_id) + "}.{" + _name + "}";
    }

private:
    int _id;
    std::string _name;
};


class Decorator: public IObject {
public:
    Decorator(Object* object): _object(object) {}

    std::string definition() const override {
        // simple decorator usage,
        // more advanced stuff can be here
        return "<tag>" + _object->definition() + "</tag>";
    }

private:
    Object* _object;
};


/* using a pointer to interface class for wide usage */
void decoratorUsageExample(IObject* obj) {
    std::cout << obj->definition() << std::endl;
}



#endif //DESIGNPATTERNSCPP_DECORATOR_H
