#include <iostream>
#include <string>

class Student 
{
	private:
		std::string	_login;

	public:
		Student(std::string login);
		~Student();
};

Student::Student(std::string login) : _login(login)
{
	std::cout << "Student " << this->_login << " is born" << std::endl;
	return;
}

Student::~Student()
{
	std::cout << "Student " << this->_login << " died" << std::endl;
	return;
}

int	main()
{
	Student		marie = Student("mrony");
	Student*	juv = new Student("jaristil");

	delete juv;
	return 0;
}