struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isroot = 0;
};

class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        TrieNode* root = new TrieNode();
        for (int j=0; j!=d.size(); j++)
        {
            TrieNode* t = root;
            for (int i=0; i!=d[j].size(); i++)
            {
                if ( (t->children).count(d[j][i]) == 0)
                {
                    TrieNode* n = new TrieNode();
                    (t->children)[d[j][i]] = n;
                    t = n;
                }
                else t = (t->children)[d[j][i]];
            }
            t->isroot = 1;
        }
        s += " ";
        string ans = "", t = "";
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] != ' ') t +=s[i];
            else
            {
                if (ans.size() > 0 && ans.back() != ' ') ans += ' ';
                TrieNode* tt = root;
                for (int j=0; j!=t.size(); j++)
                {
                    if ( (tt->children).count(t[j]) == 1)
                    {
                        tt = (tt->children)[t[j]];
                        if (tt->isroot == 1)
                        {
                            t = t.substr(0, j+1);
                            break;
                        }
                    }
                    else break;
                }
                ans += t;
                t = "";
            }
        }
        return ans;
    }
};