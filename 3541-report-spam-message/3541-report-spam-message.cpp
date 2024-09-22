class Solution {
public:
    bool reportSpam(vector<string>& m, vector<string>& b) {
        unordered_set<string> a;
        for (int i=0; i!=b.size(); i++)
        {
            a.insert(b[i]);
        }
        int c=0;
        for (int i=0; i!=m.size(); i++)
        {
            if (a.count(m[i])>0) c++;
        }
        if (c>1) return 1;
        else return 0;
    }
};