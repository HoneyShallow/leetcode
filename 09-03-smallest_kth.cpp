#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        /*方案1.将数组按从小到大的顺序排序，取前k个元素即可*/
	/*
        vector<int> ret(k);
        sort(arr.begin(), arr.end(), std::less<int>());
        copy(arr.begin(), arr.begin()+k, ret.begin());
        return ret;
	*/
        /*方案2：利用最大顶堆*/
        if(k == 0) return {};
        vector<int> ret;
        priority_queue<int, vector<int>, std::less<int>> que;
        for(int i = 0; i < k; i++)
            que.push(arr[i]);
        for(int j = k; j < arr.size(); j++){
            if(que.top() > arr[j]){
                que.pop();
                que.push(arr[j]);
            }
        }
        while(!que.empty()){
            ret.emplace_back(que.top());
            que.pop();
        }
        return ret;
    }
};

void print(const int & x){
		std::cout << x << " ";
}
int main() {
	vector<int> test = {1,3,5,7,2,4,6,8};
	int k = 4;
	Solution ans;
	vector<int> ret = ans.smallestK(test, k);
	for_each(ret.begin(), ret.end(), print);
	return 0;
}
