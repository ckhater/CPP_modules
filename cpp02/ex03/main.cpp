#include"Point.hpp"

int main(){
    Point const p(3,0);
    Point const a(1,2);
    Point const b(0,0);
    Point const c(2,0);
    Point const pv(1,1);

    std::cout << bsp(a,b,c,p)<<std::endl;
    std::cout << bsp(a,b,c,pv)<<std::endl;
	Point const d(0,0);
    std::cout << bsp(a,b,c,d)<<std::endl;
    return(0);
}
