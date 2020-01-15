#include <iostream>
#include <string>
#include <stdlib.h>
#include <openssl/md5.h>
using namespace std;
char* getkey(char* argv)
{
	string date(argv);
	unsigned char result[MD5_DIGEST_LENGTH];
	MD5( (unsigned char*)date.c_str() , date.size() , result );
	char *c_key;
	c_key=(char*)calloc( 9,sizeof(char) );
	for(int i=0;i<8;i++)
	{
		sprintf(c_key+i,"%c",result[i]);
		if(c_key[i]==0)c_key[i]=1;
	}
	return c_key;
}
