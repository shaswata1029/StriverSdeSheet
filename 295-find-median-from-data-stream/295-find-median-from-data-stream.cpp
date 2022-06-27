class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==right.size()){
            if(right.size()>0 && num>=right.top())
                right.push(num);
            else
                left.push(num);
        }
        else if(left.size()>right.size()){
            if(num<=left.top()){
                right.push(left.top());
                left.pop();
                left.push(num);
            }else
                right.push(num);
        }
        else{
            if(num>=right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
            }else
                left.push(num);
        }
    }
    
    double findMedian() {
        double median=0;
        if(left.size()==right.size())
            median=(left.top()+right.top())/2.0;
        else if(left.size()>right.size())
            median=left.top()*1.0;
        else 
            median=right.top()*1.0;
        
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */