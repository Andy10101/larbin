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
	/*解析url的函数*/
	void parse(char *s);
	/*不清楚功能*/
	void parseWithBase(char *u, url *base);
	/*统一化文件名称*/
	bool normalize(char *file);
	/*判断url中是否包含协议名称如HTTP*/
	bool isProtocol(char *s);
	/*私有构造函数，作用为：*/
	url(char *u, uint port, char *file);

public:
	//构造函数，解析url
	url(char *u, int8_t depth, url *base);

	/*根据输入进行构造*/
	url(char *line, int8_t depth);
	
	/*文件中读取url*/
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