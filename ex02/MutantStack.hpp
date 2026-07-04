#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T> & other) : std::stack<T>(other) {}
	~MutantStack() {}
	MutantStack& operator=(const MutantStack & other) {
		if (this == &other)
			return *this;
		std::stack<T>::operator=(other);
		return *this;
	}

	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
};

#endif
