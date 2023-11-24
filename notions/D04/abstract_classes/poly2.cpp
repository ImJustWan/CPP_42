#include <iostream>
#include <string>

class ACharacter {
	public:
		virtual void    attack(std::string const & target) = 0; //makes it a pure method
						// can't define/implement the meethod 
						// -> can't the class -> makes it an abstract class 
		void            sayHello(std::string const & target);
};

class Warrior : public ACharacter {
	public:
		virtual void    attack(std::string const & target);
};


void ACharacter::sayHello(std::string const &target)
{
	std::cout << "Hello " << target << " ! " << std::endl;
}


void Warrior::attack(std::string const &target)
{
	std::cout << "*attacks " << target << " with a knife*" << std::endl;
}

// class ICoffeeMaker {
// 	public:
// 		virtual void	fillWaterTank(IWaterSource *src) = 0;
// 		virtual	ICoffee *makeCoffee(std::string const &type) = 0;
// };

//Interface = 0 attribut, pure methods only
//permet de definir un comportement

int main()
{
	ACharacter *a = new Warrior();
	
	//ACharacter *b = new ACharacter();
	//NOT OK because abstract class


	a->sayHello("peasants");
	a->attack("Roger");
}

/*
Fonction membre virtuelle = method
*/