#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Elements in MutantStack:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "\n==========  STD::LIST ==========" << std::endl;
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "Top element: " << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << "Size after pop: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::cout << "Elements in List:"<< std::endl;
    for (std::list<int>::iterator lit = mlist.begin(); lit != mlist.end(); ++lit)
    {
        std::cout << *lit << std::endl;
    }
	return 0;
}