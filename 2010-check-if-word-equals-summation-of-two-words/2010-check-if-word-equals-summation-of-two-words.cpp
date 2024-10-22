int ans (string x)
        {
            int a=0;
            for (int i=0; i!=x.size(); i++)
            {
                a*=10;
                a+=x[i]-'a';
            }
            return a;
        }
        
class Solution {
public:
    bool isSumEqual(string f, string s, string t) {
        if (ans(f)+ans(s)==ans(t)) return 1;
        else return 0;
    }
};