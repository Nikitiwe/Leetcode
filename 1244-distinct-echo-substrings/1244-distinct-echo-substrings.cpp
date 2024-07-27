class Solution {
public:
    int distinctEchoSubstrings(string s) {
        unordered_set<string> arr;
        int l, f;
        string a;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=i+1; j<s.size()&&j<(i+s.size())/2+1; j++)
            {
                l=0;
                f=1;
                a="";
                while (i+l<j&&j+l<s.size())
                {
                    if (s[i+l]!=s[j+l]) {f=0; break;}
                    a+=s[i+l];
                    l++;
                }
                if (f==1&&arr.count(a)==0) arr.insert(a);
            }
        }
        return arr.size();
    }
};