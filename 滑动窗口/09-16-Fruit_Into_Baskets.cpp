#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // 第一个int表示一种水果，第二个int表示该水果的数量
        unordered_map<int, int> basket; 
        int result = 0, len = 0;
        int left = 0; // 滑动窗口左边界
        for (int i = 0; i < tree.size(); i++) {
            basket[tree[i]]++;
            len++; // 滑动窗口的宽度
            // 当篮子中保存的水果种类超过2种时
            // 去掉最前放入篮子的那种水果
            while (basket.size() > 2) {
                basket[tree[left]]--;
                if (basket[tree[left]] == 0) 
                    basket.erase(tree[left]);
                left++;
                len--;
            }
            if (result < len)
                result = len;
        }
        return result;
    }
};

int main(){
	return 0;
}