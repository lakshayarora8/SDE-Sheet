class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;

    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size=q.size()-1;
        while(size>0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
         int size=q.size()-1;
        while(size>0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
        int x=q.front();
        q.pop();
        q.push(x);
        return x;    
    }
    
    bool empty() {
        return q.empty();
    }
};

