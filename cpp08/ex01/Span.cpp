#include"Span.hpp"

// Span::Span(void){
// 	size = 0;
// 	it = 0;
// }

Span::Span(unsigned int n){
	size = n;
	it = 0;
}

Span::~Span(void){}

Span::Span(const Span &sp){
	*this = sp;
}

Span	&Span::operator=(const Span &sp){
	unsigned int i;
	
	i = 0;
	this->size =sp.size;
	this->it = sp.it;
	this->arr.resize(size);
	this->sarr.resize(size);
	while(i < this->it){
		this->arr[i] = sp.arr[i];
		this->sarr[i] = sp.sarr[i];
		i++;
	}
	return *this;
}

void	Span::addNumber(int i){
	if(it < size)
	{
		this->arr.push_back(i);
		this->sarr.push_back(i);
		it++;
		std::sort(sarr.begin(),sarr.end());
	}
	else
		throw std::out_of_range("\033[31mThis number can't be added because it exceeds the size limit!\033[0m");
}

void	Span::getArr(void){
	for(unsigned int i = 0; i< it;i++){
		std::cout<<this->arr[i]<<" ";
	}
	std::cout<<std::endl;
}


int	Span::shortestSpan(void){
	int s;
	s = INT_MAX;
	if(this->arr.size() <= 1)
		throw std::length_error("\033[31mNo span add more numbers\033[0m");
	for(unsigned int i = 0;i < it - 1;i++){
		if( sarr[i + 1] - sarr[i] < s){
			s = sarr[i + 1] - sarr[i];
		}
	}
	return(s);
}

int	Span::longestSpan(void){
	int s;
	if(this->arr.size() <= 1)
		throw std::length_error("\033[31mNo span add more numbers\033[0m");
	s = sarr[it - 1] - sarr[0];
	return(s);
}

