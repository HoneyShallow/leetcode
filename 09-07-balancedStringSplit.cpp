#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0;
        int diff = 0; // 记录到当前字符处，'L'和'R'的数量差
        for(auto & c:s){
            c == 'L'? diff++:diff--;
            if(diff == 0) // 如果当前数量差值为0，那么说明从上次差值为0的位置到当前位置所构成的串为平衡串
                ret++;
        }
        return ret;
    }
};

int main() {
	std::string str = "RLRRLLRLRL";
	Solution ans;
	int num = ans.balancedStringSplit(str);
	std::cout << num << std::endl;
	return 0;
}
