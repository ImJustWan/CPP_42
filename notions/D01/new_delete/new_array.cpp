#include <iostream>
#include <string>

class Student 
{
	private:
		std::string	_login;

	public:
		Student();
		~Student();
};

Student::Student() : _login("ldefault")
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
	Student*	students = new Student[8];

	delete [] students;
	return 0;
}