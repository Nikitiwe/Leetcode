class Solution {
public:
    bool isPathCrossing(string s) {
        unordered_set<int> m;
        int t=0;
        m.insert(t);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='N') t+=10001;
            else if (s[i]=='S') t-=10001;
            else if (s[i]=='E') t++;
            else if (s[i]=='W') t--;
            if (m.count(t)>0) return 1;
            m.insert(t);
        }
        return 0;
    }
};