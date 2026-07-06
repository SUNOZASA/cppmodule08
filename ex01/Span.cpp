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
		throw std::runtime_error("capacity is full");
	v.push_back(num);
}

void	Span::addNumber(std::vector<int> & v_) {
	if (v.size() + v_.size() > N)
		throw std::runtime_error("capacity is full");
	v.insert(v.end(), v_.begin(), v_.end());
}

unsigned int	Span::shortestSpan() {
	unsigned int	spMin = UINT_MAX;
	unsigned int	sp;

	if (v.size() <= 1)
		throw std::runtime_error("two or more elements are required");
	std::vector<int> sorted = v;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator it = sorted.begin();
	it++;
	for (; it != sorted.end(); ++it) {
		sp = *it - *(it - 1);
		if (sp <= spMin)
			spMin = sp;
	}
	return spMin;
}

unsigned int	Span::longestSpan() {
	if (v.size() <= 1)
		throw std::runtime_error("two or more elements are required");
	return *(std::max_element(v.begin(), v.end())) - *(std::min_element(v.begin(), v.end()));
}
