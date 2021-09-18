#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 
[numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度

*/
class Solution {
public:
    int minSubArrayLen(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int n = nums.size();
        int start = 0, end = 0;
        int sum = 0;
        while(end < n){
            sum += nums[end];
            while(sum >= target){
                ans = min(ans, end-start+1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX?0:ans;
    }
};

int main(){
	vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
	cout << "shortest substr length: " << Solution().minSubArrayLen(nums,target) << endl;
	return 0;
}
