//provided by ivy

#include "src.hpp"
#include "class-matrix.hpp"
#include "class-bint.hpp"
#include <iostream>
/*
void complex_test()
{
    std::cout << "Supplementary test for large amounts of data ..." << std::endl;
    sjtu::vector<Diamond::Matrix<Util::Bint>> myVec;
    for (int i = 1; i <= 1926; ++i)
        myVec.push_back(Diamond::Matrix<Util::Bint>(i % 8 + 1, i % 17 + 1, Util::Bint(i * 817)));
    int o = 1234;
    while (o--)
        myVec.pop_back();
    myVec = myVec;
    int _ = 20, __ = myVec.size();
    while (_--)
    {
        if (_ % 2 == 0)
            std::cout << myVec[_][0][0] << std::endl;
        else
            std::cout << myVec[__ - _][0][0] << std::endl;
    }
    std::cout << "Finished!" << std::endl;
}
*/
// update by Anoxiacxy 2021 2 25

bool complex_test()
{
    sjtu::vector<Diamond::Matrix<Util::Bint>> myVec;
    std::vector<Diamond::Matrix<Util::Bint>> myVec_ans;
    for (int i = 1; i <= 518; ++i)
        myVec.push_back(Diamond::Matrix<Util::Bint>(i % 8 + 1, i % 17 + 1, Util::Bint(i * 817))),
        myVec_ans.push_back(Diamond::Matrix<Util::Bint>(i % 8 + 1, i % 17 + 1, Util::Bint(i * 817)));
    int o = 432;
    while (o--)
        myVec.pop_back(), myVec_ans.pop_back();
    myVec = myVec;
    myVec_ans = myVec_ans;
    int _ = 20, __ = myVec.size();
    while (_--)
    {
        if (_ % 2 == 0) {
            if (!(myVec_ans[_][0][0] == myVec[_][0][0]))
                return false;
        }
        else {
            if (!(myVec_ans[__ - _][0][0] == myVec[__ - _][0][0]))
                return false;
        }
    }
    return true;
}

int main()
{
    double score = 0;
    if (complex_test())
        score += 1;
    std::cout << score << std::endl;
    return 0;
}