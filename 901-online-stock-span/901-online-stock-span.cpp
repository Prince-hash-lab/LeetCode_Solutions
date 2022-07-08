class StockSpanner {
    int i;
    stack<pair<int,int> > st;
    // vector<int> v;
public:
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        while(!st.empty() and st.top().second<=price)
                st.pop();
        
        int res=i-(st.empty()?-1:st.top().first) ;
        st.push({i, price});
       
        i++;
         // if(i==1) return 1;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */