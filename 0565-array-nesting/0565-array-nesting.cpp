class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=1, c=1, id, t;
        for (int i=0; i!=nums.size(); i++)
        {
            c=1;
            id=i;
            while (1)
            {
                if (nums[id]!=-1)
                {
                    t=id;
                    id=nums[id];
                    nums[t]=-1;
                    if (id==i) break;
                    c++;
                }
                else
                {
                    //c++;
                    break;
                }
            }
            ans=max(ans, c);
            if (ans>nums.size()/2) return ans;
        }
        return ans;
    }
};