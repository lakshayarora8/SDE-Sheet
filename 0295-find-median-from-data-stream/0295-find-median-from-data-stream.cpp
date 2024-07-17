class MedianFinder {
public:
    priority_queue<int> chote;
    priority_queue<int,vector<int>,greater<int>> bade;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(chote.empty() || chote.top() >= num)
        chote.push(num);
        else
        bade.push(num);

        if(chote.size() > 1+bade.size())
        { bade.push(chote.top()); chote.pop();  }
        else if(chote.size() < bade.size())
        {
            chote.push(bade.top());
            bade.pop();
        }    
    }
    
    double findMedian() {

        if((chote.size() + bade.size()) %2 )
        return 1.0*chote.top();
        
        return (chote.top() + bade.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */