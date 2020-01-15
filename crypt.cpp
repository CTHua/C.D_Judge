#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <openssl/md5.h>
#include "./hash.h"
using namespace std;
int main(int argc,char** argv)
{
	string date(argv[1]);
	int N=atoi(argv[2]); //how many question need to crypt
	char *c_key=getkey(argv[1]);
	string key(c_key);
	string mkdir;
	mkdir.append("mkdir /home1/student/stud108/s10829/judge/io/" + date );
	system(mkdir.c_str());
	for(int i=1;i<=N;i++)
	{
		string command_i,command_o;
		command_i.append("crypt \"" + key + "\" </home1/student/stud108/s10829/judge/dcryio/" + date + "/" + to_string(i) + ".in.txt");
		command_i.append(" >/home1/student/stud108/s10829/judge/io/" + date + "/" + to_string(i) + ".in");
		command_o.append("crypt \"" + key + "\" </home1/student/stud108/s10829/judge/dcryio/" + date + "/" + to_string(i) + ".out.txt");
		command_o.append(" >/home1/student/stud108/s10829/judge/io/" + date + "/" + to_string(i) + ".out");
		system(command_i.c_str());
		system(command_o.c_str());
	}
	return 0;
}
