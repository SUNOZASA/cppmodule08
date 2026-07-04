#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <exception>
#include <climits>
#include <iostream>

Span::Span() : N(0) {}

Span::Span(unsigned int N_) : N(N_) {}

Span::Span(const Span & other) : N(other.N) {
	v = other.v;
}

Span&	Span::operator=(const Span & other) {
	if (this == &other)
		return *this;
	N = other.N;
	v = other.v;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(const int & num) {
	if (v.size() == N)
		throw std::runtime_error("Full");
	v.push_back(num);
}

void	Span::addNumber(std::vector<int> & v_) {
	if (v.size() + v_.size() > N)
		throw std::runtime_error("Full");
	v.insert(v.end(), v_.begin(), v_.end());
}

unsigned int	Span::shortestSpan() {
	unsigned int	spMin = UINT_MAX;
	unsigned int	sp;

	if (v.size() <= 1)
		throw std::runtime_error("Size <= 1");
	std::vector<int>::iterator i = v.begin();
	i++;
	for (; i != v.end(); i++) {
		if (*i >= *(i - 1))
			sp = *i - *(i - 1);
		else
			sp = *(i - 1) - *i;
		if (sp <= spMin)
			spMin = sp;
	}
	return spMin;
}

unsigned int	Span::longestSpan() {
	unsigned int	spMax = 0;
	unsigned int	sp;

	if (v.size() <= 1)
		throw std::runtime_error("Size <= 1");
	std::vector<int>::iterator i = v.begin();
	i++;
	for (; i != v.end(); i++) {
		if (*i >= *(i - 1))
			sp = *i - *(i - 1);
		else
			sp = *(i - 1) - *i;
		if (sp >= spMax)
			spMax = sp;
	}
	return spMax;
}
