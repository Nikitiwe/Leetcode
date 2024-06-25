class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<int> temp;
        vector<bool> ans;
        for (int i=0; i!=l.size(); i++)
        {
            temp.clear();
            for (int j=l[i]; j<=r[i]; j++) temp.push_back(nums[j]);
            sort(temp.begin(), temp.end());
            if (temp.size()<=2) ans.push_back(1);
            else
            {
                int isit=1;
                for (int k=0; k!=temp.size()-2; k++)
                {
                    if (temp[k]-temp[k+1]!=temp[k+1]-temp[k+2]) {isit=0; break;}
                }
                if (isit==1) ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans;
    }
};