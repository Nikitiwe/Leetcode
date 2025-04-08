class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i=0; i!=arr.size(); i++)
        {
            int add = 0;
            for (int j=i; j<arr.size(); j++)
            {
                add += arr[j];
                if ((j-i)%2 == 0) ans += add;
            }
        }
        return ans;
    }
};