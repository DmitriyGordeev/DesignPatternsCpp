#ifndef DESIGNPATTERNSCPP_OBSERVER_H
#define DESIGNPATTERNSCPP_OBSERVER_H

#include <list>
#include <string>

namespace observer {

    class IObserver {
    public:
        virtual ~IObserver() = default;
        virtual void update(const std::string& event) = 0;
    };

    class IPublisher {
    public:
        virtual ~IPublisher() = default;
        virtual void subscribe(IObserver* observer) = 0;
        virtual void unsubscribe(IObserver* observer) = 0;
        virtual void notifyAll() = 0;
    };



    class Publisher: public IPublisher {
    public:
        virtual ~Publisher() {}

        void subscribe(IObserver* observer) override {
            _observers.push_back(observer);
        }

        void unsubscribe(IObserver* observer) override {
            _observers.remove(observer);
        }

        void notifyAll() override {
            for (const auto& o : _observers) {
                o->update(_event);
            }
        }

        // example usage of .notifyAll() when something important happened
        void clientCodeExample(const std::string& event) {
            this->_event = event;
            this->notifyAll();
        }

    private:
        std::list<IObserver*> _observers;
        std::string _event;
    };


    class Observer: public IObserver {
    public:
        explicit Observer(Publisher& publisher): _publisher(publisher) {
            this->_publisher.subscribe(this);
            _s_num++;
            _id = Observer::_s_num;
            std::cout << "Observer{" << _id << "} is now observing the publisher" << std::endl;
        }

        ~Observer() {}

        void update(const std::string& event) override {
            _publisherEvent = event;
            std::cout << "Observer{" << _id << "}: observing new event from the publisher = " << _publisherEvent << std::endl;
        }

        void unsubscribe() {
            _publisher.unsubscribe(this);
            std::cout << "Observer{" << _id << "} unsubscribed" << std::endl;
        }


    private:
        std::string _publisherEvent;
        Publisher& _publisher;
        int _id;
        static int _s_num;
    };

    int Observer::_s_num = 0;

}

#endif //DESIGNPATTERNSCPP_OBSERVER_H
