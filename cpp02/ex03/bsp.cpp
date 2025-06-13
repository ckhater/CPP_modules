#include"Point.hpp"

bool operator&&(Fixed const &fix1, Fixed const &fix2){
    if(fix1.toFloat()==1 && fix2.toFloat() == 1)
        return true;
    return false;
}

Fixed   Point::halfPlaneMeth(Point const a, Point const b, Point const point)
{
    return ((b.x - a.x) * (point.y - a.y)) - ((b.y - a.y) * (point.x - a.x));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed   i;
    Fixed   j;
    Fixed   k;

    i = Point::halfPlaneMeth(a, b, point);
    // std::cout<<"i=="<<i.toFloat()<<std::endl;
    j = Point::halfPlaneMeth(b, c, point);
    // std::cout<<"j=="<<j.toFloat()<<std::endl;
    k = Point::halfPlaneMeth(c, a, point);
    // std::cout<<"k=="<<k.toFloat()<<std::endl;
    if(i > 0 && j > 0 && k > 0)
        return true;
    return false;
}
