#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem/string_file.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

int main()
{
	string reading;
	boost::filesystem::load_string_file("dsvlog",reading);

	vector<string> lines;
	boost::algorithm::split(lines,reading,boost::is_any_of("\n"));

	vector<string> tf;
	boost::algorithm::split(tf,lines[lines.size()-2],boost::is_any_of(","));

	for(int i=0;i<lines.size();i++)
		cout << i << ". " << lines[i].length() << endl;




	return 0;
}
