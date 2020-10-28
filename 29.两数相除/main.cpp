#include <iostream>
#include  <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 1)
            return dividend;
        else if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if(divisor == INT_MIN)
            if(dividend == INT_MIN)
                return 1;
            else
                return 0;
        bool flag = (dividend < 0) ^ (divisor > 0);
        divisor = divisor > 0 ? divisor : -divisor;
        dividend = dividend > 0 ? -dividend : dividend;

        int result = _divide(dividend, divisor);;
        return flag ? result : -result;
    }

    int _divide(int dividend, int divisor){
        if(dividend + divisor > 0)
            return 0;
        else if(dividend + divisor == 0 || divisor > 1073741823)
            return 1;
        int div = 1;
        int tempDivisor = divisor + divisor;
        int prev = divisor;
        while(dividend + tempDivisor <= 0){
            prev = tempDivisor;
            div += div;
            if(tempDivisor > 1073741823)
                break;
            tempDivisor += tempDivisor;
        }
        return div + _divide(dividend+prev, divisor);
    }
};

int main(){
	Solution solution;
	int result = solution.divide(INT_MAX, 2);
	cout << result << endl;
}