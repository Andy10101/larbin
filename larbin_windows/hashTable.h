#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
using namespace std;

class hashTable{
private:
	ssize_t size;
	ssize_t *table;
public:
	hashTable(bool create);
	~hashTable();    
	void save();			 //把hashTable保存到一个文件中
	bool test(string U);     //判断一个url是否已经存在于这个hashTable中
	void set(string U);      //将url在hashTable中标记为已经见过
	bool testSet(string U); //判断url有没有被加过
};

#endif