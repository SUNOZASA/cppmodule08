#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Span	sp1(5);
	Span	sp1_copy1 = sp1;
	Span	sp1_copy2(sp1);
	sp1.addNumber(6); sp1.addNumber(3); sp1.addNumber(17); sp1.addNumber(9); sp1.addNumber(11);
	sp1_copy1.addNumber(10); sp1_copy1.addNumber(1);
	sp1_copy2.addNumber(10); sp1_copy2.addNumber(1);
	std::cout << "=====test1=====" << std::endl;
	std::cout << "sp1 shortestSpan: " << sp1.shortestSpan() << ", longestSpan: " << sp1.longestSpan() << std::endl;
	std::cout << "sp1_copy1 shortestSpan: " << sp1_copy1.shortestSpan() << ", longestSpan: " << sp1_copy1.longestSpan() << std::endl;
	std::cout << "sp1_copy2 shortestSpan: " << sp1_copy2.shortestSpan() << ", longestSpan: " << sp1_copy2.longestSpan() << std::endl;
	try { 
		sp1.addNumber(8);
	} catch (const std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Span	sp3(0);
	Span	sp4(1);
	sp4.addNumber(0);
	std::cout << "=====test2=====" << std::endl;
	try { 
		sp3.shortestSpan();
	} catch (const std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try { 
		sp4.shortestSpan();
	} catch (const std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Span	sp5(5);
	std::vector<int>	v;
	v.push_back(1); v.push_back(3); v.push_back(7); v.push_back(13); v.push_back(21);
	sp5.addNumber(v);
	std::cout << "=====test3=====" << std::endl;
	std::cout << "sp5 shortestSpan(): " << sp5.shortestSpan() << ", longestSpan(): " << sp5.longestSpan() << std::endl;
	try {
		sp5.addNumber(v);
	} catch (const std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	unsigned int	count = 16384;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	Span sp6(count);
	for (unsigned int i = 0; i < count; i++)
		sp6.addNumber(std::rand());
	std::cout << "=====test4=====" << std::endl;
	std::cout << "sp6 shortestSpan(): " << sp6.shortestSpan() << ", longestSpan(): " << sp6.longestSpan() << std::endl;

	std::cout << "===============" << std::endl;
}
