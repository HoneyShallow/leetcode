#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
	unordered_map<char, int> ori,cnt;
	
	bool deter(){ // 判断当前的动态哈希表是否可以构成原哈希表
		for(const auto & x:ori){
			if(cnt[x.first] < x.second)
				return false;
		}
		return true;
    }
public:
   
    string minWindow(string s, string t) {
        // 首先将t中所出现的字符信息保存在ori中
        for(auto &c:t)
            ++ori[c];
            
        int len = INT_MAX;
        int slow = 0, fast = -1;
        int ans_left = -1;//用来保存满足条件的字串的起始位置
        while(fast < (int)s.size()){
            // 如果当前元素在t中出现过，则记录
            if(ori.find(s[++fast]) != ori.end())
                ++cnt[s[fast]];
            while(deter() && slow <= fast){
                int tmp_len = fast-slow+1;
                // 如果当前子串长度比前边满足条件的字串长度短
                // 记录当前子串为最优字串
                if(tmp_len < len){
                    len = tmp_len;
                    ans_left = slow;
                }
                // 如果开头的元素出现在t中，那么
                if(ori.find(s[slow]) != ori.end())
                    --cnt[s[slow]];
                slow++;
            }
        }
        return ans_left == - 1 ? string("") :s.substr(ans_left, len);
    }
};

int main(){
	string s = "ADOBECODEBANC", t = "ABC";
	cout << "shorest substring :" << Solution().minWindow(s, t) << endl;
	return 0;
}
/*
vector<vector<int>> B = {{1,2}, {3, 4}}; 
1,2
3,4

vector<int> C = {5, 6};
B.push_back(C);

1,2
3,4
5,6
*/