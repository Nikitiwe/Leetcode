class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        vector<int> arr(1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%2==0) arr[arr.size()-1]++;
            else arr.push_back(0);
        }
        for (int i=0; i+k<arr.size(); i++)
        {
            ans+=(arr[i]+1)*(arr[i+k]+1);
        }
        return ans;
    }
};