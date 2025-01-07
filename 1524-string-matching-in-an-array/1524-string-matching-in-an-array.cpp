class Solution {
public:
    vector<string> stringMatching(vector<string>& s) {
        vector<string> ans;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j!=s.size(); j++)
            {
                if (i!=j)
                {
                    if (s[j].find(s[i])!=std::string::npos)
                    {
                        ans.push_back(s[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};