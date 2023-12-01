#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << _BOLD _GREY "\n🔹 Creating Bureaucrats ! 🔹\n" _END << std::endl;
	Bureaucrat JJG("Jean-Jacques Goldman", 88);
	std::cout << JJG << std::endl;
	Bureaucrat Garou("Garou", 8);
	std::cout << Garou << std::endl;

	std::cout << _BOLD _GREY "\n🔹 Creating a Form ! 🔹\n" _END << std::endl;
	Form firstForm("Forminette", 5, 75);
	Form secondForm(firstForm);

	std::cout << "\nIs " << firstForm.getName() << " signed ? " << firstForm.getSigned() << std::endl;
	std::cout << "Is " << secondForm.getName() << " signed ? " << secondForm.getSigned() << std::endl;

	try {
		std::cout << _BOLD _GREY "\n🔹 Can secondForm be signed by Garou ? 🔹" _END << std::endl;
		secondForm.beSigned(Garou);
		std::cout << _BOLD _GREY "🔹 Can firstForm be signed by JJG ? 🔹" _END << std::endl;
		firstForm.beSigned(JJG);
	}
	catch(const Form::GradeTooLowException& e) {
		std::cout << _RED "❌ Bureaucrat's grade is too low, NOT HAPPENING SORRY\n" << _END << std::endl;
	}
	
	std::cout << "Is " << firstForm.getName() << " signed ? " << firstForm.getSigned() << std::endl;
	std::cout << "Is " << secondForm.getName() << " signed ? " << secondForm.getSigned() << std::endl;

	try {
		std::cout << _BOLD _GREY "\n🔹 Can Garou sign the firstForm ? 🔹" _END << std::endl;
		Garou.signForm(firstForm);
		std::cout << _BOLD _GREY "🔹 Can JJG sign the secondForm ? 🔹" _END << std::endl;
		JJG.signForm(secondForm);
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cout << _RED "❌ Bureaucrat's grade is too low, NOT HAPPENING SORRY\n" << _END << std::endl;
	}
	
	std::cout << "Is " << firstForm.getName() << " signed ? " << firstForm.getSigned() << std::endl;
	std::cout << "Is " << secondForm.getName() << " signed ? " << secondForm.getSigned() << std::endl;

	std::cout << _BOLD _GREY "\n\n🔹 Creating Exceptional Forms ! 🔹\n" _END << std::endl;

	try {
		std::cout << _ITALIC _BOLD _GREY "lowExec(\"lowExec\", 0, 75)" _END << std::endl;
		Form lowExec("lowExec", 3, 75);
		std::cout << lowExec << std::endl;
		std::cout << _ITALIC _BOLD _GREY "highSign(\"highSign\", 75, 188)" _END << std::endl;
		Form highSign("highSign", 75, 188);
		std::cout << highSign << std::endl;
		return 0;
	}
	catch(const Form::GradeTooHighException& e) {
		std::cout << e.what()  << std::endl;
	}
	catch(const Form::GradeTooLowException& e) {
		std::cout << e.what()  << std::endl;
	}
	std::cout << _RED "❌ Forms have to be filled with CORRECT numbers, thanks. ಠ_ಠ\n" _END << std::endl;
	return 0;
}
