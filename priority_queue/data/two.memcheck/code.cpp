// provided by 林伟鸿
//
#include <iostream>
#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include "priority_queue.hpp"

using namespace std;

int A = 325, B = 2336, last = 233, mod = 1000007;

int Rand(){
	return last = (A * last + B) % mod;
}

void check1(){//测试push 以及 top访问
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 5000; i++){
		int x = Rand();
		Q.push(x);
		printf("%d ", Q.top());
	}
	printf("\n");
}

void check2(){//测试pop 以及 top访问
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 5000; i++){
		int x = Rand();
		Q.push(x);
	}
	printf("%d ", Q.size());
	while(!Q.empty()){
		printf("%d", Q.top());
		Q.pop();
	}
	printf("\n");
}

void check3(){//测试push pop 同时操作
	sjtu::priority_queue<int> Q;
	int size = 0;
	for(int i = 1; i <= 6000; i++){
		if(!size){
			int x = Rand();
			Q.push(x);
			size++;
		}
		else{
			int p = Rand() % 2;
			if(!p){
				Q.pop(); size--;
			}
			else{
				int x = Rand();
				Q.push(x);
				size++;
			}
		}
		if(size){
			printf("%d ", Q.top());
		}
	}
	printf("\n");
}

void check4(){//测试拷贝构造
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 5000; i++){
		int x = Rand();
		Q.push(x);
	}
	sjtu::priority_queue<int> Q2(Q);
	printf("%d ", Q2.size());
	while(!Q2.empty()){
		printf("%d ", Q2.top());
		Q2.pop();
	}
	printf("\n");
}

void check5(){//测试"="
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 5000; i++){
		int x = Rand();
		Q.push(x);
	}
	sjtu::priority_queue<int> Q2;
	Q2 = Q;
	printf("%d ", Q2.size());
	while(!Q2.empty()){
		printf("%d ", Q2.top());
		Q2.pop();
	}
	printf("\n");
}

bool check6(){//测试堆为空时top是否报错
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 100; i++) Q.push(Rand());
	try{
		while(!Q.empty()){
			Q.pop();
		}
		Q.top();
	}
	catch(...){
		return 1;
	}
	return 0;
}

bool check7(){//测试堆为空时pop是否报错
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 100; i++) Q.push(Rand());
	try{
		while(!Q.empty()){
			Q.pop();
		}
		Q.pop();
	}
	catch(...){
		return 1;
	}
	return 0;
}

//check8用于测试拷贝构造时是否在复制之前new出新的堆，若堆在pop是回收节点内存，那么会出现第二次回收时崩溃
bool check8(){
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 3000; i++){
		Q.push(Rand());
	}
	sjtu::priority_queue<int> Q2(Q);
	while(!Q.empty()){
		Q.pop();
	}
	while(!Q2.empty()){
		Q2.pop();
	}
	return 1;
}

//check9与check8同理，测试的是"="操作执行是是否new出新节点
bool check9(){
	sjtu::priority_queue<int> Q;
	for(int i = 1; i <= 3000; i++){
		Q.push(Rand());
	}
	sjtu::priority_queue<int> Q2;
	Q2 = Q;
	while(!Q.empty()){
		Q.pop();
	}
	while(!Q2.empty()){
		Q2.pop();
	}
	return 1;
}

struct intnum{
	int num;
	intnum(int p = 0) : num(p) {}
	bool operator <(const intnum &b) const{
		return num < b.num;
	}
};

void check10(){//考察传到自己的类是否能正常工作
	sjtu::priority_queue<intnum> Q;
	int size = 0;
	for(int i = 1; i <= 3000; i++){
		if(!size){
			int x = Rand();
			Q.push(intnum(x));
			size++;
		}
		else{
			int p = Rand() % 2;
			if(!p){
				Q.pop(); size--;
			}
			else{
				int x = Rand();
				Q.push(intnum(x));
				size++;
			}
		}
		if(size){
			printf("%d ", Q.top());
		}
	}
	printf("\n");
}



//check11为CE test 将注释代码进行编译，如果没有CE则通过该测试点

struct node{
	int num;
	node(int p) : num(p) {}
	bool operator <(const node &b) const{
		return num < b.num;
	}
};
bool check11(){
	sjtu::priority_queue<node> Q;
	for(int i = 1; i <= 3000; i++)
		Q.push(node(Rand()));
	while(!Q.empty()){
		Q.top();
		Q.pop();
	}
	return 1;
}


int main(){
	check1();
    check2();
	check3();
	check4();
	check5();

	if(check6()) printf("Test  6 Pass!\n");
	else{
		printf("Test 6 Fail!\n");
	}

	if(check7()) printf("Test  7 Pass!\n");
	else{
		printf("Test 7 Fail!\n");
	}

	if(check8()) printf("Test  8 Pass!\n");
	else{
		printf("Test 8 Fail!\n");
	}

	if(check9()) printf("Test  9 Pass!\n");
	else{
		printf("Test 9 Fail!\n");
	}

	check10();

	if(check11()) printf("Test 11 Pass!\n");
	else{
		printf("Test 11 Fail!\n");
	}

	return 0;
}
