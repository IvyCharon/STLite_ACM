#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>

#include "priority_queue.hpp"

int rand() {
	static int reed = 1727417277;
	return (reed += (reed << 5) + 172741827);
}

bool testmerge()
{
	sjtu::priority_queue<int> pq1, pq2;
	static int buffer[900000];
	int pointer = 0;
	const int MAXA = 40000;
	const int MAXB = 40000;
	for (int i = 1; i <= MAXA; i++) {
		pq1.push(buffer[++pointer] = rand());
	}
	for (int i = 1; i <= MAXB; i++) {
		pq2.push(buffer[++pointer] = rand());
	}
	pq1.merge(pq2);
	if (!pq2.empty()) {
		return false;
	} else {
		std::sort(buffer + 1, buffer + pointer + 1);
		while (pointer > 0) {
			if (pq1.top() != buffer[pointer]) {
				return false;
			}
			pq1.pop();
			pointer--;
		}
	}
	return true;
}

int main(int argc, char *const argv[])
{
	if (testmerge()) {
		std::cout << "OKAY" << std::endl;
	} else {
		std::cout << "FAIL" << std::endl;
	}
	return 0;
}
