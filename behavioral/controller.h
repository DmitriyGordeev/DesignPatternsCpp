#ifndef DESIGNPATTERNSCPP_CONTROLLER_H
#define DESIGNPATTERNSCPP_CONTROLLER_H

namespace controller {

    class BComponent;

    class IController {
    public:
        virtual void notify(BComponent* component, const std::string& event) const = 0;
    };


    class BComponent {
    public:
        explicit BComponent(IController* controller = nullptr) : _controller(controller) {}

        void setController(IController* controller) {
            this->_controller = controller;
        }
    protected:
        IController* _controller;
    };


    class ComponentA: public BComponent {
    public:
        void action1() {
            std::cout << "ComponentA.action1()" << std::endl;
            this->_controller->notify(this, "A1");
        }

        void action2() {
            std::cout << "ComponentA.action2()" << std::endl;
            this->_controller->notify(this, "A2");
        }
    };


    class ComponentB: public BComponent {
    public:
        void action1() {
            std::cout << "ComponentB.action1()" << std::endl;
            this->_controller->notify(this, "B1");
        }

        void action2() {
            std::cout << "ComponentB.action2()" << std::endl;
            this->_controller->notify(this, "B2");
        }
    };


    // Implementing IController and binding actions in a way we need
    class RealController: public IController {
    public:
        RealController(ComponentA* cA, ComponentB* cB): _cA(cA), _cB(cB) {
            _cA->setController(this);
            _cB->setController(this);
        }

        void notify(BComponent* sender, const std::string& event) const override {
            std::cout << "controller event:" << event << std::endl;

            if (event == "A2") {
                _cB->action2();
            }

            if (event == "B1") {
                _cA->action1();
            }
        }

    private:
        ComponentA* _cA;
        ComponentB* _cB;
    };

}

#endif //DESIGNPATTERNSCPP_CONTROLLER_H
