class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        vector<int> arr(n+1, 0);
        for (int i=1; i<=n; i++) arr[i]=i*i;
        for (int i=5; i<=n; i++)
        {
            int l=0;
            for (int j=i-1; j>1; j--)
            {
                while (arr[j]+arr[l]<arr[i]) l++;
                if (arr[j]+arr[l]==arr[i]) ans++;
            }
        }
        return ans;
    }
};