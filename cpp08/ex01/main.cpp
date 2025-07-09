#include"Span.hpp"

int main(){
	try{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.getArr();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
catch(std::exception &e){
	std::cout<<e.what()<<std::endl;
}
try{
	Span sp(5);
	std::list<int> l;

	l.push_back(78);
	l.push_back(12);
	l.push_back(98);
	sp.fillSpan(l);
	// sp.getArr();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
catch(std::exception &e){
	std::cout<<e.what()<<std::endl;
}
return 0;
}
