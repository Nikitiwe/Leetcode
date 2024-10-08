class Solution {
public:
    int countCompleteDayPairs(vector<int>& h) {
        vector<int> arr(24, 0);
        for (int i=0; i!=h.size(); i++)
        {
            arr[h[i]%24]++;
        }
        int ans=0;
        for (int i=1; i<=11; i++)
        {
            ans+=arr[i]*arr[24-i];
        }
        ans+=arr[0]*(arr[0]-1)/2;
        ans+=arr[12]*(arr[12]-1)/2;
        return ans;
    }
};