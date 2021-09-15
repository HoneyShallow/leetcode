#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
using namespace std;

class Solution {
public:
    bool checkValidString1(string s) {
        int minCount = 0, maxCount = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                minCount++;
                maxCount++;
            } else if (c == ')') {
                minCount = max(minCount - 1, 0);
                maxCount--;
                if (maxCount < 0) {
                    return false;
                }
            } else {
                minCount = max(minCount - 1, 0);
                maxCount++;
            }
        }
        return minCount == 0;
    }
	
	
	bool checkValidString2(string s) {
        int len = s.length();
        stack<int> stk;
        stack<int> aster_stk;
        for(int i = 0; i < len; i++){
            if(s[i] == '(') stk.push(i);
            else if(s[i] == '*') aster_stk.push(i);
            else{
                if(!stk.empty())
                    stk.pop();
                else if(!aster_stk.empty())
                    aster_stk.pop();
                else  
                    return false;
            }
        }

        while(!stk.empty() && !aster_stk.empty()){
            int left_ind = stk.top();
            stk.pop();
            int right_ind = aster_stk.top();
            aster_stk.pop();
            if(left_ind > right_ind)
                return false;
        }
        return stk.empty();
    }
};

int main(){
	std::string str{"(*))"};
	auto start = std::chrono::steady_clock::now();
	std::cout << Solution().checkValidString1(str) << std::endl;
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::micro> elapsed = end - start;
	std::cout << "time:" << elapsed.count() << "us" << std::endl;
	return 0;
}
