class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        vector<long long> arr(24, 0);
        for (int i=0; i!=hours.size(); i++)
        {
            arr[hours[i]%24]++;
        }
        for (int i=1; i!=12; i++)
        {
            ans+=arr[i]*arr[24-i];
        }
        ans+=arr[0]*(arr[0]-1)/2;
        ans+=arr[12]*(arr[12]-1)/2;
        return ans;
    }
};