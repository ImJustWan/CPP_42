#include "MutantStack.hpp"

int main()
{
	std::cout << _GREY "\n🔹 Doing stuff 🔹\n" _END << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << _GREY "\n🔹 Display value on top of stack 🔹\n" _END << std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << _GREY "\n🔹 Display size of stack 🔹\n" _END << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << _GREY "\n🔹 Display stack 🔹\n" _END << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
