#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
	vector<int> dp(n, 0);
	// 利用差分数组和前缀和，dp[i]表示第i个元素同第i-1个元素的差值
	// 初始情况下，为全0，由于对于该题而言时在指定区间[l, r]内做增量aug
	// 那么每当获取一次订单，由于增量的存在，dp[l]较之前的差值就会+aug
	// dp[r+1]较之前就会-aug,而区间内的差值不会改变
	for(auto & booking:bookings){
		dp[booking[0]-1] += booking[2];
		if(booking[1] < n)
			dp[booking[1]] -= booking[2];
	}
	// 在最后利用差分数组的前缀和即可求出答案;
	for(int i = 1; i < n; i++)
		dp[i] += dp[i-1];
	return dp;
}
//template <typename T>
template <class T>
void print(const T & x){
	std::cout << x << " ";
}
int main(){
/*输出：[10,55,45,25,25]*/
	vector<vector<int>> bookings ;
	vector<int> tmp1 = {1,2,10};
 	vector<int> tmp2 = {2,3,20};
	vector<int> tmp3 = {2,5,25};
	bookings.push_back(tmp1);
	bookings.push_back(tmp2);
	bookings.push_back(tmp3);
	int n = 5;
	vector<int> pro(n);
	pro = corpFlightBookings(bookings, n);
	for_each(pro.begin(), pro.end(), print<int>);

	return 0;
}
