#include <iostream>
#include <ctime>
#include <cstdlib>
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
private:
	int rand7(){
		return rand()%7+1;
	}
public:
    int rand10() {
        /*方案1：
         rand7生成1-7的数，减1得到0-6的数
        *7得到0-42的数，最后+7得到1-49的数
        我们只需要<=10的数即可*/
        int num = (rand7()-1)*7+rand7();
        while(num > 10){
            num = (rand7()-1)*7+rand7();
        }
        return num;
        /*方案2：*/
        while(true){
            int num = (rand7()-1)*7+rand7();
            if(num <= 40) return 1+num%10;
            // 说明刚才生成的在41-49之间，利用随机数再操作一遍
            num = (num - 40 - 1) * 7 + rand7();
            if(num <= 60) return 1 + num % 10;
            // 说明刚才生成的在61-63之间，利用随机数再操作一遍
            num = (num - 60 - 1) * 7 + rand7();
            if(num <= 20) return 1 + num % 10;
        }
    }
};
int main() {
	std::srand(std::time(nullptr));
	int num = 21;
	Solution ans;
	while(num--){
		int ret = ans.rand10();
		if(ret < 1 || ret > 10){
			std::cout << "algorithm error" << std::endl;
			exit(1);
		}
	}
	std::cout << "algorithm right" << std::endl;
	return 0;
}