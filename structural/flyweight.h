#ifndef DESIGNPATTERNSCPP_FLYWEIGHT_H
#define DESIGNPATTERNSCPP_FLYWEIGHT_H

#include <string>
#include <unordered_map>


namespace flyweight {

    struct SharedState {
    public:
        SharedState(const std::string& brand,
                    const std::string& model,
                    const std::string& color): _brand(brand), _model(model), _color(color) {}

        friend std::ostream& operator << (std::ostream& os, const SharedState& sharedState) {
            return os << "brand=" << sharedState._brand << ", model=" << sharedState._model << ", color=" << sharedState._color;
        }

        std::string _brand;
        std::string _model;
        std::string _color;
    };


    class UniqueState {
    public:
        UniqueState(const std::string& owner,
                    const std::string& plates): _owner(owner), _plates(plates) {}

    private:
        std::string _owner;
        std::string _plates;
    };


    class Flyweight {
    public:
        Flyweight(const SharedState* sharedState) : _sharedState(new SharedState(*sharedState)) {}

        Flyweight(const Flyweight& other): _sharedState(new SharedState(*other._sharedState)) {}

        ~Flyweight() {
            delete _sharedState;
        }

        SharedState* getSharedState() const {
            return _sharedState;
        }

        void doSomething(const UniqueState& uniqueState) const {
            std::cout << "[Flyweight.doSomething()] using shared state:" << *_sharedState << std::endl;
        }

    private:
        SharedState* _sharedState;
    };


    class FlyweightFactory {
    public:
        FlyweightFactory(std::initializer_list<SharedState> states) {
            for (const auto& s : states) {
                this->_flyweights.insert(std::make_pair<std::string, Flyweight>(this->getKey(s), Flyweight(&s)));
            }
        }

        Flyweight get(const SharedState& sharedState) {
            std::string key = this->getKey(sharedState);
            if (this->_flyweights.find(key) == this->_flyweights.end()) {
                std::cout << "can't find a flyweight, creating a new one" << std::endl;
                this->_flyweights.insert(std::make_pair(key, Flyweight(&sharedState)));
            }
            else {
                std::cout << "reusing existing flyweight" << std::endl;
            }

            return this->_flyweights.at(key);
        }


        void listFlyweights() const {
            size_t count = this->_flyweights.size();
            std::cout << "total flyweights:" << count << std::endl;
            for (const auto& p : _flyweights) {
                std::cout << p.first << std::endl;
            }
        }


    private:
        std::unordered_map<std::string, Flyweight> _flyweights;

        std::string getKey(const SharedState& sharedState) {
            return sharedState._brand + "_" + sharedState._model + "_" + sharedState._color;
        }
    };


    void addCar(FlyweightFactory& factory,
                const std::string& plates, const std::string& owner,
                const std::string& brand, const std::string& model, const std::string& color) {

        std::cout << "adding a car" << std::endl;
        const Flyweight& flyweight = factory.get({brand, model, color});
        flyweight.doSomething({owner, plates});
    }

}

#endif //DESIGNPATTERNSCPP_FLYWEIGHT_H
