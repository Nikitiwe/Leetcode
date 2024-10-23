class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i=0; i!=s.size(); i++) m[s[i]]++;
        string ans;
        while (m.size()>0)
        {
            int ma=0;
            for (auto i=m.begin(); i!=m.end(); i++)
            {
                ma=max(ma, i->second);
            }
            for (auto i=m.begin(); i!=m.end(); i++)
            {
                if (i->second==ma)
                {
                    int t=i->second;
                    char c=i->first;
                    while (t>0)
                    {
                        ans+=c;
                        t--;
                    }
                    m.erase(c);
                    break;
                }
            }
        }
        return ans;
    }
};