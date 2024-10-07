class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) {
        if (n==1) return 1;
        unordered_map<int, int> m;
        for (int i=0; i!=t.size(); i++)
        {
            m[t[i][0]]=-2000;
            m[t[i][1]]++;
        }
        /*for (int i=0; i!=t.size(); i++)
        {
            m.erase(t[i][0]);
        }*/
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==n-1) return i->first;
        }
        return -1;
    }
};