class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n<=1) return n;
        vector<int> arr(n+1, 0);
        arr[1]=1;
        int ans=0;
        for (int i=2; i<arr.size(); i++)
        {
            if (i%2==0) arr[i]=arr[i/2];
            else arr[i]=arr[i/2]+arr[i/2+1];
            ans=max(ans, arr[i]);
        }
        return ans;        
    }
};