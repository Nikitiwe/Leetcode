class MagicDictionary {
private:
    vector<string> m;

public:
    MagicDictionary() {
        m.clear();
    }
    
    void buildDict(vector<string> d) {
        m=d;
    }
    
    bool search(string s) {
        for (int i=0; i!=m.size(); i++)
        {
            if (s.size()!=m[i].size()) continue;
            else
            {
                int t=0;
                for (int j=0; j!=s.size(); j++)
                {
                    if (s[j]==m[i][j]) t++;
                }
                if (t==s.size()-1) return 1;
            }
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */