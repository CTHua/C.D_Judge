#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc,char** argv)
{
	string key(argv[1]);
	int N=atoi(argv[2]); //how many question need to crypt
	for(int i=1;i<N;i++)
	{
		string command_i,command_o;
		command_i.append("crypt " + key + "</home1/student/stud108/s10829/judge/dcryio/in/"+ to_string(i) +".in");
		command_i.append(" >/home1/student/stud108/s10829/judge/io/question/question" + to_string(i) +".crypt");
		command_o.append("crypt " + key + "</home1/student/stud108/s10829/judge/dcryio/out/"+ to_string(i) +".out");
		command_o.append(" >/home1/student/stud108/s10829/judge/io/ans/ans" + to_string(i) +".crypt");
		system(command_i.c_str());
		system(command_o.c_str());
	}
	return 0;
}
