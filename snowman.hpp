//
// Created by tovim on 07/03/2021.
//

#ifndef DEMO_CPP_SNOWMAN_HPP
#define DEMO_CPP_SNOWMAN_HPP
#define MAX_VAL 44444444
#define MIN_VAL 11111111
#define MIN_NUM 1
#define MAX_NUM 4
#define DIGITS 7
#include<iostream>
namespace ariel {
    std::string snowman(int prop);
}
bool isLegit(int num);
std::string chooseHat(int num);
std::string chooseNM (int num);
std::string chooseEye (int num);
std::string chooseLA (int num);
std::string chooseRA (int num);
std::string chooseTorso (int num);
std::string chooseBase (int num);
#endif //DEMO_CPP_SNOWMAN_HPP
