#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

#include "priority_queue.hpp"

void TestConstructorAndPush()
{
	std::cout << "Testing constructors, destructor and push..." << std::endl;
	sjtu::priority_queue<int> pq;
	for (int i = 100; i > 0; --i) {
		pq.push(i);
	}
	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
	std::cout << std::endl;
	for (int i = 1000; i > 100; --i) {
		pq.push(i);
	}
	sjtu::priority_queue<int> pqBack(pq);
	std::cout << pqBack.size() << std::endl;
	sjtu::priority_queue<int> pqBB;
	for (int i = 10; i <= 10000; ++i) {
		pqBB.push(i);
	}
	std::cout << pqBB.size() << std::endl;
	pqBB = pq;
	std::cout << pqBB.size() << std::endl;
}

void TestSize()
{
	std::cout << "Testing size()" << std::endl;
	sjtu::priority_queue<long long> pq;
	for (int i = 1; i <= 1000; ++i) {
		pq.push(rand());
	}
	std::cout << pq.size() << std::endl;
}

void TestException()
{
	sjtu::priority_queue<int> pq;
	try {
		std::cout << pq.top() << std::endl;
	} catch (...) {
		std::cout << "Throw correctly." << std::endl;
	}
}

int main(int argc, char *const argv[])
{
	TestConstructorAndPush();
	TestSize();
	TestException();
	return 0;
}
