#include <utility>

#ifndef DESIGNPATTERNSCPP_VISITOR_H
#define DESIGNPATTERNSCPP_VISITOR_H

namespace visitor {

    class ObjectA;

    class ObjectB;


    class XMLVisitorExample {
    public:
        std::string getXmlObjectA(ObjectA *objectA);

        std::string getXmlObjectB(ObjectB *objectB);
    };


    class IObject {
    public:
        virtual std::string accept(XMLVisitorExample *visitor) = 0;
        virtual ~IObject() = default;
    };


    class ObjectA : public IObject {
    public:
        explicit ObjectA() = default;

        std::string accept(XMLVisitorExample *visitor) override {
            return visitor->getXmlObjectA(this);
        }

        std::string getData() const {
            return "[" + std::to_string(_data[0]) + ","
                   + std::to_string(_data[1]) + ","
                   + std::to_string(_data[2]) + "]";
        }

    private:
        int _data[3]{1, 2, 3};
    };


    class ObjectB : public IObject {
    public:
        ObjectB(std::string value, std::string attr) : _value(std::move(value)), _attribute(std::move(attr)) {}

        std::string accept(XMLVisitorExample *visitor) override {
            return visitor->getXmlObjectB(this);
        }

        std::string getValue() const { return _value; }

        std::string getAttr() const { return _attribute; }

    private:
        std::string _value;
        std::string _attribute;
    };


    std::string XMLVisitorExample::getXmlObjectA(ObjectA *objectA) {
        return "<A>" + objectA->getData() + "</A>";
    }

    std::string XMLVisitorExample::getXmlObjectB(ObjectB *objectB) {
        return "<B attribute=\"" + objectB->getAttr() + "\">" + objectB->getValue() + "</B>";
    }


}

#endif //DESIGNPATTERNSCPP_VISITOR_H
