#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/string_file.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

int main()
{
	string result;
	boost::filesystem::load_string_file("dsvlog",result);
	cout << result.size() << endl;

	vector<string> linev;
	boost::algorithm::split(linev, result, boost::is_any_of("\n"));
	cout << linev[1] << endl;

	for(string n : linev) {
		cout << n << endl;
	}

	vector<string>::iterator vit;
	vit=linev.begin();
	do {
		cout << *vit << endl;
		vit++;
	} while( vit != linev.end());

	return 0;
}
