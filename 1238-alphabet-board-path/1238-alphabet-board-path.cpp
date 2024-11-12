class Solution {
public:
    string alphabetBoardPath(string t) {
        string ans;
        int x=0, y=0;
        for (int i=0; i!=t.size(); i++)
        {
            int a=(t[i]-'a')/5, b=(t[i]-'a')%5;
            if (x==5||a!=5)
            {
                if (a>x) while (x<a) {ans+='D'; x++;}
                else while (x>a) {ans+='U'; x--;}
                if (b>y) while (y<b) {ans+='R'; y++;}
                else while (y>b) {ans+='L'; y--;}
            }
            else
            {
                if (b>y) while (y<b) {ans+='R'; y++;}
                else while (y>b) {ans+='L'; y--;}
                if (a>x) while (x<a) {ans+='D'; x++;}
                else while (x>a) {ans+='U'; x--;}
            }
            ans+='!';
        }
        return ans;
    }
};