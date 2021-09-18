#include <iostream>
#include <vector>
using namespace std;

/*结点结构体*/
struct ListNode {
	int val;
	ListNode * next;
	ListNode():val(0), next(nullptr){}
	ListNode(int x):val(x), next(nullptr){}
	ListNode(int x, ListNode * ptr_next):val(x), next(ptr_next){}
};
ListNode * create_list(const vector<int> & data){
	ListNode* dummy_node = new ListNode(-1); //哑节点
	ListNode * cur = dummy_node;
	for(const auto & x:data){
		ListNode* tmp = new ListNode(x);
		cur->next = tmp;
		cur = cur->next;
	}
	cur = dummy_node->next;
	delete dummy_node;
	
	return cur;
}

void show_list(ListNode* head){
	ListNode * tmp = head;
	while(tmp != nullptr){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


class Solution {
public:
    void reverse_list(ListNode * head){
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while(cur != nullptr){
            ListNode * tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
    }
    void reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy_node = new ListNode(-1);
        dummy_node->next = head;
        // 找到要反转区间的前驱结点，和后继节点
        ListNode * pre = dummy_node;
        for(int i = 0; i < left-1; i++)
            pre = pre->next;
        // pre指向前驱结点
        // left_node指向区间左结点
        ListNode * left_node = pre->next;
        ListNode * right_node = left_node;
        for(int i = 0; i < right-left; i++)
            right_node = right_node->next;
        // right_node指向区间左结点
        // suc指向区间后继结点
        ListNode * suc = right_node->next;

        pre->next = nullptr;
        right_node->next = nullptr;

        /*反转链表区间，虽然链表确实反转了，但是左右各链表指针指向的结点却没有变化*/
        reverse_list(left_node); 

        pre->next = right_node;
        left_node->next = suc;
		
		head = dummy_node->next;
		delete dummy_node;
		
        // return head;
    }
};

int main(){
	int left = 2, right = 4;
	vector<int> data{1,2,3,4,5};
	ListNode* head = create_list(data);
	show_list(head);
	Solution().reverseBetween(head, left, right);
	show_list(head);
	return 0;
}

