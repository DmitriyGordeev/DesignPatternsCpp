#ifndef DESIGNPATTERNSCPP_CHAIN_OF_RESPONSIBILITY_H
#define DESIGNPATTERNSCPP_CHAIN_OF_RESPONSIBILITY_H

#include <string>
#include <iostream>


namespace chain_of_responsibility {

    class IHandler {
    public:
        virtual IHandler* setNext(IHandler* abstractHandler) = 0;
        virtual std::string handle(const std::string& request) = 0;
    };


    class Handler: public IHandler {
    public:
        Handler(): _nextHandler(nullptr) {}

        IHandler* setNext(IHandler* abstractHandler) override {
            this->_nextHandler = abstractHandler;
            return abstractHandler;
        }

        std::string handle(const std::string& request) override {
            if(this->_nextHandler) {
                return this->_nextHandler->handle(request);
            }
            return {};
        }

    private:
        IHandler* _nextHandler;
    };


    class BusHandler: public Handler {
    public:
        std::string handle(const std::string& request) override {
            if (request == "bus")
                return "vehicle: bus\n";
            else
                // pass the request to the next bind handler
                return Handler::handle(request);
        }
    };

    class AirplaneHandler: public Handler {
    public:
        std::string handle(const std::string& request) override {
            if (request == "plane")
                return "vehicle: airplane\n";
            else
                // pass the request to the next bind handler
                return Handler::handle(request);
        }
    };

    class ShipHandler: public Handler {
    public:
        std::string handle(const std::string& request) override {
            if (request == "ship")
                return "vehicle: ship\n";
            else
                // pass the request to the next bind handler
                return Handler::handle(request);
        }
    };


    void usageExample(IHandler& handler) {
        std::vector<std::string> food = {"ship", "plane", "bus", "plane", "helicopter"};
        for (const auto& f : food) {
            std::cout << "Tickets type:" << f;
            std::string result = handler.handle(f);

            if (!result.empty())
                std::cout << " =>" << result;
            else
                std::cout << " " << f << " - not used" << std::endl;
        }
    }




}



#endif //DESIGNPATTERNSCPP_CHAIN_OF_RESPONSIBILITY_H
