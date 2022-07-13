class MedianFinder {
    priority_queue<int> s;
    priority_queue<int ,vector<int>,  greater<int>>  g;
    int n;
    double med;
public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
       if(n==0){ s.push(num); med=num; }
       else if(n==1)
       {
           int ele=s.top();
           if(ele<=num) g.push(num);
           else 
           {    s.pop();
               g.push(ele);
               s.push(num);
           }
           
       }
        else if(n%2==0)
        {
             int ele1=s.top(), ele2=g.top();
               if(num<ele2) s.push(num);
               else 
               {    g.pop();
                   s.push(ele2);
                   g.push(num);
               }
            
        }
        else
        {
            int ele1=s.top(), ele2=g.top();
               if(num>ele1) g.push(num);
               else 
               {    s.pop();
                   g.push(ele1);
                   s.push(num);
               }
        }
        
        n++;
    }
    
    double findMedian() {
        if(n==1) return med;
        if(n%2==0) med=(double(s.top())+double(g.top()))/2;
        else med=s.top();
        return med;
    }
};
const auto fast = []() 
{std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */