#include <iostream>
#include <cstdlib>
#include <ctime>
#include "url.h"
#include "fifo.h"
using namespace std;
void test_class_fifo();
void test_url();
int main()
{
	
	//test_url();
	test_class_fifo();
	return 0;
}

void test_class_fifo(){
	srand(time(0));
	int a[50];
	for(int i = 0; i < 50; i++){a[i] = i;}
	Fifo<int> f;
	int k = 0;
	f.put(a);
	cout << *(f.tryGet()) << endl;
	// test for put() and tryGet()
	while(k < 1000)
	{
		if(rand()*3/RAND_MAX >1)
		{
			int j = rand()*49/RAND_MAX;
			f.put(a+j);
			cout << "put" << a[j] << endl;
		}
		else
		{
			int* tmp = f.tryGet();

			if(tmp)
				cout << *tmp << endl;
			else cout << "NULL" << endl;

		}
	k++;
	}
	//test for getLength(), read() and size
	cout << "length:" << f.getLength() << endl;
	cout <<"read:" << *(f.read()) << endl;
	cout << "size:" << f.size << endl;
	


}


//urlÀàµÄ²âÊÔº¯Êý
void test_class_url()
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