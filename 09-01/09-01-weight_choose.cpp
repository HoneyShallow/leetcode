#include <iostream>
using namespace std;

class Solution {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre; /*前缀和*/

    int binary_search(int x){
        int left = 0, right = pre.size()-1;
        while(left < right){
            int middle = left + (right - left)/2;
            if(pre[middle] < x)
                left = middle + 1;
            else 
                right = middle;
        }
        return left;
    }
public:
    Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        int n = w.size(); // 权重
        pre.resize(n);
        pre[0] = w[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1]+w[i];
    }
    
    int pickIndex() {
        int x = dis(gen);
        return binary_search(x);
    }
};

int main(){
	vector<int> weight{3,1,2,4};
	Solution s1(weight);
	while(1){
		std::cout << s1->pickIndex() << endl;
	}
	return 0;
}
