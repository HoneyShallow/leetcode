#include <iostream>       
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
	public:
		const int BASE = 1000000007;
		unordered_map<int, long> hash;
		int fib1(int n){
			/*方案1：递归并利用额外空间减少超过重复计算*/
			if(n < 2) return n;
			if(hash.count(n) > 0)
				return hash[n];
			int ret = (fib1(n-1)+fib1(n-2)) % BASE;
			hash[n] = ret;
			return ret;
		}
		int fib2(int n){
			/*方案2：动态规划*/
			if(n < 2) return n;
			// const int BASE = 1000000007;
			vector<int> dp(n+1, 0);
			dp[0] = 0, dp[1] = 1;
			for(int i = 2; i < n+1; i++){
				dp[i] = (dp[i-1]+dp[i-2])%BASE;
			}
			return dp[n];
		}
		int fib3(int n){
			if(n < 2) return n;
			// const int BASE = 1000000007;

			int ai =0, bi = 0, ret = 1;
			for(int i = 2; i < n+1 ;i++){
				ai = bi;
				bi = ret;
				ret = (ai+bi)%BASE;
			}
			return ret;
		}
};

int main(){
	int n;
	std::cout << "enter n ";
	std::cin >> n;

	std::cout << "fib1(n) = " << Solution().fib1(n) << std::endl;
	std::cout << "fib2(n) = " << Solution().fib2(n) << std::endl;
	std::cout << "fib3(n) = " << Solution().fib3(n) << std::endl;
	return 0;
}




