class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<long long> arr(60, 0);
        long long ans=0;
        for (int i=0; i!=time.size(); i++)
        {
            arr[time[i]%60]++;
        }
        for (int i=1; i!=30; i++)
        {
            ans+=arr[i]*arr[60-i];
        }
        ans+=arr[0]*(arr[0]-1)/2;
        ans+=arr[30]*(arr[30]-1)/2;
        return ans;
    }
};