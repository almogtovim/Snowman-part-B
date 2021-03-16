//
// Created by tovim on 07/03/2021.
//
#include <iostream>
#include "snowman.hpp"
#include <sstream>


using namespace std;


bool isLegit(int num){
    const int ten = 10;
    if (num > MAX_VAL || num < MIN_VAL ) { return false; }
    int tmp = num;
    while (tmp > 0){
        if (tmp%ten < MIN_NUM || tmp%ten > MAX_NUM) { return false; }
        tmp /= ten;
    }
    return true;
}
string chooseHat(int num){
    string straw = "\n _===_ ";
    string mexican = "  ___  \n ..... ";
    string fez = "   _   \n  /_\\  ";
    string russian = "  ___  \n (_*_) ";
    switch(num) {
        case 1:
            return straw;
        case 2:
            return mexican;
        case 3:
            return fez;
        case 4:
            return russian;
    }
    return "something wrong";
}
string chooseNM (int num){
    string normal = ",";
    string dot = ".";
    string line = "_";
    string none = " ";
    switch(num) {
        case 1:
            return normal;
        case 2:
            return dot;
        case 3:
            return line;
        case 4:
            return none;
    }
    return "something wrong";
}
string chooseEye (int num){             /* chooseEye */
    string dot = ".";
    string biggerDot = "o";
    string biggestDot = "O";
    string closed = "-";
    switch(num) {
        case 1:
            return dot;
        case 2:
            return biggerDot;
        case 3:
            return biggestDot;
        case 4:
            return closed;
    }
    return "something wrong";
}
string chooseLA (int num){
    string normal = "<";
    string upwards = "\\";
    string downwards = "/";
    string none = " ";
    switch(num) {
        case 1:
            return normal;
        case 2:
            return upwards;
        case 3:
            return downwards;
        case 4:
            return none;
    }
    return "something wrong";
}
string chooseRA (int num){
    string normal = ">";
    string upwards = "/";
    string downwards = "\\";
    string none = " ";
    switch(num) {
        case 1:
            return normal;
        case 2:
            return upwards;
        case 3:
            return downwards;
        case 4:
            return none;
    }
    return "something wrong";
}
string chooseTorso (int num){
    string buttons = "( : )";
    string vest = "(] [)";
    string inward = "(> <)";
    string none = "(   )";
    switch(num) {
        case 1:
            return buttons;
        case 2:
            return vest;
        case 3:
            return inward;
        case 4:
            return none;
    }
    return "something wrong";
}
string chooseBase (int num){
    string buttons = " ( : ) ";
    string feet = " (\" \") ";
    string flat = " (___) ";
    string none = " (   ) ";
    switch(num) {
        case 1:
            return buttons;
        case 2:
            return feet;
        case 3:
            return flat;
        case 4:
            return none;
    }
    return "something wrong";
}
namespace ariel{
    std::string snowman(int prop){
        if (!isLegit(prop)) { throw  "Please enter another number"; }
        string str = to_string(prop);
        std::stringstream mySS;
        string base;
        string mn;
        string lEye;
        string rEye;
        string lArm;
        string rArm;
        string hat;
        string torso;
        string lUp;
        string rUp;
        enum Case {hatcase=0, nm=1, lefteye=2,righteye=3, lefta=4, righta=5, tor=6, baseline=7 };
        for (int i = 0; i <= DIGITS; i++){                    //   HNLRXYTB
            switch(i) {
                case hatcase:
                    hat = chooseHat(str[i]-'0');
                case nm:
                    mn = chooseNM(str[i]-'0');
                case lefteye:
                    lEye = chooseEye(str[i]-'0');
                case righteye:
                    rEye = chooseEye(str[i]-'0');
                case lefta:
                    if (str[i]-'0' == 2) {
                        lUp = chooseLA(str[i] - '0');
                        lArm = " ";
                    }
                    else{
                        lUp = " ";
                        lArm = chooseLA(str[i] - '0');
                    }
                case righta:
                    if (str[i]-'0' == 2) {
                        rUp = chooseRA(str[i] - '0');
                        rArm = "";
                    }
                    else{
                        rUp = "";
                        rArm = chooseRA(str[i] - '0');
                    }
                case tor:
                    torso = chooseTorso(str[i]-'0');
                case baseline:
                    base = chooseBase(str[i]-'0');
            }
        }
        mySS << hat << "\n" << lUp << "(" << lEye << mn << rEye << ")" << rUp << "\n" << lArm << torso << rArm << "\n" << base <<"\n";
        string snowShape = mySS.str();
        return snowShape;
    }
}