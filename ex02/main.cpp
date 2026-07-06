#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

int main()
{
	std::cout << "=====test1=====" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5); mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); mstack.push(5); mstack.push(737); mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it; --it;
	std::cout << "mstack: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << ";" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "=====test2=====" << std::endl;
	std::list<int> l;
	l.push_back(5); l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3); l.push_back(5); l.push_back(737); l.push_back(0);
	std::list<int>::iterator l_it = l.begin();
	std::list<int>::iterator l_ite = l.end();
	++l_it; --l_it;
	std::cout << "l: ";
	while (l_it != l_ite) {
		std::cout << *l_it << " ";
		++l_it;
	}
	std::cout << ";" << std::endl;

	std::cout << "=====test3=====" << std::endl;
	MutantStack<int> mstack_copy(mstack);
	MutantStack<int> mstack_assign = mstack;
	std::cout << "mstack_copy size: " << mstack_copy.size() << ", top: " << mstack_copy.top() << std::endl;
	std::cout << "mstack_assign size: " << mstack_assign.size() << ", top: " << mstack_assign.top()<< std::endl;
	mstack_copy.pop();
	mstack_assign.pop();
	std::cout << "mstack size: " << mstack.size() << ", top: " << mstack.top()<< std::endl;
	std::cout << "mstack_copy size: " << mstack_copy.size() << ", top: " << mstack_copy.top()<< std::endl;
	std::cout << "mstack_assign size: " << mstack_assign.size() << ", top: " << mstack_assign.top()<< std::endl;

	std::cout << "=====test4=====" << std::endl;
	const MutantStack<int> mstack_const(mstack);
	MutantStack<int>::const_iterator it_const = mstack_const.begin();
	MutantStack<int>::const_iterator ite_const = mstack_const.end();
	++it_const; --it_const;
	std::cout << "mstack_const: ";
	while (it_const != ite_const) {
		std::cout << *it_const << " ";
		++it_const;
	}
	std::cout << ";" << std::endl;
	const std::stack<int> s_const(mstack_const);

	std::cout << "=====test5=====" << std::endl;
	std::stack<int>		s_empty;
	MutantStack<int>	m_empty;
	std::cout << "s_empty size: " << s_empty.size() << ", m_empty size: " << m_empty.size() << std::endl;

	std::cout << "=====test6=====" << std::endl;
	std::cout << "mstack top:" << mstack.top() << std::endl;
	mstack.push(42); mstack.push(84);
	std::cout << "mstack top:" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack top:" << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack top:" << mstack.top() << std::endl;

	std::cout << "=====test7=====" << std::endl;
	it = mstack.begin();
	std::cout << "mstack ++: ";
	while (it != ite) {
		*it += 1;
		std::cout << *it << " ";
		it++;
	}
	std::cout << ";" << std::endl;

	std::cout << "=====test8=====" << std::endl;
	MutantStack<std::string> mstack_str;
	mstack_str.push("Hello world!"); mstack_str.push("Good morning!"); mstack_str.push("See you!");
	MutantStack<std::string>::iterator it_str = mstack_str.begin();
	MutantStack<std::string>::iterator ite_str = mstack_str.end();
	while (it_str != ite_str) {
		std::cout << *it_str << std::endl;
		it_str++;
	}

	std::cout << "=====test9=====" << std::endl;
	MutantStack<int>	mstack2;
	mstack2.push(5); mstack2.push(2); mstack2.push(8); mstack2.push(4); mstack2.push(6);
	MutantStack<int>::iterator	it2 = mstack2.begin();
	MutantStack<int>::iterator	ite2 = mstack2.end();
	std::cout << "mstack2 before sort: ";
	while (it2 != ite2) {
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << ";" << std::endl;
	std::sort(mstack2.begin(), mstack2.end());
	it2 = mstack2.begin();
	std::cout << "mstack2 after sort: ";
	while (it2 != ite2) {
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << ";" << std::endl;
	std::cout << "mstack2 find: ";
	MutantStack<int>::iterator it2_find = std::find(mstack2.begin(), mstack2.end(), 111);
	if (it2_find == mstack2.end())
		std::cout << "Not found" << std::endl;
	else
		std::cout << "Found " << *it2_find << std::endl;
	std::cout << "===============" << std::endl;
	return 0;
}
