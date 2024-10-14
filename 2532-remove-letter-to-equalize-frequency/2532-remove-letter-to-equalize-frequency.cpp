class Solution {
public:
    bool equalFrequency(string s) {
        unordered_map<int, int> m;
        for (int i=0; i!=s.size(); i++)
        {
            m[s[i]-'a']++;
        }
        if (m.size()==1) return 1;
        for (int i=0; i!=s.size(); i++)
        {
            m[s[i]-'a']--;
            if (m[s[i]-'a']!=0)
            {
                bool isit=1;
                for (auto j=m.begin(); j!=m.end(); j++)
                {
                    if (j->second!=m[s[i]-'a'])
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) return 1;
            }
            else
            {
                m.erase(s[i]-'a');
                int t;
                for (auto j=m.begin(); j!=m.end(); j++)
                {
                    t=j->second;
                    break;
                }
                bool isit=1;
                for (auto j=m.begin(); j!=m.end(); j++)
                {
                    if (j->second!=t)
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) return 1;
            }
            m[s[i]-'a']++;
        }
        return 0;
    }
};