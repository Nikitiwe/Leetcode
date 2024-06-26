class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<vector<int>> a;
        vector<int> ans;
        int count=0, max;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==x)
            {
                count++;
                a.push_back({i, count});
            }
        }
        if (a.size()!=0) max=a[count-1][1];
        for (int i=0; i!=queries.size(); i++)
        {
            count=-1;
            for (int j=0; j!=a.size(); j++)
                {
                    if (queries[i]>max) break;
                    else if(a[j][1]==queries[i])
                    {
                        count=j;
                        ans.push_back(a[j][0]);
                        break;
                    }
                }
            if (count==-1) ans.push_back(-1);
        }
        return ans;
    }
};