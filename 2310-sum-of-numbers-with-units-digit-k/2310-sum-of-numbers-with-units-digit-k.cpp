class Solution {
public:
  int minimumNumbers(int N, int k) { 
        if(N==0) return 0; 
        for(int i=1;i<=10;i++){ 
            int res=i*k; 
            if(res%10==N%10 and res<=N){ 
                return i; 
            } 
        } 
        return -1; 
    } 
};