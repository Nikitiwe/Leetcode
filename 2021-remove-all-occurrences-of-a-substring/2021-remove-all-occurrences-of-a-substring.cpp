class Solution {
public:
    string removeOccurrences(string s, string w) {
        bool isit = 1;
        while (isit == 1)
        {
            isit = 0;
            string t;
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i] == w[0])
                {
                    bool isf = 1;
                    for (int j = 0; j!=w.size(); j++)
                    {
                        if (i+j < s.size() && s[i+j] == w[j]) continue;
                        else
                        {
                            isf = 0;
                            break;
                        }
                    }
                    if (isf == 1)
                    {
                        for (int j = i + w.size(); j < s.size(); j++) t += s[j];
                        isit = 1;
                        break;
                    }
                    else t += s[i];
                }
                else t += s[i];
            }
            s = t;
        }
        return s;
    }
};