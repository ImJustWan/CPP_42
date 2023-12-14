#include "Base.hpp"

int main()
{
	std::cout << _BOLD _GREY "\n🔹 Creating Objects ! 🔹\n" _END << std::endl;
	Base *tmp1 = Base::generate();
	Base *tmp2 = Base::generate();
	Base *tmp3 = Base::generate();
	Base *tmp4 = Base::generate();


	std::cout << _RIVIERA "\nDetermining tmp1's type : 🔹" _END << std::endl;
	Base::identify(tmp1);
	Base::identify(*tmp1);
	std::cout << _RIVIERA "\nDetermining tmp2's type : 🔹" _END << std::endl;
	Base::identify(tmp2);
	Base::identify(*tmp2);
	std::cout << _RIVIERA "\nDetermining tmp3's type : 🔹" _END << std::endl;
	Base::identify(tmp3);
	Base::identify(*tmp3);
	std::cout << _RIVIERA "\nDetermining tmp4's type : 🔹" _END << std::endl;
	Base::identify(tmp4);
	Base::identify(*tmp4);

	delete tmp1;
	delete tmp2;
	delete tmp3;
	delete tmp4;
	return 0;
}
