class Solution {
public:
 struct comp{
   bool operator()(vector<int>&a,vector<int>&b){
     int op1=min(-a[0],-a[0]+a[1]-b[0]);
     int op2=min(-b[0],-b[0]+b[1]-a[0]);
     if(op1!=op2)return op1<op2;
     return a[0]>b[0];
   }
 };
    bool f(long long mid,vector<vector<int>>&t){
        long long cost=mid;
        for(int i=0;i<t.size();i++){
            if(cost>=t[i][0]){
                cost+=(long long)(t[i][1])-(long long)(t[i][0]);
            }else{
                return false;
            }
        }
        return cost>=0;
    }
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n=transactions.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=transactions[i][0];
        }
        sort(transactions.begin(),transactions.end(),comp());
        long long high=sum;
        long long low=0;
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(f(mid,transactions)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
