// provided by 徐植天

#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cctype>
#include<utility>
#include "priority_queue.hpp"

void TestConstructorAndPush(){
	std::cout << "Testing constructors, destructor and push..." << std::endl;
	sjtu :: priority_queue<int> q;
	int up = 600;
	for (int i = 0;i < up;i ++){
		q.push(i);
	}
	for (int i = 0;i < up / 2;i ++){
		std :: cout << q.top() << " ";
		q.pop();
	}
	std :: cout << std :: endl;
	std :: cout << q.size() << std :: endl;
	sjtu :: priority_queue<int> nq(q);
	std :: cout << nq.size() << std :: endl;
	for (int i = up * 2;i < up * 2 + 10;i ++){
		nq.push(i);
	}
	std :: cout << nq.size() << std :: endl;
	for (int i = 0;i < 5;i ++){
		std :: cout << nq.top() << " ";
		nq.pop();
	}
	std :: cout << std :: endl;
	nq = q;
	std :: cout << nq.size() << std :: endl;
}
void TestSize(){
	std::cout << "Testing size()" << std::endl;
	sjtu :: priority_queue<int>q,q2;
	while (!q.empty()) q.pop();
	for (int i = 0;i < 100;i ++) q.push(i);
	q2 = q;
	q2.push(101),q2.push(102);
	std :: cout << q.size() << " " << q2.size() << std :: endl;
	q2 = q2;
	std :: cout << q2.size() << std :: endl;
}

void TestException(){
	std::cout << "Testing Exception" << std::endl;
	sjtu :: priority_queue<int>q,q2;
	while (!q.empty()) q.pop();
	for (int i = 0;i < 100;i ++) q.push(i);
	q2 = q;
	for (int i = 0;i < 100;i ++) q2.pop();
	int s = 0;
	try{
		q2.pop();
	}catch(...){
		++ s;
	}
	try{
		std :: cout << q2.top() << std :: endl;
	}catch(...){
		++ s;
	}
	if (s == 2){
		std :: cout << "Throw correctly" << std :: endl;
	}
}
struct guest{
	int x,y;
	int getvalue() const{
		return x * 10 + y;
	}
	guest() : x(0),y(0){}
	guest(int a,int b) : x(a),y(b){}
	guest (const guest &other){
		x = other.x;
		y = other.y;
	}
	guest &operator= (const guest &other){
		x = other.x;
		y = other.y;
		return *this;
	}
};
bool operator < (const guest &a,const guest &b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
void Testguest_sp(sjtu :: priority_queue<guest>tmp){
	for (int i = 90;i < 95;i ++){
		int x = i / 10;
		int y = i % 10;
		tmp.push(guest(x,y));
	}
	std :: cout << tmp.size() << " " << tmp.top().getvalue() << std :: endl;
}
void Testguest(){
	std :: cout << "Testing guest" << std :: endl;
	sjtu :: priority_queue<guest>q,q2;
	while (!q.empty()) q.pop();
	for (int i = 0;i < 100;i ++){
		int x = i / 10;
		int y = i % 10;
		q.push(guest(x,y));
	}
	std :: cout << q.size() << std :: endl;
	q2 = q;
	for (int i = 0;i < 10;i ++) q2.pop();
	std :: cout << q2.size() << " " << q2.top().getvalue() << std :: endl;
	Testguest_sp(q2);
	std :: cout << q2.size() << " " << q2.top().getvalue() << std :: endl;
}
void Testsamecopy(){
	std :: cout << "Testing samecopy" << std :: endl;
	sjtu :: priority_queue<guest>q;
	for (int i = 0;i < 50;i ++){
		int x = i * 2 / 10;
		int y = i * 2 % 10;
		q.push(guest(x,y));
	}
	std :: cout << q.size() << std :: endl;
	for (int i = 0;i < q.size();i ++){
		std :: cout << q.top().getvalue() << " ";
	}
	std :: cout << std :: endl;
	q = q;
	for (int i = 0;i < 10;i ++) q.pop();
	std :: cout << q.size() << std :: endl;
	for (int i = 0;i < q.size();i ++){
		std :: cout << q.top().getvalue() << " ";
	}
	std :: cout << std :: endl;
}
void Testsort(){
	std :: cout << "Testing sort" << std :: endl;
	sjtu :: priority_queue<guest>q;
	for (int i = 0;i < 50;i ++){
		int x = i / 10;
		int y = i % 10;
		q.push(guest(x,y));
	}
	for (int i = 0;i < 50;i ++){
		std :: cout << q.top().getvalue() << " ";
		q.pop();
	}
	std :: cout << std :: endl;
}
struct binary{
	int len;
	int number[10];
	std :: string getexpression() const{
		std :: string ret = "";
		for (int i = 0;i < len;i ++) ret += char(48 + number[i]);
		return ret;
	}
	binary(int *p = NULL,int l = 0){
		len = l;
		for (int i = 0;i < l;i ++) number[i] = p[i];
	}
	binary(const binary &other){
		len = other.len;
		for (int i = 0;i < len;i ++) number[i] = other.number[i];
	}
	binary &operator = (const binary &other){
		len = other.len;
		for (int i = 0;i < len;i ++) number[i] = other.number[i];
	}
};
bool operator < (const binary &a,const binary &b){
	if (a.len != b.len) return a.len < b.len;
	for (int i = 0;i < a.len;i ++){
		if (a.number[i] < b.number[i]) return true;
		if (a.number[i] > b.number[i]) return false;
	}
	return false;
}
void Testextra(){
	std :: cout << "Testing extra" << std :: endl;
	sjtu :: priority_queue<binary>q;
	int e[10];
	for (int i = 1;i < 1000;i ++){
		int len = 0,t = i;
		while (t){
			e[len ++] = t % 2;
			t /= 2;
		}
		for (int j = 0;j < len / 2;j ++){
			int tmp = e[j];
			e[j] = e[len - 1 - j];
			e[len - 1 - j] = tmp;
		}
		q.push(binary(e,len));
	}
	for (int i = 1;i < 1000;i ++){
		std :: cout << q.top().getexpression() << " ";
		q.pop();
	}
	std :: cout << std :: endl;
}
int main(){
	TestConstructorAndPush(); 
 	TestSize();
 	TestException();
	Testguest();
	Testsamecopy();
	Testsort();
	Testextra();
	return 0;
}
