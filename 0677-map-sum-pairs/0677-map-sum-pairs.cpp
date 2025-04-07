struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int val = 0;
    int sum = 0;
};

class MapSum {
public:
    TrieNode* root;

    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string s, int k) {
        TrieNode* t = root;
        for (int i=0; i!=s.size(); i++)
        {
            if ( (t->children).count(s[i]) == 0)
            {
                TrieNode* n = new TrieNode();
                (t->children)[s[i]] = n;
                t = n;
            }
            else t = (t->children)[s[i]];
        }
        int diff = k;
        if (t->val == 0) t->val = k;
        else
        {
            diff = k - t->val;
            t->val = k;
        }
        t->sum += diff;

        t = root;
        for (int i=0; i<s.size(); i++)
        {
            t->sum += diff;
            t = (t->children)[s[i]];
        }
        return;
    }
    
    int sum(string s) {
        TrieNode* t = root;
        for (int i=0; i!=s.size(); i++)
        {
            if ( (t->children).count(s[i]) == 1)
            {
                t = (t->children)[s[i]];
            }
            else return 0;
        }
        return t->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */