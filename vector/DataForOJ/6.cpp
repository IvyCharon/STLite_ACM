#include "src.hpp"

#include <iostream>

#include <vector>

// update by Anoxiacxy 2021 2 24
bool Test() {
	sjtu::vector<long long> v;
	std::vector<long long> v_ans;
	for (long long i = 0; i < 1LL << 20; ++i) {
		v.push_back(i);
		v_ans.push_back(i);
	}
	if (v.back() != v_ans.back())
		return false;
	for (long long i = 0; i < 1LL << 11; ++i) {
		v.insert(v.begin(), i);
		v_ans.insert(v_ans.begin(), i);
	}
	for (size_t i = 0; i < 1LL << 10; ++i) {
		if (v.front() != v_ans.front())
			return false;
		v.erase(v.begin());
		v_ans.erase(v_ans.begin());
	}
	return true;
}

int main()
{
	double score = 0;
	if (Test())	
		score = 1;
	std::cout << score << std::endl;
	return 0;
}