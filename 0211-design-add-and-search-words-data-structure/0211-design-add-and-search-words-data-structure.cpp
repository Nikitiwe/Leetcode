class WordDictionary {
private:
    unordered_set<string> m;

public:
    WordDictionary() {
        m.clear();
    }
    
    void addWord(string word) {
        m.insert(word);
    }
    
    bool search(string s) {
        int t=0, id1=-1, id2=-1;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='.')
            {
                if (id1==-1) id1=i;
                else id2=i;
                t++;
            }
        }
        if (t==0)
        {
            if (m.count(s)==1) return 1;
            else return 0;
        }
        else if (t==1)
        {
            for (int i=0; i!=26; i++)
            {
                s[id1]='a'+i;
                if (m.count(s)==1) return 1;
            }
            return 0;
        }
        else
        {
            for (int i=0; i!=26; i++)
            {
                s[id1]='a'+i;
                for (int j=0; j!=26; j++)
                {
                    s[id2]='a'+j;
                    if (m.count(s)==1) return 1;
                }
            }
            return 0;
        }
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */