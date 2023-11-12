#include "Stringz.hpp"

void    replaceLine(std::string& line, std::string s1, std::string s2) 
{
	size_t	i = 0;

	while ((i = line.find(s1, i)) != std::string::npos)
	{
		line = line.substr(0, i) + s2 + line.substr(i + s1.length());
		i += s2.length();
	}	

}

int    replaceStrings(std::string infileName, std::string s1, std::string s2) {

	std::string outfileName;

	outfileName = infileName + ".replace";
   
	std::ifstream ifs(infileName.c_str());
	std::ofstream ofs(outfileName.c_str());

	if (ifs.peek() == std::ifstream::traits_type::eof())
		return (std::cout << "Your infile is empty :(" << std::endl, 1);
	if (!ifs.is_open() || !ofs.is_open())
		return (std::cout << "Can't open filezzz" << std::endl, 1);
	std::string	line;
	while (std::getline(ifs, line))
	{
		replaceLine(line, s1, s2);
		ofs << line << std::endl;
	}
	return 0;
}