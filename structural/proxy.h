#ifndef DESIGNPATTERNSCPP_PROXY_H
#define DESIGNPATTERNSCPP_PROXY_H
#include <iostream>

namespace proxy {
    class IHeavyObject {
    public:
        virtual ~IHeavyObject() {}
        virtual void init() = 0;
    };


    class SomeHeavyObject : public IHeavyObject {
    public:
        explicit SomeHeavyObject(size_t size) {
            _size = size;
            _iData = new int[size];
            _fData = new float[size];
            std::cout << "[proxy::SomeHeavyObject constructor] allocating data" << std::endl;
        }

        ~SomeHeavyObject() override {
            delete[] _iData;
            delete[] _fData;
            _iData = nullptr;
            _fData = nullptr;
        }

        void init() override {
            for (int i = 0; i < _size; i++) {
                _iData[i] = i;
                _fData[i] = i * 0.1f;
            }
        }

    private:
        size_t _size;
        int *_iData;
        float *_fData;
    };


    class ProxyHeavyObject: public IHeavyObject {
    public:
        ProxyHeavyObject(size_t size): _size(size), _heavyObject(nullptr) {}

        void init() override {
            if (!_heavyObject) {        // create an object if not created yet - do heavy work on demand
                std::cout << "[proxy::ProxyHeavyObject init()] allocating data" << std::endl;
                _heavyObject = new SomeHeavyObject(_size);
            }
            _heavyObject->init();
        }

    private:
        size_t _size;
        SomeHeavyObject* _heavyObject;
    };
}


#endif //DESIGNPATTERNSCPP_PROXY_H
