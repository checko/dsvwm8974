#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/string_file.hpp>
#include <boost/algorithm/string.hpp>

int main()
{
	std::string result;
	boost::filesystem::load_string_file("dsvlog",result);
	std::cout << result.size() << std::endl;

	std::vector<std::string> linev;
	boost::algorithm::split(linev, result, boost::is_any_of("\n"));
	std::cout << linev[1] << std::endl;

	for(std::string n : linev) {
		std::cout << n <<std:: endl;
	}

	return 0;
}
