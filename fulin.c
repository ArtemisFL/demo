#include<iostream>
#include<pthread>
#include<stdio.h>

using namespace std;

class singletion
{
	
protected:
	singletion ()
	{
		pthread_mutex_init(&mutex);
	}
	singletion(singletion &)=delete;
	singletion & operator=(const singletion &)=delete;

private:
	static singletion *p;

public:
	static pthread_mutex_t mutex;
	static singletion *get_insstance();
}


pthread_mutex_t singletion::mutex;
singletion *singletion::p=nullptr;

singletion *get_insstance()
{
	if(p==nullptr)
	{
		"第二次|这是一个标记|解决冲突";
		p=new singleton();
		pthread_mutex_unlock(&mutex);
	}
	
	return p;
}
