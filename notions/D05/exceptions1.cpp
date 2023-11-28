#include <stdexcept>

void	test1()
{
	try
	{
		//Do stuff
		if (/*error*/)
		{
			throw std::exception();
		}
		else
		{
			//stuff
		}
	}
	catch(const std::exception& e)
	{
		// Error handlin
	}
}

void	test2()
{
	//Do stuff
	if (/*error*/)
	{
		throw std::exception();
	}
	else
	{
		//stuff
	}
}

void	test3()
{
	try
	{
		test2();
	}
	catch(const std::exception& e)
	{
		// Error handlin
	}
}

void test4()
{
	class PEBKAException : public std::exception
	{
		public:
			virtual const char * what() const throw()
			{
				return("Problem Exists bewteen Keyboard And Chair");
			}
	};
	try
	{
		test3();
	}
	catch(PEBKAException& e)
	{
		// User is an idiot
	}
	catch(std::exception& e)
	{
		// Other exceptions
	}
}