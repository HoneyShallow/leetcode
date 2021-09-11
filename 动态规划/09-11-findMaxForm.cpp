#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

class Solution {
public:
    vector<int> get_zeros_ones(const string & str){
        vector<int> ret(2);
        for(auto& c:str)
          ret[c-'0']++;
        return ret;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size(); // 字符串的数目
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>> (m+1, vector<int> (n+1)));

        for(int i = 1; i <= size; i++){
            vector<int> ret = get_zeros_ones(strs[i-1]);
            int zeros = ret[0], ones = ret[1];

            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j >= zeros && k >= ones)
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-zeros][k-ones]+1);
                }
            } 
        }
        return dp[size][m][n];
    }
    int findMaxForm1(vector<string>& strs, int m, int n) {
        int size = strs.size(); // 字符串的数目
        vector<vector<int>> dp(m+1, vector<int> (n+1));

        for(int i = 0; i < size; i++){
            vector<int> ret = get_zeros_ones(strs[i]);
            int zeros = ret[0], ones = ret[1];
            // 此处采用倒序遍历，是为了防止正序遍历
            for(int j = m; j >= zeros; j--){
                for(int k = n; k >= ones; k--){
                        dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones]+1);
                }
            } 
        }
        return dp[m][n];
    }
};

int main() {
	vector<string> tmp{"10", "0001", "111001", "1", "0"};
	int m = 5, n = 3;
	auto start = std::chrono::steady_clock::now();
	int ret = Solution().findMaxForm(tmp, m, n);
	std::cout << ret << std::endl;
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, std::micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
    std::cout<< "time: "  << elapsed.count() << "us" << std::endl;
	
	return 0;
}
