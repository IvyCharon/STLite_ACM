#include "src.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

/*
void TestConstructor()
{
	std::cout << "Testing constructors and assignment operator..." << std::endl;
	sjtu::vector<int> v;
	for (int i = 1; i <= 10; ++i) {
		v.push_back(i);
	}
	const sjtu::vector<int> vc(v);
	for (size_t i = 0; i < vc.size(); ++i) {
		std::cout << vc[i] << " ";
	}
	std::cout << std::endl;
	sjtu::vector<int> vv;
	for (int i = 0; i < 10; ++i) {
		vv.push_back(i);
	}
	for (size_t i = 0; i < vv.size(); ++i) {
		std::cout << vv[i] << " ";
	}
	std::cout << std::endl;
	vv = v;
	for (size_t i = 0; i < vv.size(); ++i) {
		std::cout << vv[i] << " ";
	}
	std::cout << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestConstructor() {
	sjtu::vector<int> v;
	std::vector<int> v_ans;
	for (int i = 1; i <= 10; ++i) {
		v.push_back(i);
		v_ans.push_back(i);
	}
	const sjtu::vector<int> vc(v);
	const std::vector<int> vc_ans(v_ans);
	for (size_t i = 0; i < vc.size(); ++i) {
		if (vc[i] != vc_ans[i])
			return false;
	}

	sjtu::vector<int> vv;
	std::vector<int> vv_ans;
	for (int i = 0; i < 10; ++i) {
		vv.push_back(i);
		vv_ans.push_back(i);
	}
	for (size_t i = 0; i < vv.size(); ++i) {
		if (vv[i] != vv_ans[i])
			return false;
	}
	vv = v;
	vv_ans = v_ans;
	for (size_t i = 0; i < vv.size(); ++i) {
		if (vv[i] != vv_ans[i])
			return false;
	}
	return true;
}
/*
void TestIterators()
{
	std::cout << "Testing iterators..." << std::endl; 
	sjtu::vector<int> v;
	for (int i = 1; i <= 20; ++i) {
		v.push_back(i);
	}
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	const sjtu::vector<int> vc(v);
	for (sjtu::vector<int>::const_iterator it = vc.cbegin(); it != vc.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestIterators() {
	sjtu::vector<int> v;
	std::vector<int> v_ans;
	for (int i = 1; i <= 20; ++i) {
		v.push_back(i);
		v_ans.push_back(i);
	}
	std::vector<int>::iterator it_ans = v_ans.begin();
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it, ++it_ans) {
		if (*it != *it_ans)
			return false;
	}
	
	const sjtu::vector<int> vc(v);
	const std::vector<int> vc_ans(v_ans);
	std::vector<int>::const_iterator it_ans2 = vc_ans.cbegin();
	for (sjtu::vector<int>::const_iterator it = vc.cbegin(); it != vc.cend(); ++it, ++it_ans2) {
		if (*it != *it_ans2)
			return false;
	}
	return true;
}
/*
void TestAccessingMethod()
{
	std::cout << "Testing accessing methods..." << std::endl;
	sjtu::vector<long long> vd;
	for (long long i = 0; i < 50; ++i) {
		vd.push_back(1LL << i);
	}
	for (size_t i = 0; i < vd.size(); ++i) {
		std::cout << vd[i] << std::endl;
	}
	try {
		std::cout << vd.at(100) << std::endl;
	} catch(...) {
		std::cout << "exceptions thrown correctly." << std::endl;
	}
}
*/
// update by Anoxiacxy 2021 2 24
bool TestAccessingMethod() {
	sjtu::vector<long long> vd;
	std::vector<long long> vd_ans;
	for (long long i = 0; i < 50; ++i) {
		vd.push_back(1LL << i);
		vd_ans.push_back(1LL << i);
	}
	for (size_t i = 0; i < vd.size(); ++i) {
		if (vd[i] != vd_ans[i])
			return false;
	}
	try {
		if (vd.at(100) == 0)
			return false;
	} catch(...) {
		return true;
	}
	return false;
}
/*
void TestPush_Pop()
{
	std::cout << "Testing push_back and pop_back..." << std::endl;
	sjtu::vector<double> vd;
	for (double i = 0.0; i < 10.0; i += 1.0) {
		vd.push_back(i);
	}
	std::cout << vd.back() << std::endl;
	for (double i = 20.0; i < 23.0; i += 1.0) {
		vd.push_back(i);
	}
	std::cout << vd.back() << std::endl;
	vd.pop_back();
	std::cout << vd.back() << std::endl;
	vd.pop_back();
	std::cout << vd.back() << std::endl;
	for (int i = 0; i < 5; ++i) {
		vd.pop_back();
	}
	std::cout << vd.back() << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestPush_Pop() {
	sjtu::vector<double> vd;
	std::vector<double> vd_ans;
	for (double i = 0.0; i < 10.0; i += 1.0) {
		vd.push_back(i);
		vd_ans.push_back(i);
	}
	if (vd.back() != vd_ans.back()) return false;
	for (double i = 20.0; i < 23.0; i += 1.0) {
		vd.push_back(i);
		vd_ans.push_back(i);
	}
	if (vd.back() != vd_ans.back()) return false;
	vd.pop_back(); 
	vd_ans.pop_back();
	if (vd.back() != vd_ans.back()) return false;
	vd.pop_back();
	vd_ans.pop_back();
	if (vd.back() != vd_ans.back()) return false;
	for (int i = 0; i < 5; ++i) {
		vd.pop_back();
		vd_ans.pop_back();
	}
	if (vd.back() != vd_ans.back()) return false;
	return true;
}
/*
void TestInsert()
{
	std::cout << "Testing insert functions" << std::endl;
	sjtu::vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	v.insert(v.begin() + 3, 100);
	v.insert(v.begin() + 5, 200);
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
*/
// update by Anoxiacxy 2021 2 24
bool TestInsert() {
	sjtu::vector<int> v;
	std::vector<int> v_ans;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		v_ans.push_back(i);
	}
	v.insert(v.begin() + 3, 100);
	v_ans.insert(v_ans.begin() + 3, 100);
	v.insert(v.begin() + 5, 200);
	v_ans.insert(v_ans.begin() + 5, 200);
	std::vector<int>::iterator it_ans = v_ans.begin();
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it, ++it_ans) {
		if (*it != *it_ans)
			return false;
	}
	return true;
}

