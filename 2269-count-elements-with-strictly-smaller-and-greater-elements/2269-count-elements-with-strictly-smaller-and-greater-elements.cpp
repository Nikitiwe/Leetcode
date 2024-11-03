class Solution {
public:
    int countElements(vector<int>& nums) {
        int mi=*min_element(nums.begin(), nums.end()), ma=*max_element(nums.begin(), nums.end()), ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (mi<nums[i]&&nums[i]<ma) ans++;
        }
        return ans;
    }
};