#ifndef DESIGNPATTERNSCPP_ADAPTER_H
#define DESIGNPATTERNSCPP_ADAPTER_H

namespace adapter {
    /** Little example of adapting python code to cpp code */

    class CppFunc {
    public:
        virtual ~CppFunc() = default;

        virtual std::string getFuncDefinition() const {
            return "void " + _func_name + "()";
        }

    private:
        std::string _func_name;
    };


    class PyFunc {
    public:
        std::string getFuncDef() const {
            return "def " + _func_name + "()";
        }

    private:
        std::string _func_name;
    };



    class PyToCppAdapter: public CppFunc {
    public:
        PyToCppAdapter(PyFunc* pyFunc) : _pyFunc(pyFunc) {}

        std::string getFuncDefinition() {
            std::string value = _pyFunc->getFuncDef();
            size_t pos = value.find(' ');
            if (pos != std::string::npos) {
                std::string name = value.substr(pos + 1);
                return "void " + name;
            }
            return "";
        }

    private:
        PyFunc* _pyFunc;
    };


    void adapterUsageExample(CppFunc* cppFunc) {
        std::cout << cppFunc->getFuncDefinition() << std::endl;
    }
}




#endif //DESIGNPATTERNSCPP_ADAPTER_H
