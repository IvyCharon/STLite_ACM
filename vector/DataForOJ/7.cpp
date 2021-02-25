#include "src.hpp"

#include "class-integer.hpp"
#include "class-matrix.hpp"
#include "class-bint.hpp"

#include <iostream>
#include <fstream>
#include <string>
/*
void TestInteger()
{
	std::cout << "Test for classes without default constructor..." << std::endl;
	sjtu::vector<Integer> vInt;
	for (int i = 1; i <= 100; ++i) {
		vInt.push_back(Integer(i));
	}
	std::cout << "Test OK..." << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestInteger() {
	sjtu::vector<Integer> vInt;
	std::vector<Integer> vInt_ans;
	for (int i = 1; i <= 100; ++i) {
		vInt.push_back(Integer(i));
		vInt_ans.push_back(Integer(i));
	}
	return true;
}
/*
void TestMatrix()
{
	std::cout << "Test for my Matrix..." << std::endl;
	sjtu::vector<Diamond::Matrix<double>> vM;
	for (int i = 1; i <= 10; ++i) {
		vM.push_back(Diamond::Matrix<double>(i, i, i));
	}
	for (size_t i = 0; i < vM.size(); ++i) {
		std::cout << vM[i] << std::endl;
	}
}
*/
// update by Anoxiacxy 2021 2 24
bool TestMatrix()
{
	sjtu::vector<Diamond::Matrix<double>> vM;
	std::vector<Diamond::Matrix<double>> vM_ans;
	for (int i = 1; i <= 10; ++i) {
		vM.push_back(Diamond::Matrix<double>(i, i, i));
		vM_ans.push_back(Diamond::Matrix<double>(i, i, i));
	}
	for (size_t i = 0; i < vM.size(); ++i) {
		if (!(vM[i] == vM_ans[i]))
			return false;
	}
	return true;
}
/*

void TestBint()
{
	std::cout << "Test for big integer" << std::endl;
	sjtu::vector<Util::Bint> vBint;
	for (long long i = 1LL << 50; i < (1LL << 50) + 10; ++i) {
		vBint.push_back(Util::Bint(i) * i);
	}
	for (sjtu::vector<Util::Bint>::iterator it = vBint.begin(); it != vBint.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestBint()
{
	sjtu::vector<Util::Bint> vBint;
	std::vector<Util::Bint> vBint_ans;
	for (long long i = 1LL << 50; i < (1LL << 50) + 10; ++i) {
		vBint.push_back(Util::Bint(i) * i);
		vBint_ans.push_back(Util::Bint(i) * i);
	}
	std::vector<Util::Bint>::iterator it_ans = vBint_ans.begin();
	for (sjtu::vector<Util::Bint>::iterator it = vBint.begin(); it != vBint.end(); ++it, ++it_ans) {
		if (*it != *it_ans)
			return false;
	}
	return true;
}

int main()
{
	double score = 0;
	if (TestInteger() &&
		TestMatrix() &&
		TestBint()
	) score += 1;
	std::cout << score << std::endl;
}