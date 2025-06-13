#include"Point.hpp"

Point::Point(void):x(0),y(0){
    std::cout << "Default constructor called"<< std::endl;
}

Point   &Point::operator=(Point const &pt){
    if (this != &pt)
    {
        (Fixed) this->y = pt.y;
        (Fixed) this->x = pt.x;
    }
    return *this;
}

Point::Point(const float x, const float y):x(x),y(y){
    // std::cout << "Constructor called"<< std::endl;
}

Point::Point(Point const &pt):x(pt.x),y(pt.y){
    // std::cout << "copy constructor called"<< std::endl;
}

Point::~Point(void){

}