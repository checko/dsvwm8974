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
		if(lit->length()>0){
			vector<string> field;
			boost::algorithm::split(field,*lit,boost::is_any_of(","));
			if(field[2].find("Address write")!=string::npos){
				vector<string> value;
				boost::algorithm::split(value,field[2],boost::is_any_of(" "));
				cout << value[2] << endl;
			}
		}
		lit++;
	}

	return 0;
}
