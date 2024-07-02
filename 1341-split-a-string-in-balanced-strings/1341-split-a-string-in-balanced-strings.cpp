class Solution {
public:
    int balancedStringSplit(string s) {
        int col=0, cor=0, ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='L') col++;
            else cor++;
            if (col==cor&&cor>0) {ans++; col=0; cor=0;}
        }
        return ans;
    }
};