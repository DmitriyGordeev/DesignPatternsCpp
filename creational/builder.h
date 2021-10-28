#ifndef DESIGNPATTERNSCPP_BUILDER_H
#define DESIGNPATTERNSCPP_BUILDER_H

#include <memory>

class NestedObject1 {
public:
    NestedObject1(): _c('0'), _f(12.2f) {}

private:
    char _c;
    float _f;

};

class NestedObject2 {
public:
    NestedObject2(): _x(0), _y(12), _z(100.1f) {}

private:
    int _x;
    int _y;
    float _z;
};

class SomeComplexObject {
public:

    SomeComplexObject() {}

    void setC(char c) { _c = c; }
    void setI(int i) { _i = i; }
    void setF(float f) { _f = f; }
    void setNestedObject1(NestedObject1* n1) { _n1 = n1; }
    void setNestedObject2(NestedObject2* n2) { _n2 = n2; }
    void setCPtr(char* c_ptr) { _c_ptr = c_ptr; }

    static std::unique_ptr<SomeComplexObject> buildType1(NestedObject1* n1, NestedObject2* n2) {
        std::unique_ptr<SomeComplexObject> out = std::make_unique<SomeComplexObject>();
        out->setC('A');
        out->setI(17);
        out->setNestedObject1(n1);
        out->setNestedObject2(n2);
        out->setCPtr("Hello");
        return out;
    }

    static std::unique_ptr<SomeComplexObject> buildType2(NestedObject1* n1, NestedObject2* n2) {
        std::unique_ptr<SomeComplexObject> out = std::make_unique<SomeComplexObject>();
        out->setC('B');
        out->setI(19);
        out->setNestedObject1(n1);
        out->setNestedObject2(n2);
        out->setCPtr("Hello");
        return out;
    }

private:
    char _c;
    int _i;
    float _f;
    NestedObject1* _n1;
    NestedObject2* _n2;
    char* _c_ptr;

};

#endif //DESIGNPATTERNSCPP_BUILDER_H
