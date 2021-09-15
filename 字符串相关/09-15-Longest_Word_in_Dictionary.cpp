#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> hash;
        string ans = "";
        // 哈希集合用于存储对比的前缀字符串
        for(auto &word:words)
            hash.insert(word);
        
        // 找出长度比我们当前选取的最有字符串长的后者长度相同但字典序更靠前的字符串，判断其个前缀是否再哈希集合中，如果满足，更新最优字符串
        for(auto & word:words){
	    int len_tmp = ans.length();
            if(len_tmp < word.length() || 
            len_tmp == word.length() && word < ans){
                bool tmp = true;
                for(int i = 1; i < word.length(); i++){
                    string str = word.substr(0, i);
                    if(hash.count(str) == 0){
                        tmp = false;
                        break;
                    }   
                }
                if(tmp)
                    ans = word;
            }
        }
        return ans;
    }
};
int main() {
	vector<string> words{"w","wo","wor","worl","world"};
	cout << Solution().longestWord(words) << endl;
	return 0;
}
