class Solution {
public:
    int maxArea(int H, int w, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int maxi=0;
        int maxi2=0;
        int n=h.size();
        int m=v.size();
        for(int i=1;i<h.size();i++){
            maxi=max(maxi,h[i]-h[i-1]);
        }
        maxi=max(maxi,h[0]-0);
          maxi=max(maxi,H-h[n-1]);

        for(int i=1;i<v.size();i++){
            maxi2=max(maxi2,v[i]-v[i-1]);
        }
        maxi2=max(maxi2,v[0]-0);

maxi2=max(maxi2,w-v[m-1]);
// int mod=1e9+7;
// int ans=((maxi%mod)*(maxi2%mod))%mod;

//         return ans;
 long long MOD = 1e9 + 7;
        long long ans = (maxi % MOD) * (maxi2 % MOD) % MOD;
        return (int)ans;
    }
};
