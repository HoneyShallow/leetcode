#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // 如何判断dictionary中的字符串能由s删除某些元素得到呢
        /*利用双指针，如何能在遍历完参考字符串之前，遍历完子字符串
        则该字符串就能由参考字符串删除某些元素得到
        而确定长度和字典序则由条件限制
        */
		int len_s = s.size();
        string ans = "";
        for(auto &dic:dictionary){
            int len_tmp = ans.size(), len = dic.length();
            if(len_tmp < len || (len_tmp == len && ans > dic)){
                int i = 0, j = 0;
                while(i < len && j < len_s){
                    if(dic[i] == s[j]){
                        i++;
                    }
                    j++;
                }
                if(i == len)
                    ans = dic;
            }
        }
        return ans;
    }
};

int main() {
	vector<string> dictionary{"ale","apple","monkey","plea"};
	string s = "abpcplea";
	cout << Solution().findLongestWord(s, dictionary) << endl;
	return 0;
}