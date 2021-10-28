#ifndef DESIGNPATTERNSCPP_BUILDER_H
#define DESIGNPATTERNSCPP_BUILDER_H

#include <string>
#include <memory>


class Person {
public:

    Person() = default;

    class Builder {
    public:
        explicit Builder(std::unique_ptr<Person> person) : _person(std::move(person)) {}

        Builder* setId(int id) {
            _person->_id = id;
            return this;
        }

        ~Builder() {
            _person = nullptr;
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

        std::unique_ptr<Person> build() {
            return std::move(_person);
        }

    private:
        std::unique_ptr<Person> _person;
    };


    static Builder* getBuilder() {
        std::unique_ptr<Person> p = std::make_unique<Person>();
        Builder* b = new Builder(std::move(p));
        return b;
    }


private:
    // it's assumed we have many properties here
    int _id;
    std::string _firstName;
    std::string _secondName;
    std::string _email;
};

#endif //DESIGNPATTERNSCPP_BUILDER_H
