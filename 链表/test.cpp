#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val; // 值
	ListNode * next; //下一位置指针
	ListNode(int x):val(x), next(nullptr){}// 有参构造函数
	bool operator==(const ListNode* node){
		return this->val == node->val && this->next == node->next;
	}
	bool operator!=(const ListNode* node){
		return !(this == node);
	}
};

// bool operator==(const ListNode* node1, const ListNode* node2){
	// return node1->val == node2->val && node1->next == node2->next;
// }

/*初始化链表*/
ListNode * init_list(const vector<int> & data){
	ListNode * before = new ListNode(-1);
	ListNode * cur = before;
	for(const auto & x:data){
		ListNode * tmp = new ListNode(x);
		cur->next = tmp;
		cur = cur->next; 
	}
	return before->next;
}
/*打印链表信息*/
void visit_list(const ListNode * head){
	const ListNode * tmp = head;
	while(tmp != nullptr){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
ListNode * find_node(ListNode * head, int value){
	if(head == nullptr) return nullptr;
	ListNode * tmp = head;
	while(tmp != nullptr){
		if(tmp->val == value)
			return tmp;
		tmp = tmp->next;
	}
	return nullptr;
}

void del_node(ListNode * head, ListNode * target){
	ListNode * tmp = nullptr;
	tmp->next = head;
	while(tmp->next != target){
		tmp = tmp->next;
	}
	if(tmp->next == target) {
		tmp->next = target->next;
		delete target;
	}
}
void insert_node(ListNode * head, ListNode * target){
}
int main(){
	vector<int> data{1, 2, 3, 5, 5, 8 ,9};
	ListNode * head = init_list(data); 
	visit_list(head);
	return 0;
}
