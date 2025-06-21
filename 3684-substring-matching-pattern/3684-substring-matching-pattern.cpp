class Solution {
public:
    bool hasMatch(string s, string p) {
        int id;
        for (int i=0; i!=p.size(); i++)
        {
            if (p[i] == '*')
            {
                id = i;
                break;
            }
        }
        string a = p.substr(0, id);
        string b = p.substr(id+1);
        int l = 0;
        if (id != 0) l = s.find(a);
        if (l == string::npos) return 0;
        int r = s.rfind(b);
        if (r == string::npos) return 0;
        if (l + id <= r) return 1;
        else return 0;
    }
};