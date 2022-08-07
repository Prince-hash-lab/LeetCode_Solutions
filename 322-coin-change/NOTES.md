if(amt==0) return 0;
if(i==n) return -1;
int num=cc(cn, amt, i+1, n);
if(amt>=cn[i])
{
int num2=cc(cn, amt-cn[i], i, n);
if(num==-1 and num2==-1) return -1;
else if(num!=-1 and num2!=num2)
}
return num;
}
to know its recusive appraoch and memoiazed solution
top down:->
int coinChange(vector<int>& cn, int amt) {
int n=cn.size();
vector<vector<int>> v(n+1, vector<int> (amt+1, 0));
for(int i=0; i<amt+1; i++)
v[0][i]=INT_MAX-1;
for(int i=1; i<amt+1; i++)
{
if(i%cn[0]) v[1][i]=INT_MAX-1;
else v[1][i]=i/cn[0];
}
for(int i=2; i<n+1; i++)
{
for(int j=1; j<amt+1; j++)
{
v[i][j]=v[i-1][j];
if(cn[i-1]<=j)
v[i][j]=min(v[i][j], 1+v[i-1][j-cn[i-1]]);
}
}
for(int i=0; i<n+1; i++)
{
cout<<" n= "<<i<<" ";
for(int j=0; j<amt+1; j++)
{
cout<<v[i][j]<<" ";
}
cout<<endl;
}
if(v[n][amt]==INT_MAX-1) return -1;
return v[n][amt];
not wokring properly