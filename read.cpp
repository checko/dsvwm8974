#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <boost/filesystem/string_file.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

unsigned int str2ui(string strin)
{
	unsigned int ul = stoul(strin,nullptr,16);

	return ul;
}

int main()
{
	string result;
	boost::filesystem::load_string_file("dsvlog",result);

	vector<string> linev;
	boost::algorithm::split(linev, result, boost::is_any_of("\n"));

	vector<string>::iterator lit=linev.begin()+1;
	map<unsigned int,unsigned int> regs;
	map<unsigned int,unsigned int>::iterator iter;
	while(lit!=linev.end()){
		unsigned int regadd,regvalue;
		unsigned int data;
		if(lit->find("Address write: 1A")!=string::npos){
			lit+=2;
			data = str2ui(lit->substr(lit->length()-2));
			regadd = data >> 1;
			

			lit+=2;
			regvalue = str2ui(lit->substr(lit->length()-2));
			regvalue |= (data & 0x01) << 8;

			iter=regs.find(regadd);
			if(iter != regs.end())
				iter->second = regvalue;
			else
				regs[regadd] = regvalue;

		}
		lit++;
	}

	for(iter=regs.begin();iter!=regs.end();iter++)
		cout << hex << iter->first << ":" << hex << iter->second << endl;	

	return 0;
}
