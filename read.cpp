#include <iostream>
#include <string>
#include <boost/filesystem/string_file.hpp>

int main()
{
	std::string result;
	boost::filesystem::load_string_file("dsvlog",result);
	std::cout << result.size() << std::endl;

	return 0;
}
