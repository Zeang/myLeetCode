#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int prevNum = 0, Num = 0;
        for(auto& a : s){
            prevNum = Num;
            switch(a){
                case 'I':
                    Num = 1;
                    break;
                case 'V':
                    Num = 5;
                    break;
                case 'X':
                    Num = 10;
                    break;
                case 'L':
                    Num = 50;
                    break;
                case 'C':
                    Num = 100;
                    break;
                case 'D':
                    Num = 500;
                    break;
                case 'M':
                    Num = 1000;
                    break;
            }
            if(prevNum < Num){
                result -= prevNum;
            }else{
                result += prevNum;
            }
        }
        return result+Num;
    }
};

int main(){
    Solution solution;
    cout << solution.romanToInt("MCMXCIV");
}