#include <iostream>
#include "url.h"
using namespace std;

void test_url();
int main()
{
	bool test = false;
	cout << "function isValid:" << test << endl;
	test_url();

	return 0;
}

//urlÀàµÄ²âÊÔº¯Êý
void test_url()
{
	char *u1 = "http://www.google.com/reader/view/stream/";
	char *u2 = "http://www.google.com/reader/view/stream/user.html";
	char *u1_2 = "user.html";
	int8_t depth1 = 3;
	int8_t depth2 = 4;

	//²âÊÔ¹¹Ôìº¯Êý
	url father_URL(u1,depth1);
	url child_URL(u2,depth2);
	url child_URL2(u1_2,depth2,&father_URL);

	//²âÊÔisValidº¯Êý
	 bool flag = father_URL.isValid();
	cout << "function isValid of father_URL:" << flag*1 << endl;	
	cout << "function isValid of child_URL:" << child_URL.isValid() << endl;
	cout << "function isValid of child_URL2:" << child_URL2.isValid() << endl;
	cout << endl;

	//²âÊÔprint
	cout << "function print:\n";
	father_URL.print();	
	child_URL2.print() ;

	char *host, *port, *file;
	int depth;
	cout << "function getHost,getPort and getFile:\n";
	cout << father_URL.getHost() << endl;
	cout << child_URL2.getHost() << endl;
	cout << father_URL.getFile() << endl;
	cout << child_URL2.getPort() << endl;
	cout << "function giveUrl:\n";
	char *u = child_URL.giveUrl();
	cout << u<< endl;
	delete [] u;
	char buf[60];
	cout << "function writeUrl:\n";
	father_URL.writeUrl(buf);
	cout << buf << endl;
	cout << "function getUrl:\n";
	cout << father_URL.getUrl() << endl;
	cout << "function hostHashCode and hashCode:\n";
	cout << child_URL.hostHashCode() << '\t' << child_URL.hashCode() << endl;
	cout <<111;




}