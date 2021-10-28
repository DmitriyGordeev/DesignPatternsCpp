#ifndef DESIGNPATTERNSCPP_BUILDER_H
#define DESIGNPATTERNSCPP_BUILDER_H

#include <string>
#include <memory>


class Person {
public:

    class Builder {
    public:
        explicit Builder(Person* person) : _person(person) {}

        Builder* setId(int id) {
            _person->_id = id;
            return this;
        }

        Builder* setFirstName(const std::string& firstName) {
            _person->_firstName = firstName;
            return this;
        }

        Builder* setSecondName(const std::string& secondName) {
            _person->_secondName = secondName;
            return this;
        }

        Builder* setEmail(const std::string& email) {
            _person->_email = email;
            return this;
        }

        Person* build() {
            return _person;
        }

    private:
        Person* _person;
    };


    static Builder* getBuilder() {
        Person* p = new Person();
        Builder* b = new Builder(p);
        return b;
    }


private:
    int _id;
    std::string _firstName;
    std::string _secondName;
    std::string _email;

    Person() = default;
};

#endif //DESIGNPATTERNSCPP_BUILDER_H
