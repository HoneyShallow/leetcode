#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>> & mat){
	for(vector<vector<int>>::const_iterator it = mat.begin(); it != mat.end(); it++){
		for(vector<int>::const_iterator it1 = (*it).begin(); it1 != (*it).end(); it1++){
			cout << *it1 << " ";
		}
		cout << endl;
	}
}
class Solution1 {
	/*按层模拟，由外往里填充数据*/
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int count = 1; // 每个元素要填充的数字

        int ori_i = 0, ori_j = 0; // 初始的起点位置
        int loop_nums = n/2; // 共需要的圈数
        int loop_offset = 1; // 每一圈在各方向上允许的偏移量
        while(loop_nums--){
            int i = ori_i, j = ori_j;
            // 矩形右向上边
            for(j = ori_j; j < ori_j+n-loop_offset; j++)
                ret[i][j] = count++;
            // 矩形下向右边
            for(i = ori_i; i < ori_i+n-loop_offset; i++)
                ret[i][j] = count++;
            // 矩形左向下边
            for(;j > ori_j; j--)
                ret[i][j] = count++;
             // 矩形上向左边
            for(;i > ori_i; i--)
                ret[i][j] = count++;
            ori_i += 1, ori_j += 1;
            loop_offset += 2;
        }
        if(n % 2 != 0)
            ret[n/2][n/2] = count;
        return ret;
    }
};

class Solution {
/*模拟实际方向填充数据*/
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        /*这种解题方案的精髓在于，方向，
        右：行索引不变，列索引+1
        下：列索引不变，行索引+1
        左：行索引不变，列索引-1
        上：列索引不变，行索引-1
        */
        int max_num = n*n;
        int cur_num = 1;
        int row_i = 0, col_i = 0; // 行索引和列索引
        int dir_i = 0; // 方向索引
        while (cur_num <= max_num) {
            ret[row_i][col_i] = cur_num; // 填充当前位置的数据，
            cur_num++;
            // 计算下一个要填充的位置
            int nextRow = row_i + dir[dir_i][0], nextColumn = col_i + dir[dir_i][1];
            // 如果下一位越过边界，或者已经被填充过，修改填充方向
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || ret[nextRow][nextColumn] != 0) {
                dir_i = (dir_i + 1) % 4;  // 顺时针旋转至下一个方向
            }
            // 重新计算下一个要填充的位置
            row_i = row_i + dir[dir_i][0];
            col_i = col_i + dir[dir_i][1];
        }
        return ret;
    }
};

int main() {
	int n = 4;
	vector<vector<int>> ret = Solution().generateMatrix(n);
	print(ret);
	return 0;
}
