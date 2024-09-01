class Solution {
public:
    int minimumOperations(string num) {
        if (num=="0") return 0;
        if (num.size()==1) return 1;
        int a00=0, a25=0, a50=0, t=0, a0=0;
        for (int i=num.size()-1; i>=0; i--)
        {
            if (t==0&&num[i]=='0') t++;
            else if (t==0) a00++;
            else if (t==1&&num[i]=='0') t++;
            else if (t==1) a00++;
            else break;
        }
        if (t!=2) a00=num.size();
        t=0;
        for (int i=num.size()-1; i>=0; i--)
        {
            if (t==0&&num[i]=='5') t++;
            else if (t==0) a25++;
            else if (t==1&&(num[i]=='2'||num[i]=='7')) t++;
            else if (t==1) a25++;
            else break;
        }
        if (t!=2) a25=num.size();
        t=0;
        for (int i=num.size()-1; i>=0; i--)
        {
            if (t==0&&num[i]=='0') t++;
            else if (t==0) a50++;
            else if (t==1&&num[i]=='5') t++;
            else if (t==1) a50++;
            else break;
        }
        if (t!=2) a50=num.size();
        t=0;
        for (int i=num.size()-1; i>=0; i--)
        {
            if (num[i]=='0') t++;
            else a0++;
        }
        if (t>1) a0=num.size()-1;
        return min({a00, a25, a50, a0});
    }
};