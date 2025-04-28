class Solution {
public:
    vector<string> fullJustify(vector<string>& s, int k) {
        vector<string> ans;
        vector<string> next;
        int l = s[0].size();
         next.push_back(s[0]);
        for (int i=1; i!=s.size(); i++)
        {
            int t = s[i].size();
            if (l+t+1 <= k)
            {
                next.push_back(s[i]);
                l += t+1;
            }
            else
            {
                string add;
                int d = next.size() - 1; // число разделителей
                if (d == 0)
                {
                    add += next[0];
                    while (add.size() < k) add += ' ';
                }
                else
                {
                    int extra = k - l; // число лишних пробелов
                    int count = extra % d;
                    extra /= d;
                    for (int j=0; j!=next.size(); j++)
                    {
                        add += next[j];
                        if (j+1 < next.size())
                        {
                            add += ' ';
                            for (int a=0; a<extra; a++) add += ' ';
                            if (j < count) add += ' ';
                        }
                    }
                }
                ans.push_back(add);
                next.clear();
                l = 0;
                l += t;
                next.push_back(s[i]);
            }
        }
        if (next.size() > 0)
        {
            string add;
            for (int j=0; j!=next.size(); j++)
            {
                add += next[j];
                if (j+1 < next.size())
                {
                    add += ' ';
                }
            }
            while (add.size() < k) add += ' ';
            ans.push_back(add);
        }
        return ans;
    }
};