class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> m;
        int a, sum=0, n=nums.size();
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
            if (m[nums[i]]==2) a=nums[i];
        }
        return {a, -sum+a+n*(n+1)/2};
    }
};