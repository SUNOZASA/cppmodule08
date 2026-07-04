#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
	unsigned int		N;
	std::vector<int>	v;
public:
	Span();
	Span(unsigned int N_);
	Span(const Span & other);
	Span& operator=(const Span & other);
	~Span();

	void			addNumber(const int & num);
	void			addNumber(std::vector<int> & v);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};

#endif
