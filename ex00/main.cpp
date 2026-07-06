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
	int	v_find = 3;
	int	d_find = 3;

	std::cout << "=====vector test=====" << std::endl;
	std::vector<int>::iterator vit;
	try {
		vit = easyfind(v, v_find);
		std::cout << "found" << *vit << std::endl;
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=====deque  test=====" << std::endl;
	std::deque<int>::iterator dit;
	try {
		dit = easyfind(d, d_find);
		std::cout << "found" << *dit << std::endl;
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
