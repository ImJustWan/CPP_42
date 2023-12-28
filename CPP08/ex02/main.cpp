#include "MutantStack.hpp"

// int main()
// {
// 	std::cout << _GREY "\n🔹 Creating a mutant stack 'mstack' 🔹\n" _END << std::endl;
	
// 	MutantStack<int> mstack;

// 	// Because MutantStack herited from stack, we can use the functions of stack
// 	mstack.push(88);
// 	mstack.push(1);
// 	std::cout << _GREY "\n🔹 top() : Display value on top of stack 🔹\n" _END << std::endl;
// 	std::cout << mstack.top() << std::endl;
// 	std::cout << _GREY "\n🔹 pop() : Remove element on top of stack 🔹\n" _END << std::endl;
// 	mstack.pop();
// 	std::cout << _GREY "\n🔹 size() : Display size of stack 🔹\n" _END << std::endl;
// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(42);
// 	mstack.push(5);


// 	std::cout << _GREY "\n🔹 Creating real stack sndStack by copy of mstack🔹\n" _END << std::endl;
// 	std::stack<int> sndStack(mstack);
// 	std::cout << _GREY "\nIs the new stack sndStack empty ? ➡ " _END;
// 	std::cout << (sndStack.empty() ? "True" : "False") << std::endl;


// 	std::cout << _GREY _ITALIC "\n Adding elements to sndStack" _END << std::endl;
// 	sndStack.push(737);
// 	sndStack.push(0);

// 	std::cout << _GREY "\nSize of mstack :\t" _END << mstack.size() << std::endl;
// 	std::cout << _GREY "\nSize of sndStack :\t" _END << sndStack.size() << std::endl;

// 	MutantStack<int>::iterator it = mstack.getBegin();
// 	MutantStack<int>::iterator ite = mstack.getEnd();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }



int main()
{
	std::cout << _GREY _RIVIERA _BOLD "\nCreating a list 'test_list'" _END << std::endl;
	std::cout << _GREY _ORANGE _BOLD"\nCreating a mutant stack 'mut_stack'\n" _END << std::endl;
	
	std::list<int>	test_list;
	MutantStack<int> mut_stack;

	// stack = vertical, list = horizontal
	// stack.push = list.push_back();

	std::cout << _GREY _ITALIC "\n🔹 push_back() : Add value at the top of stack 🔹" _END << std::endl;
	test_list.push_back(42);
	test_list.push_back(88);
	test_list.push_back(1);
	std::cout << _GREY _ITALIC "🔸 push() : Add value at the end of list 🔸\n" _END << std::endl;
	mut_stack.push(42);
	mut_stack.push(88);
	mut_stack.push(1);


	std::cout << _GREY "\n🔹 back() : Display value at the end of list ➭ " _END;
	std::cout << test_list.back() << " 🔹 " << std::endl;
	std::cout << _GREY "🔸 top() : Display value on top of stack ➭ " _END;
	std::cout << mut_stack.top() << " 🔸 " << std::endl;
	std::cout << _GREY _ITALIC "\n\n🔹 pop_back() : Remove element at the end of list 🔹" _END << std::endl;
	test_list.pop_back();
	std::cout << _GREY _ITALIC "🔸 pop() : Remove element on top of stack 🔸\n" _END << std::endl;
	mut_stack.pop();

	test_list.push_back(602214074);
	test_list.push_back(8397);
	mut_stack.push(602214074);
	mut_stack.push(8397);

	std::cout << _GREY "\n🔹 size() : Display size of list ➭ " _END;
	std::cout << test_list.size() << " 🔹 " << std::endl;
	std::cout << _GREY "🔸 size() : Display size of stack ➭ " _END;
	std::cout << mut_stack.size() << " 🔸 " << std::endl;

	std::cout << _GREY "\n\n\n🔹 Iteration to display the list 🔹\n" _END << std::endl;
	std::list<int>::iterator it_l = test_list.begin();
	std::list<int>::iterator ite_l = test_list.end();

	++it_l;
	--it_l;
	while (it_l != ite_l)
	{
		std::cout << *it_l << std::endl;
		++it_l;
	}

	std::cout << _GREY "\n🔸  Iteration to display the stack 🔸 \n" _END << std::endl;
	MutantStack<int>::iterator it_s = mut_stack.getBegin();
	MutantStack<int>::iterator ite_s = mut_stack.getEnd();

	++it_s;
	--it_s;
	while (it_s != ite_s)
	{
		std::cout << *it_s << std::endl;
		++it_s;
	}

	std::cout << _GREY "\n\n🔸 Creating real stack sndStack by copy of mut_stack 🔸\n" _END << std::endl;
	std::stack<int> sndStack(mut_stack);
	std::cout << _GREY "Is the new stack sndStack empty ? ➡ " _END;
	std::cout << (sndStack.empty() ? "True\n" : "False\n") << std::endl;
	return 0;
}
