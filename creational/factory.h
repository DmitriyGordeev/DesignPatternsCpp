#ifndef DESIGNPATTERNSCPP_FACTORY_H
#define DESIGNPATTERNSCPP_FACTORY_H
#include <iostream>
#include <memory>


namespace factory {

    class Figure {
    public:
        Figure(int x, int y): _x(x), _y(y) {}
        virtual ~Figure() {}
        virtual void render() = 0;

    protected:
        int _x;
        int _y;
    };


    class Circle: public Figure {
    public:
        Circle(int x, int y, int radius): Figure(x, y), _radius(radius) {}

        void render() {
            // some drawing methods ...
            std::cout << "Drawing a circle" << std::endl;
        }

    protected:
        int _radius;
    };


    class Box: public Figure {
    public:
        Box(int x, int y, int width, int height): Figure(x, y), _width(width), _height(height) {}

        void render() {
            // some drawing methods ...
            std::cout << "Drawing a box" << std::endl;
        }

    private:
        int _width;
        int _height;
    };


/** Factory class */
    enum FigType {
        CIRCLE,
        BOX
    };


    class Factory {
    public:
        static std::unique_ptr<Figure> create(FigType figType, int x, int y) {
            switch (figType) {
                case FigType::CIRCLE:
                    return std::make_unique<Circle>(x, y, 1);

                case FigType::BOX:
                    return std::make_unique<Box>(x, y, 1, 1);

                default:
                    return nullptr;
            }
        }
    };
}



#endif //DESIGNPATTERNSCPP_FACTORY_H
