class MedianFinder {
public: 
    priority_queue<int, vector<int>, std::less<int>> queMin; 
	// 堆顶元素最大，保存的是小于等于中位数的元素
    priority_queue<int, vector<int>, std::greater<int>> queMax; 
	// 堆顶元素最小，保存的是大于中位数的元素

    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                //如果小顶堆比大顶堆元素少2个，说明大顶堆的堆顶元素已经大于中位数了
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                //如果小顶堆比大顶堆元素多，说明小顶堆的堆顶元素已经小于等于中位数了
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }
    
    double findMedian() {
        if (queMin.size() > queMax.size()) { // 如果大顶堆元素比小顶堆多，说明中位数就是大顶堆堆顶元素
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

/*
 *
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
*/