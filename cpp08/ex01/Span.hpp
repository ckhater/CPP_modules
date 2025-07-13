#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<vector>
#include<list>
#include<climits>

class Span{
	private:
		unsigned int		size;
		unsigned int		it;
		std::vector<int>	arr;
		std::vector<int>	sarr;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &sp);
		Span &operator=(const Span &sp);
		~Span(void);
		void	addNumber(int i);
		void	getArr(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		template<typename T> void fillSpan(T &cont){
			if(cont.size() + this->it  > this->size)
				throw std::out_of_range("\033[31mThis number can't be added because it exceeds the size limit!\033[0m");
			arr.insert(arr.begin(),cont.begin(), cont.end());
			sarr.insert(sarr.begin(),cont.begin(), cont.end());
			std::sort(sarr.begin(),sarr.end());
			it = static_cast<unsigned int>(cont.size());
		}
};

#endif
