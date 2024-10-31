class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int ans=0;
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                int p=nums[i]*nums[j];
                m[p]++;
                ans+=m[p]-1;
            }
        }
        return ans*8;
    }
};