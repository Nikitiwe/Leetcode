class Solution {
public:
    bool canChange(string start, string target) {
        int sl=0, sr=0, tl=0, tr=0;
        vector<int> s, t;
        for (int i=0; i!=start.size(); i++)
        {
            if (start[i]=='R') {s.push_back(1000000); break;}
            if (start[i]=='L') {s.push_back(2000000); break;}
        }
        for (int i=0; i!=start.size(); i++)
        {
            if (target[i]=='R') {t.push_back(1000000); break;}
            if (target[i]=='L') {t.push_back(2000000); break;}
        }
        if (t!=s) return 0;
        for (int i=0; i!=start.size(); i++)
        {
            if (start[i]=='R') {sr++; if (sl>0) s.push_back(sl); sl=0;}
            else if (start[i]=='L') {sl++; if (sr>0) s.push_back(sr); sr=0;}
            if (target[i]=='R') {tr++; if (tl>0) t.push_back(tl); tl=0;}
            else if (target[i]=='L') {tl++; if (tr>0) t.push_back(tr); tr=0;}
            if (tr>sr) return 0;
            if (tl<sl) return 0;
        }
        s.push_back(max(sl, sr));
        t.push_back(max(tl, tr));
        if (t!=s) return 0;
        return 1;
    }
};