#include <iostream>
using namespace std;
int compare_version(string version1, string version2);

int compare_version(string version1, string version2){
	int m = version1.length(), n = version2.length();
	int p1 = 0, p2 = 0;
	while(p1 < m || p2 < n){
		int x = 0;
		// x为version1 中.前的有效整数
		for(; p1 < m && version1[p1] != '.'; p1++)
			x = x*10 + version1[p1]-'0';
		p1++; // 跳过.
		// y为 version2 中.前的有效整数
		int y = 0;
		for(; p2 < n && version2[p2] != '.'; p2++)
			y = y*10 + version2[p2]-'0';
		p2++;
		// 逐次比较x与y的值也即比较两个版本号，若不等，则可以直接返回大小
		// 若等，比较下一个.前的整数，直至遍历完某个版本号
		if(x != y)
			return x > y?1:-1;
	}
	return 0;
}
int main(){
	string version1 = "1.01", version2 = "1.001";
	std::cout << compare_version(version1, version2) << std::endl;
}