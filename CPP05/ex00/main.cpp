#include "Bureaucrat.hpp"

int main()
{
	std::cout << _BOLD _GREY "\n🔹 Creating a Bureaucrat ! 🔹\n" _END << std::endl;
	Bureaucrat JJG("Jean-Jacques Goldman", 2);
	std::cout << JJG << std::endl;

	try	{
		std::cout << _ITALIC _GREY "🔹 promoting " << JJG.getName() << " 🔹" _END << std::endl;
		JJG.incrementGrade();
		std::cout << JJG << std::endl;
		std::cout << _ITALIC _GREY "🔹 promoting " << JJG.getName() << " 🔹" _END << std::endl;
		JJG.incrementGrade();
		std::cout << JJG << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what()  << std::endl;
		 std::cout << _FOREST_GREEN "✨ "<< JJG.getName() << " has already achieved the highest rank (シ_ _)シ" _END << std::endl;
	}

	std::cout << _BOLD _GREY "\n\n🔹 Creating a Default Bureaucrat ! 🔹\n" _END << std::endl;
	Bureaucrat random;
	std::cout << random << std::endl;
	std::cout << _ITALIC _GREY "🔹 promoting " << random.getName() << " ! 🔹" _END << std::endl;
	random.incrementGrade();
	std::cout << random << std::endl;
	std::cout << _ITALIC _GREY "🔹 demoting " << random.getName() << " 🔹" _END << std::endl;
	try {
		random.decrementGrade();
		std::cout << random << std::endl;
		random.decrementGrade();
		std::cout << random << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what()  << std::endl;
		std::cout << _MAROON "⛔ " << random.getName() << " is already at the bottom of the ladder ( ´･･)ﾉ(._.`)" _END << std::endl;
	}

	std::cout << _BOLD _GREY "\n\n🔹 Creating Exceptional Bureaucrats ! 🔹\n" _END << std::endl;

	try {
		Bureaucrat Wan("Wan", 0);
		std::cout << Wan << std::endl;
		std::cout << std::endl;
		Bureaucrat Grint("Grint", 188);
		std::cout << Grint << std::endl;
		return 0;
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what()  << std::endl;
		std::cout << _RED "❌ Be reasonable, nobody starts with a grade that high..." _END << std::endl;
		return 1;
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what()  << std::endl;
		std::cout << _RED "❌ With a grade that low, they might as well not even start working..." _END << std::endl;
		return 2;
	}
}
