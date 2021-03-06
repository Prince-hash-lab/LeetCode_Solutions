class MinStack {
    stack<pair<int,int>> st;
    int mini;
public:
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty() or val<st.top().second) 
        {
            st.push({val,val});
            return ;
        }
        st.push({val, st.top().second});
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */