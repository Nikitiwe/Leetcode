class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        vector<int> arr(k, 0);
        for (int i=0; i!=nums.size(); i++) arr[(nums[i]%k+k)%k]++;
        for (int i=1; i<=arr.size()/2; i++) if (arr[i]!=arr[arr.size()-i]) return 0;
        if (arr[0]%2!=0) return 0;
        return 1;
    }
};