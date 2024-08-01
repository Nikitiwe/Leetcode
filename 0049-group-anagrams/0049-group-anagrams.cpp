class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> ord=strs;
        for (int i=0; i!=ord.size(); i++)
        {
            sort(ord[i].begin(), ord[i].end());
        }
        vector<vector<string>> ans, ansord;
        vector<bool> isit(strs.size(), 1);
        vector<string> row;
        ans.push_back(row);
        ansord.push_back(row);
        ans[0].push_back(strs[0]);
        ansord[0].push_back(ord[0]);
        isit[0]=0;
        for (int i=0; i<strs.size(); i++)
        {
            for (int j=i; j!=strs.size(); j++)
            {
                if (isit[j]==1)
                {
                    if (ansord[i][0]==ord[j])
                    {
                        isit[j]=0;
                        ans[i].push_back(strs[j]);
                        ansord[i].push_back(ord[j]);
                    }
                }
            }
            for (int j=i; j!=strs.size(); j++)
            {
                if (isit[j]==1)
                {
                    isit[j]=0;
                    ans.push_back(row);
                    ans[i+1].push_back(strs[j]);
                    ansord.push_back(row);
                    ansord[i+1].push_back(ord[j]);
                    break;
                }
            }
        }
        return ans;
    }
};