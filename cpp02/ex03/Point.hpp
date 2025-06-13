#ifndef POINT_HPP
#define POINT_HPP

#include"Fixed.hpp"

class Point{
    private:
        Fixed const x;
        Fixed const y;
        
    public:
        Point(void);
        Point(const float a, const float b);
        Point(Point const &pt);
        Point &operator=(Point const &pt);
        ~Point(void);
        static Fixed   halfPlaneMeth(Point const a, Point const b, Point const point);

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
bool operator&&(Fixed const &fix1, Fixed const &fix2);

#endif