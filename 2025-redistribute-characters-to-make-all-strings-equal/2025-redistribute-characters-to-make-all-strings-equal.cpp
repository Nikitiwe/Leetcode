class Solution {
public:
    bool makeEqual(vector<string>& w) {
        unordered_map<char, int> m;
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=0; j!=w[i].size(); j++) m[w[i][j]]++;
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second%w.size()!=0) return 0;
        }
        return 1;
    }
};