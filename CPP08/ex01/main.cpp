#include "Span.hpp"
#include <vector>
#include <cstdlib> 
#define MAX_N 18888

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

	for (int i = 0; i < 4; i++)
		sp.removeNumber();
	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << _BOLD _GREY "\n🔹 Creating STONK SPAN 🔹" _END << std::endl;

	Span 				stonkSpan = Span(MAX_N);
	std::vector<int>	smartSpan(500, 25);

	try {
		// Uncomment for MAX_N calls to addNumber (manual)
		// for (int i = 0; i < MAX_N; i++)
		// 	stonkSpan.addNumber(generateRandomNumber());
		// std::cout << _GREY "\n🔹 What is the shortest span in stonkSpan ? 🔹" _END << std::endl;
		// std::cout << stonkSpan.shortestSpan() << std::endl;
	
		std::cout << "\nSize of SMART before : " << smartSpan.size() << std::endl;
		std::cout << "Size of STONK before : " << stonkSpan._spanVector.size() << std::endl;
		stonkSpan.addNumber(smartSpan);
		std::cout << "Size of SMART before : " << smartSpan.size() << std::endl;
		std::cout << "Size of STONK after : " << stonkSpan._spanVector.size()<< "\n" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	
	return 0;
}
