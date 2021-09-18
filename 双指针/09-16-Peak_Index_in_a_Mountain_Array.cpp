#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print(const T & );

class Solution {
public:
/*山脉数组的峰值索引*/
    int peakIndexInMountainArray(vector<int>& arr) {
        // 找出数组中的最大值的索引
        int left = 0, right = arr.size()-1;
        while(left < right){    
            int mid = left+(right-left)/2;
            if(arr[mid] > arr[mid+1])
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};

class Solution1 {
public:
/*寻找峰值元素索引*/
    int findPeakElement(vector<int>& nums) {
        /* 如何查找峰值呢，利用二分法，索引到中间值，
        如果该值严格大于其右侧的值，那么峰值出现在左半区域
		相反的，峰值出现在右半区域
        */
        //根据题干可知，我们默认nums[-1]和nums[n]是理论存在的，也即可访问的索引
        int left = 0, right = nums.size()-1;
        //由于每次都是要和mid相比，那么mid+1有可能越界
        while(left < right){
            int mid = left+(right-left)/2;
            if(nums[mid] > nums[mid+1])
                right = mid;
            else 
                left = mid+1;
        }
        return left;
    }
};

template<typename T>
void print(const T & x){
	cout << x << " ";
}
int main(){
	vector<int> arr = {3,4,5,1};
	for_each(arr.begin(), arr.end(), print<int>);
	cout << "peak index = " << Solution().peakIndexInMountainArray(arr) << endl;
	vector<int> arr1 = {1,2,1,3,5,6,4};
	for_each(arr1.begin(), arr1.end(), print<int>);
	cout << "peak element = " << Solution1().findPeakElement(arr1) << endl;
	return 0;
}
