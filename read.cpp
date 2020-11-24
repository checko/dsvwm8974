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

	vector<string> linev;
	boost::algorithm::split(linev, result, boost::is_any_of("\n"));

	vector<string>::iterator lit=linev.begin()+1;
	while(lit!=linev.end()){
		if(lit->find("Address write: 1A")!=string::npos){
			lit+=2;
			cout << lit->substr(lit->length()-2) << endl;
			lit+=2;
			cout << lit->substr(lit->length()-2) << endl;
		}
		lit++;
	}

	return 0;
}
