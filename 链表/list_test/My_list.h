#ifndef My_list_H
#define My_list_H

struct ListNode{
	int val;
	ListNode* next;
	// ListNode():val(0), next(nullptr){}
	ListNode(int x):val(x), next(nullptr){}
	ListNode(int x, ListNode* ptr):val(x), next(ptr){}
	bool operator==(const ListNode * node){
		return this->val == node->val && this->next == node->next;
	}
	bool operator!=(const ListNode * node){
		return !(this == node);
	}
};

class MyLinkedList {
public:
	MyLinkedList();
	~MyLinkedList();
	MyLinkedList(const MyLinkedList & another);
	MyLinkedList operator=(const MyLinkedList & another);
	int get(int index) const;
    void addAtHead(int val);
	void addAtTail(int val);
    void addAtIndex(int index, int val);
	void deleteAtIndex(int index);
	void show_list() const;
	bool is_empty() const;
		
    
private:
    ListNode * dummy_node;
    ListNode * tail;
    int size;
};

 /** Initialize your data structure here. */
MyLinkedList::MyLinkedList() { // 初始化链表
	tail = nullptr;
	dummy_node = new ListNode(0, tail);
	size = 0;
}

MyLinkedList::~MyLinkedList(){
	delete dummy_node;
	dummy_node = nullptr;
}
MyLinkedList::MyLinkedList(const MyLinkedList & another){
	this->dummy_node = new ListNode((another.dummy_node)->val);
	this->tail = another.tail;
	this->size = another.size;
}
MyLinkedList MyLinkedList::operator=(const MyLinkedList & another){
	if(*this == another) return *this;
	this->dummy_node = new ListNode((another.dummy_node)->val);
	this->tail = another.tail;
	this->size = another.size;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int MyLinkedList::get(int index) const{ // 复杂度为n
	if(index < 0 || index >= size)
		return -1;
	ListNode * tmp = dummy_node->next;
	while(index--){
		tmp = tmp->next;
	}
	return tmp->val;
}
/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void MyLinkedList::addAtHead(int val) {
	ListNode * tar = new ListNode(val);
	tar->next = dummy_node->next; 
	dummy_node->next = tar;
	
	size++;
}
    
/** Append a node of value val to the last element of the linked list. */
void MyLinkedList::addAtTail(int val) {
	ListNode * tar = new ListNode(val);
	if(size == 0)
		tail = tar;
	else{
		tail->next = tar;
		tail = tar;
	}
	size++;
}
    
/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void MyLinkedList::addAtIndex(int index, int val) {
	if(index > size) 
		return;
	else if(size == index) {
		addAtTail(val);
		return;
	} 
	else if(index < 0){
		addAtHead(val);
		return;
	}

	ListNode * pre = dummy_node;
	while(index--)
		pre = pre->next;
	ListNode * tar = new ListNode(val);
	tar->next= pre->next;
	pre->next= tar;
	size++;
}
/** Delete the index-th node in the linked list, if the index is valid. */
void MyLinkedList::deleteAtIndex(int index) {
	if(index < 0 || index >= size)
		return;
	ListNode * pre = dummy_node;
	while(index--)
		pre = pre->next;
	// 如果要删除的结点是尾结点
	if(pre->next == tail){
		delete tail;
		tail = pre;
	}else {
		ListNode * tmp = pre->next;
		pre->next = tmp->next;
		delete tmp;
	}
	size--;
}
void MyLinkedList::show_list() const{
	ListNode * tmp = dummy_node->next;
	while(tmp != nullptr){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
bool MyLinkedList::is_empty() const{
	return size == 0;
}
#endif