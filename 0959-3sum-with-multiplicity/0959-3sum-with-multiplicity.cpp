class Solution {
public:
    int threeSumMulti(vector<int>& nums, int t) {
        long long ans = 0;
        vector<int> arr(101, 0);
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++) m[t - i] = arr[i];
        for (int i=0; i!=arr.size(); i++)
        {
            if (i < t-i-i) ans += arr[i]*(arr[i]-1)/2*m[i+i];
            for (int j=i+1; j<arr.size(); j++)
            {
                if (m.count(i+j) != 0)
                {
                    if (j < t-i-j) ans += arr[i]*arr[j]*m[i+j];
                    else if (j == t-i-j) ans += arr[i]*arr[j]*(arr[j]-1)/2;
                }
            }
        }
        if (t%3 == 0) ans += (long long)m[2*t/3]*(m[2*t/3]-1)*(m[2*t/3]-2)/6;
        return ans%1000000007;
    }
};