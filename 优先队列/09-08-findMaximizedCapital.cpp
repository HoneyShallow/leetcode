#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /*由于profits指的是纯利润，说明只要启动项目，任意一个项目都可盈利，
        也即是说在完成该项目后手中的资金必然比开展项目前要多，
        那么我们开始分情况来讨论一下，
        1.如果启动资金 w >= max(capital)，那么我们可以通过选择利润最高的前k个项目即可获得最大利润
        2.如果启动资金 w < min(capital), 那么我们只能从启动资金为0的项目开始，
           如果没有启动资金为0的项目，那么我们最终的利润必然为0,
           如果存在若干个启动资金为0的项目，我们很自然的会想到从利润最大x的那个项目开始
           将该项目从列表中删除，此时启动资金就变成了x,
                如果此时x < min(captial)那么重新从2开始;
                如果 x >= max(capital)，那么就转为1.
                如果 min(capital) <= x < max(captial),那么我们就对比找到满足x >= captial_i条件的
                利润最大captial_i的项目
           
        */

        int n = profits.size();
        priority_queue<int, vector<int>, std::less<int>> que; // 大顶堆

        /*将各项目资金按从小到大的顺序排列*/
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n ;i++)
            tmp.push_back({capital[i], profits[i]});
        auto cmp = [](const pair<int, int> & a, const pair<int, int> & b){
            return a.first < b.first;
        };
        sort(tmp.begin(), tmp.end(), cmp);

        int curr = 0; // 用来记录插入到队列中的列表元素下标，以防越界
        for (int i = 0; i < k; ++i) { 
            // 外层循环是获得k各项目的最大利润
            // 内层循环时获取当前条件下的一个项目的最大利润
            while (curr < n && tmp[curr].first <= w) {
                // 将满足资本条件的项目利润插入到大顶堆中
                que.push(tmp[curr].second);
                curr++;
            }
            // 此时大顶堆中的利润均是可操作项目的利润，对顶是各项目中的最大利润
            if (!que.empty()) {
                w += que.top();
                que.pop();
            } else {
                break;
            }
        }
        return w;
    }
};

int main() {
	int k = 3, w = 0;
	vector<int> capital{0, 1, 2};
	vector<int> profits{1, 2, 3};
	Solution ans;
	int ret = ans.findMaximizedCapital(k, w, profits, capital);
	std::cout << k << "个项目的最大利润为 " <<  ret << std::endl;
}
