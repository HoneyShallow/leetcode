#include <iostream>
#include <vector>
#include <unordered_map> // 哈希映射
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3) return 0; // 如果坐标点数少于3,肯定没有回旋镖
        // 用坐标点在数组中的索引代表该点，则两点间的信息可以用
        // {(i, j),distance}
        int ret = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> dis_info;
            for(int j = 0; j < n;j++){ // 不能再循环条件处使用i!=j因为，当i == j,就跳出循环了，而此时有可能还有点的信息为统计
                if(i == j) continue; // 跳过自身
                int x1 = points[i][0],y1 = points[i][1];
                int x2 = points[j][0],y2 = points[j][1];
                int dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                ++dis_info[dis];
            }
            // 在以x0为拐点时，虽然x2和x3到它的距离相同，不过折线是有方向的，也即(x2, x3)和(x3,x2)对应不同的折线,所以下边用的是排列而非组合
            for(auto &[_,times]:dis_info){
                ret += times*(times-1);
            }
        }
        return ret;
    }
};
// void print(vector<vector<int>> & vec){
	// for(auto it = vec.begin(); it != vec.end(); it++){
		// for(auto it1 = (*it).begin(); it1 != (*it).end(); it1++)
			// std::cout << *it1 << " ";
		// std::cout << std::endl;
	// }
// }
template<typename T>
void print(T & vec){
	for(auto it = vec.begin(); it != vec.end(); it++){
		for(auto it1 = (*it).begin(); it1 != (*it).end(); it1++)
			std::cout << *it1 << " ";
		std::cout << std::endl;
	}
}
int main() {
	vector<vector<int>> points{{0,0},{1,0},{2,0}};
	print<vector<vector<int>>>(points);
	std::cout << "the number of boomerangs is/are " 
			<< Solution().numberOfBoomerangs(points) 
			<< std::endl;
	return 0;
}
