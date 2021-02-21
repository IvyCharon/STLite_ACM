// provided by xzj
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdio>

#include "priority_queue.hpp"

long long aa=13131,bb=5353,MOD=1e9+7,now=1;
int rand()
{
	for(int i=1;i<3;i++)
		now=(now * aa + bb) % MOD;
	return now;
}
class T1//no_construct
{
public:
	int data;
	T1(int key):data(key){}
};
bool operator == (const T1 &a,const T1 &b)
{
	return a.data == b.data;
}
std::ostream &operator <<(std::ostream &os, const T1 &a){
	os<<a.data;
	return os;	
}

class T2//pointer + no_construct
{
public:
	int *data;
	T2(int key):data(new int(key)){}
	T2(const T2 &other):data(new int(*(other.data))){}
	T2&operator = (const T2 &other)
	{
		if(this == &other) return *this;
		delete data;
		data = new int(*(other.data));
	}
	~T2(){delete data;}
};
bool operator == (const T2 &a,const T2 &b)
{
	return *(a.data) == *(b.data);
}
std::ostream &operator <<(std::ostream &os, const T2 &a){
	os<<*(a.data);
	return os;	
}

class T3
{
public:
	int data;
	T3():data(0){}
	T3(int key):data(key){}
};
bool operator == (const T3 &a,const T3 &b)
{
	return a.data == b.data;
}
std::ostream &operator <<(std::ostream &os, const T3 &a){
	os<<a.data;
	return os;	
}

class T4//pointer
{
public:
	int *data;
	T4():data(new int(0)){}
	T4(int key):data(new int(key)){}
	T4(const T4 &other):data(new int(*(other.data))){}
	T4&operator = (const T4 &other)
	{
		if(this == &other) return *this;
		delete data;
		data = new int(*(other.data));
		return *this;
	}
	~T4(){delete data;}
};
bool operator == (const T4 &a,const T4 &b)
{
	return *(a.data) == *(b.data);
}
std::ostream &operator <<(std::ostream &os, const T4 &a){
	os<<*(a.data);
	return os;	
}
struct cmp{
	bool operator ()(const T1 &a,const T1 &b)const{return a.data < b.data;} 	
	bool operator ()(const T2 &a,const T2 &b)const{return *(a.data) < *(b.data);} 	
	bool operator ()(const T3 &a,const T3 &b)const{return a.data < b.data;} 	
	bool operator ()(const T4 &a,const T4 &b)const{return *(a.data) < *(b.data);} 	
	bool operator ()(const int &a,const int &b)const{return a < b;} 	
};
template<class T>
void test()
{
	sjtu::priority_queue<T,cmp> q;
	int test_num=10000;
	for(int i=1;i<=test_num;i++)
	{
		q.push(T(rand()));
		if(i % 100==0)
		{
			std::cout<<q.top()<<' '<<q.size()<<' '<<q.empty()<<std::endl;
		}
		if(i % 100 > 900)
			q.pop();
	}
}
template<class T>
void copy_test()
{
	sjtu::priority_queue<T,cmp> q;
	int num=5000;
	for(int i=1;i<=num;i++)
		q.push(T(rand()));
	for(int j=1;j<=5;j++)
	{
		sjtu::priority_queue<T,cmp> t(q);
		for(int i=1;i<=100;i++)
			t.push(T(rand()));
		for(int k=1;k<=10;k++)
		{
			std::cout<<t.top()<<' '<<t.size()<<' '<<t.empty()<<std::endl;
			t.pop();
		}
		sjtu::priority_queue<T,cmp> p;
		p=t;
		p=p=p=p;
		for(int i=1;i<=100;i++)
			p.push(T(rand()));
		for(int k=1;k<=10;k++)
		{
			std::cout<<p.top()<<' '<<p.size()<<' '<<p.empty()<<std::endl;
			p.pop();
		}
	}
}
void normal_test()
{
	puts("Normal test...");
	test<int>();
	test<T3>();
	test<T4>();
}
void advanced_test()
{
	printf("Advanced test...");
	test<T1>();
	test<T2>();
}
void normal_copy_test()
{
	printf("Normal copy&= test...");
	copy_test<int>();
	copy_test<T3>();
	copy_test<T4>();
}
void advanced_copy_test()
{
	printf("Advanced copy&= test...");
	copy_test<T1>();
	copy_test<T2>();
}
void exception_test()
{
	bool flag = 0;
	printf("Exception test...");
	sjtu::priority_queue<int,cmp> q;
	for(int i=1;i<=100;i++)
		q.push(rand());
	for(int i=1;i<=100;i++)
		q.pop();
	try{
		q.pop();	
	}
	catch(sjtu::container_is_empty) {flag = 1;}
	catch(...){flag = 0;}
	if(!flag)
	{
		puts("Wrong Answer(pop)");
		return;
	}
	try{
		int tmp(q.top());	
	}
	catch(sjtu::container_is_empty) {flag = 1;}
	catch(...){flag = 0;}
	if(!flag)
	{
		puts("Wrong Answer(top)");
		return;
	}
	puts("Accept");
}
int main(int argc, char *const argv[])
{
	//freopen("testans-priority_queue-advance","w",stdout);
	puts("Test Start");
	normal_test();
	normal_copy_test();	
	advanced_test();	
	advanced_copy_test();
	exception_test();
	return 0;
}
