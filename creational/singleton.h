#ifndef DESIGNPATTERNSCPP_SINGLETON_H
#define DESIGNPATTERNSCPP_SINGLETON_H

class Singleton {
private:
    static Singleton* _instance;
    int _data;

    explicit Singleton(int data) : _data(data) {}

    ~Singleton() = default;

public:
    static Singleton* getInstance(int data) {
        if (_instance == nullptr)
            _instance = new Singleton(data);
        return _instance;
    }

    int doSomething(int a) {
        return a * _data;
    }

    Singleton(const Singleton& s) = delete;
    void operator = (const Singleton &) = delete;
};

Singleton* Singleton::_instance{nullptr};

#endif //DESIGNPATTERNSCPP_SINGLETON_H
