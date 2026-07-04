#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T & container, int target) {
	typename T::iterator result
		= std::find(container.begin(), container.end(), target);
	if (result == container.end())
		throw std::runtime_error("Not Found");
	return result;
}

#endif
