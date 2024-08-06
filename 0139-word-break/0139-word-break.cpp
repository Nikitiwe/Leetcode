class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> arr(s.size(), 0);
        int l=0;
        for (int i=0; i<s.size(); i++)
        {
            if (i==0||arr[i-1]==1)
            {
                for (int j=0; j!=wordDict.size(); j++)
                {
                    l=0;
                    while (i+l<s.size()&&l<wordDict[j].size()&&s[i+l]==wordDict[j][l]) l++;
                    if (l==wordDict[j].size()) arr[i+l-1]=1;
                }
            }
        }
        return arr[s.size()-1];
    }
};