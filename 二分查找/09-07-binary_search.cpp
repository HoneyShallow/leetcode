#include <iostream>
using namespace std;

class Solution {
public:
    int search1(vector<int>& nums, int target) {
        /*方案1：*/
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else 
                right = mid;
        }
        if(left == right && nums[left] == target)
            return left;
        else 
            return -1;
    }
	
	int search2(vector<int>& nums, int target) {
	 /* 方案2:*/
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < taget)
                left = mid + 1;
            else 
                right = mid;
        }
        return -1;
	}
};

int main() {
	Solution ans;
	vector<int> v{-1,0,3,5,9,12};
	int target1 = 9, target2 = 2;
	ans.search1(v, target1);
	ans.search1(v, target2);
	return 0;
}