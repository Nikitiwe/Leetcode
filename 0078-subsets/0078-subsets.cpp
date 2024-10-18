class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<unordered_set<int>> m;
        int t=nums.size(), s=2;
        if (t>1)
        {
            while (t>1)
            {
                s*=2;
                t--;
            }
        }
        for (int i=0; i<s; i++)
        {
            t=i;
            unordered_set<int> n;
            for (int j=0; j!=nums.size(); j++)
            {
                if (t%2==1) n.insert(nums[j]);
                t/=2;
            }
            bool isit=1;
            if (m.size()>0) for (int j=0; j!=m.size(); j++)
            {
                if (m[j]==n)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1)
            {
                m.push_back(n);
            }
        }
        vector<vector<int>> ans(m.size(), vector<int> ());
        for (int i=0; i!=m.size(); i++)
        {
            if (m[i].size()>0) for (auto j=m[i].begin(); j!=m[i].end(); j++)
            {
                ans[i].push_back(*j);
            }
            else
            {
                //ans[i].push_back({});
            }
        }
        return ans;
    }
};