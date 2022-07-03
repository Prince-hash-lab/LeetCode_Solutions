class MyQueue {
    stack<int> s1;
    stack<int> s2;
    int front;
public:
    MyQueue() {
        front=-1;
        
    }
    
    void push(int x) {
        if(s1.empty()) front=x;
        s1.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ele=front;
        s2.pop();
        if(!s2.empty()) front=s2.top();
        else front=-1;
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }
    
    int peek() {
        return front;
        
    }
    
    bool empty() {
        if(front==-1) return true;
        return false ;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */