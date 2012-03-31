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
	void save();			 //��hashTable���浽һ���ļ���
	bool test(string U);     //�ж�һ��url�Ƿ��Ѿ����������hashTable��
	void set(string U);      //��url��hashTable�б��Ϊ�Ѿ�����
	bool testSet(string U); //�ж�url��û�б��ӹ�
};

#endif