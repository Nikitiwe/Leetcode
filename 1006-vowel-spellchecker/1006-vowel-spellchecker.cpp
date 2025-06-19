class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& q) {
        unordered_set<string> s; // как надо, нижний регистр, без гласных в нижнем
        unordered_map<string, string> l, w;
        for (int i=0; i!=wordlist.size(); i++)
        {
            string &t = wordlist[i];
            s.insert(t);
            string tt;
            for (int j=0; j!=t.size(); j++) tt += tolower(t[j]);
            if (l.count(tt) == 0) l[tt] = t;
            string ttt;
            for (int j=0; j!=t.size(); j++)
            {
                if (tolower(t[j]) == 'a' || tolower(t[j]) == 'i' || tolower(t[j]) == 'e' || tolower(t[j]) == 'o' || tolower(t[j]) == 'u') ttt += '*';
                else ttt += tolower(t[j]);
            }
            if (w.count(ttt) == 0) w[ttt] = t;
        }
        vector<string> ans(q.size(), "");
        for (int i=0; i!=q.size(); i++)
        {
            if (s.count(q[i]) == 1) ans[i] = q[i];
            else
            {
                string tt;
                for (int j=0; j!=q[i].size(); j++) tt += tolower(q[i][j]);
                if (l.count(tt) == 1) ans[i] = l[tt];
                else
                {
                    string ttt;
                    for (int j=0; j!=q[i].size(); j++)
                    {
                        if (tolower(q[i][j]) == 'a' || tolower(q[i][j]) == 'i' || tolower(q[i][j]) == 'e' || tolower(q[i][j]) == 'o' || tolower(q[i][j]) == 'u') ttt += '*';
                        else ttt += tolower(q[i][j]);
                    }
                    if (w.count(ttt) == 1) ans[i] = w[ttt];
                }
            }
        }
        return ans;
    }
};