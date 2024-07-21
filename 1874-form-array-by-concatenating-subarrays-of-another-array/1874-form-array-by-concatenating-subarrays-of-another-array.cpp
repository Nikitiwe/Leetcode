class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int l=0, temp=0, f;
        while (l<nums.size())
        {
            if (nums[l]==groups[temp][0])
            {
                f=1;
                for (int i=0; i!=groups[temp].size(); i++)
                {
                    if (i+l<nums.size()&&nums[l+i]==groups[temp][0+i]) f=1;
                    else {f=0; break;}
                }
            }
            if (f==1)
            {
                l+=(groups[temp].size());
                temp++;
                f=0;
                if (temp==groups.size()) return 1;
            }
            else l++;
        }
        return 0;
    }
};