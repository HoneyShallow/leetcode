#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // 方案1：借助额外空间
        // int n = nums.size();
        // vector<int> ret(n);
        // ret[0] = nums[0];
        // for(int i = 1; i < n; i++)
            // ret[i] = ret[i-1]+nums[i];
        // return ret; 
        // 方案2：原地修改
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
        }
        return nums;
    }
};
template<typename T>
void print(const int & x){
	std::cout << x << " ";
}
int main() {
	Solution ans;
	vector<int> v1{1,2,3,4};
	vector<int> v2 = ans.runningSum(v1);
	for_each(v2.begin(), v2.end(), print);
	return 0;
}