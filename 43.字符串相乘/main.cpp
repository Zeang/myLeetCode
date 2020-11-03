#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	string result = "";
    	string temp;
        for(int i = 0; i < num2.size(); ++i){
        	temp = multiplyC(num1, num2[i]);
        	if(result != "0")
        		result += "0";
        	result = add(result, temp);
        }

        return result;
    }

    string multiplyC(string num1, char a){
        int ai = a - '0';
        if(ai == 0)
        	return "0";
        int temp = 0;
        string result = "";
        for(int i = num1.size()-1; i >= 0;  --i){
        	int bi = num1[i] - '0';
        	int num = bi * ai + temp;
        	result = to_string(num%10) + result;
        	temp = num/10;
        }
        if(temp > 0)
        	result = to_string(temp) + result;
        return result;
    }

    string add(string a, string b){
    	int M = a.size();
    	int N = b.size();
    	string result = "";
    	int temp = 0;
    	for(int i = 1; i <= M && i <= N; ++i){
    		int num = a[M-i]-'0' + b[N-i]-'0' + temp;
    		result = to_string(num%10) + result;
    		temp = num/10;
    	}
    	string sTemp;
    	if(M > N)
    		sTemp = a.substr(0, M-N);
    	else{
    		sTemp = b.substr(0, N-M);
    	}
    	M = sTemp.size();
    	for(int i = 1; i <= M; ++i){
    		int num = sTemp[M-i] - '0' + temp;
    		result = to_string(num%10) + result;
    		temp = num/10;
    	}
    	if(temp > 0)
    		result = to_string(temp) + result;
    	return result;
    }
};

int main(){
	Solution solution;
	string a = "0";
	string b = "42";
	cout << solution.multiply(a, b) << endl;

}