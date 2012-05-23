#ifndef URL_H_
#define URL_H_
#include <stdlib.h>
#include <stdint.h>
#include "types.h"
#include <WinSock2.h>
class url{
private:
	char *host;
	char *file;
	uint16_t port;
	int8_t depth;
	/*����url�ĺ���*/
	void parse(char *s);
	/*���������*/
	void parseWithBase(char *u, url *base);
	/*ͳһ���ļ�����*/
	bool normalize(char *file);
	/*�ж�url���Ƿ����Э��������HTTP*/
	bool isProtocol(char *s);
	/*˽�й��캯��������Ϊ��*/
	url(char *u, uint port, char *file);

public:
	//���캯��������url
	url(char *u, int8_t depth, url *base);

	/*����������й���*/
	url(char *line, int8_t depth);
	
	/*�ļ��ж�ȡurl*/
	url(char *line);

	~url();

	in_addr addr;

	bool isValid();

	void print();

	char *getHost() {return host;}
	uint getPort(){return port;}
	char *getFile(){return file;}
	int8_t getDepth(){return depth;}

	bool initOK(url *from);

	url *giveBase();
    
	char *giveUrl();

	int writeUrl(char *buf);

	char *serialize();

	char *getUrl();

	uint hostHashCode();
	uint hashCode();


#ifdef URL_TAGS
	/* tag associated to this url */
	uint tag;
#endif // URL_TAGS

#ifdef COOKIES
	/* cookies associated with this page */
	char *cookie;
	void addCookie(char *header);
#else // COOKIES
	inline void addCookie(char *header) {}
#endif // COOKIES
};

#endif