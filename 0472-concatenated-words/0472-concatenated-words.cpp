class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& s) {
        unordered_set<string> m(s.begin(), s.end());
        vector<string> ans;
        for (int i=0; i!=s.size(); i++)
        {
            vector<bool> arr(s[i].size()+1, 0);
            arr[0]=1;
            for (int k=0; k<s[i].size(); k++)
            {
                if (arr[k]==1)
                {
                    string t;
                    for (int j=k; j<s[i].size(); j++)
                    {
                        t+=s[i][j];
                        if (t.size()<s[i].size()&&m.count(t)>0) arr[j+1]=1;
                    }
                }
            }
            if (arr.back()==1) ans.push_back(s[i]);
        }
        return ans;
    }
};