#include "easyfind.hpp"
#include <string>
#include <vector>
#include <deque>
#include <iostream>

int	main() {
	std::vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	std::deque<int> d;
	d.push_back(0);
	d.push_back(1);
	d.push_front(2);
	d.push_back(3);
	d.push_front(4);
	int	num_not_found = 10;

	std::vector<int>::iterator vit = easyfind(v, 3);
	std::cout << "found " << *vit << std::endl;
	try {
		vit = easyfind(v, num_not_found);
		std::cout << "found " << *vit << std::endl;
	} catch(const std::exception & e) {
		std::cerr << num_not_found << " " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::deque<int>::iterator dit = easyfind(d, 2);
	std::cout << "found " << *dit << std::endl;
}
