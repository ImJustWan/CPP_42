#include "Span.hpp"
#include <vector>
#include <cstdlib> 
#define MAX_N 8888

int generateRandomNumber() {
	return rand() % 1000000;
}


int main()
{
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// Uncomment for FullSpanException
		// sp.addNumber(88);
		std::cout << _GREY "\n🔹 What is the shortest span in this vector ? 🔹" _END << std::endl;
		std::cout << sp.shortestSpan() << std::endl;

		std::cout << _GREY "\n🔹 What is the longest span in this vector ? 🔹" _END << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << _GREY "\n🔹 Removing 4/5 numbers 🔹" _END << std::endl;

	for (int i = 0; i < 4; i++)
		sp.removeNumber();
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << _BOLD _GREY "\n🔹 Creating STONK SPAN 🔹" _END << std::endl;

	std::vector<int>	smartSpan(88, 88);
	Span 				stonkSpan = Span(MAX_N);

	// smartSpan was created with '88' 500 times ; uncomment to print
	// for (std::vector<int>::iterator i = smartSpan.begin(); i != smartSpan.end(); ++i) {
	// 	std::cout << *i << std::endl;
	// }

	try {

		// Uncomment for MAX_N calls to addNumber (manual)
		for (unsigned int i = 0; i < stonkSpan.getMaxSize(); i++)
			stonkSpan.addNumber(generateRandomNumber());
		
		std::cout << "\nSize of SMART before : " << smartSpan.size() << std::endl;
		std::cout << "Size of STONK before : " << stonkSpan.getCurrSize() << std::endl;
		std::cout << _RIVIERA _ITALIC "\nInserting 12 elements from stonk.begin at smart.begin\n" _END << std::endl;
		
		smartSpan.insert(smartSpan.begin(), stonkSpan.getBegin(), stonkSpan.getBegin() + 12);

		std::cout << "Size of SMART after : " << smartSpan.size() << std::endl;
		for (std::vector<int>::iterator i = smartSpan.begin(); i != smartSpan.end(); ++i) {
		std::cout << *i << std::endl;
		}
		// stonkSpan.addNumber(smartSpan);

	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
