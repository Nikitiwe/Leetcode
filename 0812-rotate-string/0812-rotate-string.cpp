class Solution {
public:
    bool rotateString(string s, string g) {
        if (s.size()!=g.size()) return 0;
        for (int i=0; i!=s.size(); i++)
        {
            string t;
            for (int j=0; j!=s.size(); j++)
            {
                t+=s[(j+i)%s.size()];
            }
            if (t==g) return 1;
        }        
        return 0;
    }
};