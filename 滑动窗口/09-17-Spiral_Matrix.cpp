#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void print(const T &);

template<typename T>
void print(const T &x){
	cout << x << " ";
}

template<> void print(const vector<vector<int>> & mat){
	for(vector<vector<int>>::const_iterator it = mat.begin(); it != mat.end(); it++){
		for(vector<int>::const_iterator it1 = (*it).begin(); it1 != (*it).end(); it1++){
			cout << *it1 << " ";
		}
		cout << endl;
	}
}
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> acc(m, vector<int> (n,0));// 记录矩阵数据的访问情况
        vector<int> ret;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_i = 0;
        int row_i = 0, col_i = 0;
        int ori_num = 0, ori_sum = m*n; // 共需要访问多少元素，每访问一个访问数目+1
        while(ori_num < ori_sum){
            ret.push_back(matrix[row_i][col_i]);
            ori_num++;
            acc[row_i][col_i] = 1;
            int next_row_i = row_i + dir[dir_i][0], next_col_i = col_i + dir[dir_i][1];
            if(next_row_i < 0 || next_row_i >= m || next_col_i < 0 || next_col_i >= n || acc[next_row_i][next_col_i])
                dir_i = (dir_i + 1) % 4;
            row_i += dir[dir_i][0];
            col_i += dir[dir_i][1];
        }
        return ret;
    }
};
int main(){
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	print(matrix);
	vector<int> ret = Solution().spiralOrder(matrix);
	for_each(ret.begin(), ret.end(), print<int>);
	return 0;
}