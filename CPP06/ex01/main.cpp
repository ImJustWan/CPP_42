#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	// if (ac != 2 || (av[1] && strlen(av[1]) == 0)) {
	// 	std::cout << "./convert takes one argument, thank you." << std::endl;
	// 	return 1;
	// }

	Data	*tmp = new Data;
	uintptr_t newOne = Serializer::serialize(tmp);
	Data *secondOne = Serializer::deserialize(newOne);
	

	std::cout << _RIVIERA _BOLD _ITALIC "\nInfos for tmp :\n" _END << (*tmp) << std::endl;
	std::cout << _RIVIERA _BOLD _ITALIC "Infos for secondOne :\n" _END << (*secondOne) << std::endl;
	
	std::cout << _RIVIERA _BOLD _ITALIC "Some addresses : " _END << std::endl;
	std::cout << "tmp (Data *) : " << tmp << std::endl;
	std::cout << "secondOne (Data *) : " << secondOne << std::endl;
	// std::cout << thirdOne << std::endl;

	uintptr_t thirdOne = Serializer::serialize(secondOne);
	std::cout << _RIVIERA _BOLD _ITALIC "\nInfos for thirdOne :" _END << std::endl;
	std::cout << (*reinterpret_cast<Data *>(thirdOne)) << std::endl;

	std::cout << "thirdOne is (uintptr_t): " << thirdOne << std::endl;
	std::cout << "reinterpret_cast<uintptr_t> of secondOne is : ";
	std::cout << reinterpret_cast<uintptr_t>(secondOne) << std::endl;

	// Data *thirdOne(newOne);

	delete tmp;
	return 0;
}
