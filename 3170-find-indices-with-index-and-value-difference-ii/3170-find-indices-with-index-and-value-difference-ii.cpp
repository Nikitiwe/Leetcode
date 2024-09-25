class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        vector<int> ma(nums.size(), -1), mi(nums.size(), -1);
        for (int i=0; i<=id; i++)
        {
            if (i+id<nums.size())
            {
                ma[i+id]=nums[i];
                mi[i+id]=nums[i];
            }
            else break;
        }
        for (int i=id; i<nums.size(); i++)
        {
            if (i+id<nums.size())
            {
                ma[i+id]=nums[i];
                mi[i+id]=nums[i];
            }

            if (i>0) ma[i]=max(ma[i], ma[i-1]);
            if (i>0&&mi[i-1]>-1) mi[i]=min(mi[i], mi[i-1]);

            if (ma[i]>-1&&ma[i]-nums[i]>=vd) return {i, (int)(find(nums.begin(), nums.end(), ma[i])-nums.begin())};
            if (mi[i]>-1&&nums[i]-mi[i]>=vd) return {i, (int)(find(nums.begin(), nums.end(), mi[i])-nums.begin())};
        }
        return {-1, -1};
    }
};