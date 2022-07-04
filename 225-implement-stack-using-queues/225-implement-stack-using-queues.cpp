class MyStack {
    queue<int> qu;
    int size;
    int top1;
public:
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        qu.push(x);
        top1=x;
        size++;
    }
    
    int pop() {
        int ele;
        for(int i=0; i<size-1; i++)
        {
            qu.push(qu.front());
            top1=qu.front();
            qu.pop();
        }
        ele=qu.front();
        qu.pop();
        size--;
        return ele;
    }
    
    int top() {
        return top1;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */