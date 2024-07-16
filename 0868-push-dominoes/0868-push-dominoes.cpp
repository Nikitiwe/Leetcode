class Solution {
public:
    string pushDominoes(string d) {
        string n(d.size(), '.'), m(d.size(), '.');
        int count=0, temp;
        while (d.size()>1)
        {
            temp=count;
            if (d[0]=='.'&&d[1]=='L') {n[0]='L'; count++;}
            else n[0]=d[0];
            if (d.size()>2) for (int j=1; j<=d.size()-2; j++)
            {
                if (d[j]=='.'&&d[j-1]=='R'&&d[j+1]!='L') {n[j]='R'; count++;}
                else if (d[j]=='.'&&d[j+1]=='L'&&d[j-1]!='R') {n[j]='L'; count++;}
                else n[j]=d[j];
            }
            if (d[d.size()-1]=='.'&&d[d.size()-2]=='R') {n[d.size()-1]='R'; count++;}
            else n[d.size()-1]=d[d.size()-1];
            if (temp==count) break;
            d=n;
            n=m;
        }
        return d;

    }
};