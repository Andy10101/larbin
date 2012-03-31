#include "hashTable.h"

#define hashSize 64000000
#define ssize_t unsigned int
//¹¹Ôìº¯Êý
hashTable::hashTable(bool create){
	if(create)
	{
		ssize_t total = hashSize/8;
		table = new char[total];
		for(ssize_t i=0; i<total; i++)
			table[i] = 0;
	}else{
	int fds = 
	}

}