/*

void TestErase()
{
	std::cout << "Testing erase functions" << std::endl;
	sjtu::vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	v.insert(v.begin() + 3, 100);
	v.insert(v.begin() + 5, 200);
	v.erase(v.begin() + 5);
	v.erase(v.begin() + 3);
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

*/
// update by Anoxiacxy 2021 2 24
bool TestErase() {
	sjtu::vector<int> v;
	std::vector<int> v_ans;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		v_ans.push_back(i);
	}
	v.insert(v.begin() + 3, 100);
	v_ans.insert(v_ans.begin() + 3, 100);
	v.insert(v.begin() + 5, 200);
	v_ans.insert(v_ans.begin() + 5, 200);
	v.erase(v.begin() + 5);
	v_ans.erase(v_ans.begin() + 5);
	v.erase(v.begin() + 3);
	v_ans.erase(v_ans.begin() + 3);
	std::vector<int>::iterator it_ans = v_ans.begin();
	for (sjtu::vector<int>::iterator it = v.begin(); it != v.end(); ++it, ++it_ans) {
		if (*it != *it_ans)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	if (TestConstructor() &&
		TestIterators() &&
		TestAccessingMethod() &&
		TestPush_Pop() &&
		TestInsert() &&
		TestErase()
	) 	
		std::cout << 1 << std::endl;
	else
		std::cout << 0 << std::endl;
	return 0;
}