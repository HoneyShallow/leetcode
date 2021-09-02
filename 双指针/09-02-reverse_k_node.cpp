#include <iostream>

struct ListNode {
public:
	int val;
	ListNode * next;
	ListNode(int x):val(x), next(nullptr){}
}

ListNode* init_list(vector<int> elems){
	int num = elems.size(); 
	if(num == 0) return nullptr;
	/*采用尾插法*/
	ListNode * tail = nullptr, *head = nullptr;
	head->next = tail;
	for(auto & elem:elems){
		ListNode* tmp = new listNode(elem);
		tail->next = tmp;
		tail = tmp;
	}
	return head->next;
}
void print_list(ListNode * head){
	listNode * tmp = head->next;
	while(tmp != nullptr){
		std::cout << tmp->val << " "; 
	}
	std::cout << std::endl;
}
ListNode* getKthFromEnd(ListNode* head, int k){
	//方案1：首先顺序遍历一遍链表共有n个结点
	// 倒数第k个结点，也即正数第n-k个结点
	int num = 0;
	ListNode * tmp = head;
	while(tmp != nullptr){
		num++;
		tmp = tmp->next;
	}
	tmp = head;
	int dir_in = num-k;
	while(dir_in){
		tmp = tmp->next;
		dir_in--;
	}
	return tmp;
	// 方案2：快指针先请进k步，然后快慢指针在同时一步前进，
	// 当快指针到达超尾结点时，慢结点正好指向倒数第k个结点
	ListNode* fast = head, *slow = head;
	for(int i = 0; i < k; i++)
		fast = fast->next;
	while(fast != nullptr){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	vector<int> data = {1, 2, 3, 4, 5};
	int k = 2;
	ListNode * head = init_list(data);
	ListNode * kth_node = getKthFromEnd(head, k);
	print_list(kth_node);
	return 0;
}