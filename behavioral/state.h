#ifndef DESIGNPATTERNSCPP_STATE_H
#define DESIGNPATTERNSCPP_STATE_H

namespace state {

    class Context;

    class State {
    public:
        virtual ~State() = default;
        virtual void action1() = 0;
        virtual void action2() = 0;

        void setContext(Context* context) {
            _context = context;
        }

        std::string getName() const {
            return _name;
        }

    protected:
        Context* _context;
        std::string _name;
    };


    class Context {
    public:
        explicit Context(State* state): _state(nullptr) {
            changeState(state);
        }

        ~Context() {
            delete _state;
        }

        void changeState(State* state) {
            if (_state)
                delete _state;
            _state = state;
            _state->setContext(this);
            std::cout << "changeState(): state is " << _state->getName() << std::endl;
        }

        void request1() {
            _state->action1();
        }

        void request2() {
            _state->action2();
        }

    private:
        State* _state;
    };


    class RealStateA: public State {
    public:

        RealStateA() {
            _name = "A";
        }

        void action1() override {
            std::cout << "RealStateA.action1()" << std::endl;
        }

        void action2() override;
    };

    class RealStateB: public State {
    public:
        RealStateB() {
            _name = "B";
        }

        void action1() override {
            std::cout << "RealStateB.action1()" << std::endl;
            _context->changeState(new RealStateA);
        }
        void action2() override {
            std::cout << "RealStateB.action2()" << std::endl;
            _context->changeState(new RealStateA);
        }

    };

    void RealStateA::action2() {
        std::cout << "RealStateA.action2()" << std::endl;
        _context->changeState(new RealStateB);
    }


}

#endif //DESIGNPATTERNSCPP_STATE_H
