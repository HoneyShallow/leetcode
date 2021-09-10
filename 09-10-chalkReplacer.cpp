#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if(chalk[0] > k) return 0;
        //方案2：利用前缀和和二分查找求解
        int n = chalk.size();
        /*
        // 借助额外空间计算前缀和
        vector<long long> prefix_sum(n);
        prefix_sum[0] = chalk[0];
        for(int i = 1; i < n; i++)
            prefix_sum[i] = prefix_sum[i-1]+chalk[i];
        k %= prefix_sum[n-1];
        */
        // 不借助额外空间计算前缀和
        for(int i = 1; i < n; i++){
            chalk[i] += chalk[i-1];
            if(chalk[i] > k) return i;
        } 
        k %= chalk.back();
        // 找到首个大于k的元素位置
        int left = 0, right = n-1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(chalk[mid] > k)
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
	vector<int> chalk{3,4,1,2};
	int k = 25;
	Solution ans;
	int ret  = ans.chalkReplacer(chalk, k);
	std::cout << ret << std::endl;
	return 0;
}
