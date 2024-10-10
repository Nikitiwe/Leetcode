class Solution {
public:
    bool isSubstringPresent(string s) {
        for (int i=0; i!=26; i++)
        {
            for (int j=0; j!=26; j++)
            {
                string l, r;
                l+='a'+i; l+='a'+j;
                r+='a'+j; r+='a'+i;
                if (s.find(l)!=-1&&s.find(r)!=-1) return 1;
            }
        }
        return 0;
    }
};