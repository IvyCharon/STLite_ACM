// Modified by battlin on 2021/3/3.
//Provided by desire2020/Steve Lu

/***********************************************************************
Hint: This test case almost completely tests the correctness of your deque.
So if all tests are passed, feel free to enhance your performance! :)
***********************************************************************/

#include "class-integer.hpp"
#include "class-matrix.hpp"
#include "class-bint.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include "src.hpp"

long long randNum(long long x,long long maxNum){
    x = (x * 10007) % maxNum;
    return x + 1;
}
const size_t N = 10005LL;

void error(){
    std::cout << "Error, mismatch found." << std::endl;
    exit(0);
}

bool TestInteger(){
    //std::cout << "Test 1 : Test for classes without default constructor...";
    sjtu::deque<int> dInt;
    std::vector<int> vInt;
    for (int i = 0; i < N; ++i) {
        vInt.push_back(int(randNum(i, N + 17)));
        dInt.push_back(vInt[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (vInt[i] != dInt[i])
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestIntegeragain(){
    //std::cout << "Test 2 : Test for classes without default constructor but with reversing...";
    sjtu::deque<int> dInt;
    std::vector<int> vInt;
    for (int i = 0; i < N; ++i) {
        dInt.push_back(int(randNum(i, N + 17)));
        vInt.push_back(dInt[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (vInt[i] != dInt[i])
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestMatrix(){
    //std::cout << "Test 3 : Test for Matrix, a class with dynamic members...";
    sjtu::deque<Diamond::Matrix<double>> dM;
    std::vector<Diamond::Matrix<double>> vM;
    for (int i = 0; i < N; ++i) {
        vM.emplace_back(randNum(i + 1, 10 + 7), randNum(i + 2, 10 + 7), randNum(i + 3, (100 + 17)) * 1.0 / randNum(i, 17));
        dM.push_back(vM[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (!(vM[i] == dM[i]))
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestBint(){
    //std::cout << "Test 4 : Test for Bint...";
    sjtu::deque<Util::Bint> dBint;
    std::vector<Util::Bint> vBint;
    for (long long i = 1LL << 60; i < (1LL << 60) + N; ++i) {
        vBint.push_back(Util::Bint(i) * randNum(i, (1 << 29) ));
        dBint.push_back(vBint.back());
    }
    for (int i = 0; i < N; ++i) {
        if (!(vBint[i] == dBint[i]))
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestCopyConstructorAndOperatorEqu(){
    //std::cout << "Test 5 : Test for copy constructor and operator=...";
    sjtu::deque<long long> *pInt;
    pInt = new sjtu::deque<long long>;
    for (long long i = 0; i < N; ++i) {
        pInt -> push_back(i);
    }
    sjtu::deque<long long> &dInt = *pInt;
    sjtu::deque<long long> dualInt(dInt);
    sjtu::deque<long long> dualInt_oper;
    dualInt_oper = dInt;
    for (long long i = 0; i < N; ++i) {
        if (dualInt[i] != (*pInt)[i] || dualInt_oper[i] != (*pInt)[i] || dInt[i] != (*pInt)[i])
            //error();
            return false;
    }
    dualInt_oper = dualInt_oper;
    delete pInt;
    for (long long i = 0; i < N; ++i){
        if (dualInt_oper[i] != dualInt[i])
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestIteratorSequenceAccess(){
    //std::cout << "Test 6 : Test for accessing the container in the order of the sequence with iterator...";
    sjtu::deque<long long> dInt;
    for (long long i = 0; i < N; ++i) {
        dInt.push_back(i);
    }
    sjtu::deque<long long> :: iterator it;
    it = dInt.begin();

    for (long long i = 0; i < N; ++i) {
        if (*it != dInt[i])
            //error();
            return false;
        ++it;
    }
    if (it != dInt.end())
        //error();
        return false;

    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestIteratorRandomAccess(){
    //std::cout << "Test 7 : Test for accessing the container randomly with iterator...";
    sjtu::deque<long long> dInt;
    std::vector<long long> vInt;
    for (long long i = 0; i < N; ++i) {
        dInt.push_back(i);
        vInt.push_back(i);
    }
    for (long long i = 0; i < N; ++i) {
        if (*(dInt.begin() + i) != vInt[i])
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestInsertAndErase(){
    //std::cout << "Test 8 : Test for insert() and erase()...";
    sjtu::deque<long long> dInt;
    std::vector<long long> vInt;
    for (long long i = 0; i < N; ++i) {
        dInt.push_back(i);
        vInt.push_back(i);
    }
    vInt.insert(vInt.begin() + 6, 2);
    dInt.insert(dInt.begin() + 6, 2);
    vInt.insert(vInt.begin() + 66, 23);
    dInt.insert(dInt.begin() + 66, 23);
    vInt.insert(vInt.begin() + 6666, 233);
    dInt.insert(dInt.begin() + 6666, 233);
    vInt.erase(vInt.begin() + 2333);
    dInt.erase(dInt.begin() + 2333);
    vInt.erase(vInt.begin() + 6666);
    dInt.erase(dInt.begin() + 6666);
    for (long long i = 0; i < N; ++i) {
        if (*(dInt.begin() + i) != vInt[i])
            //error();
            return false;
    }
    //std::cout << "Correct." << std::endl;
    return true;
}
bool TestPopAndPush(){
    //std::cout << "Test 9 : Test for pop() and push()...";
    sjtu::deque<long long> dInt, drInt;
    std::vector<long long> vInt;
    std::vector<long long> rInt;
    for (size_t i = 0; i < 11451LL; ++i){
        dInt.push_back(i);
        vInt.push_back(i);
    }
    for (size_t i = 0; i < 4396LL; ++i){
        dInt.pop_back();
        vInt.pop_back();
    }
    for (size_t i = 0; i < 11451LL; ++i){
        drInt.push_front(i);
        rInt.push_back(i);
    }
    for (size_t i = 0; i < 4396LL; ++i){
        drInt.pop_front();
        rInt.pop_back();
    }
    for (size_t i = 0; i < 7055LL; ++i){
        if (dInt[i] != vInt[i])
            //error();
            return false;
        if (drInt[7054LL - i] != rInt[i])
            //error();
            return false;
    }

    //std::cout << "Correct." << std::endl;
    return true;

}

int main() {
    if (TestInteger() &&
        TestIntegeragain() &&
        TestMatrix() &&
        TestBint() &&
        TestCopyConstructorAndOperatorEqu() &&
        TestIteratorSequenceAccess() &&
        TestIteratorRandomAccess() &&
        TestInsertAndErase() &&
        TestPopAndPush())
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;
    //std::cout << "Congratulations. " << std::endl;
    //std::cout << "Your submission has passed all correctness tests. " << std::endl;
    //std::cout << "Next mission is to use valgrind to ensure that there ain't any memory leaks in your deque. " << std::endl;
    return 0;
}