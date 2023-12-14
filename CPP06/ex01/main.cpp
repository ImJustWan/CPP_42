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
	

	std::cout << "\nInfos for tmp :\n" << (*tmp) << std::endl;
	std::cout << "Infos for secondOne :\n" << (*secondOne) << std::endl;
	// std::cout << thirdOne << std::endl;

	uintptr_t thirdOne = Serializer::serialize(secondOne);
	std::cout << "Infos for thirdOne :" << std::endl;
	std::cout << (*reinterpret_cast<Data *>(thirdOne)) << std::endl;

	// std::cout << "secondOne is : " << secondOne << std::endl;
	// std::cout << "reinterpret_cast<uintptr_t> of  is : ";
	// std::cout << reinterpret_cast<uintptr_t>(newOne) << std::endl;

	// Data *thirdOne(newOne);

	delete tmp;
	return 0;
}
