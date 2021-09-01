#include <iostream>
using namespace std;
int compare_version(string version1, string version2);

int compare_version(string version1, string version2){
	int m = version1.length(), n = version2.length();
	int p1 = 0, p2 = 0;
	while(p1 < m || p2 < n){
		int x = 0;
		for(; p1 < m && version1[p1] != '.'; p1++)
			x = x*10 + version1[p1]-'0';
		p1++;
		int y = 0;
		for(; p2 < n && version2[p2] != '.'; p2++)
			y = y*10 + version2[p2]-'0';
		p2++;
		if(x != y)
			return x > y?1:-1;
	}
	return 0;
}
int main(){
	string version1 = "1.01", version2 = "1.001";
	std::cout << compare_version(version1, version2) << std::endl;
}