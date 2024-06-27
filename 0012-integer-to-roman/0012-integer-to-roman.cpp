class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int k=1, t;
        while(num-k*1000>=0) {ans=ans+"M"; k++;}
        t=num%1000;
        k=t/100;
        if (k==9) ans=ans+"CM";
        else if (k==8) ans=ans+"DCCC";
        else if (k==7) ans=ans+"DCC";
        else if (k==6) ans=ans+"DC";
        else if (k==5) ans=ans+"D";
        else if (k==4) ans=ans+"CD";
        else if (k==3) ans=ans+"CCC";
        else if (k==2) ans=ans+"CC";
        else if (k==1) ans=ans+"C";
        t=t%100;
        k=t/10;
        if (k==9) ans=ans+"XC";
        else if (k==8) ans=ans+"LXXX";
        else if (k==7) ans=ans+"LXX";
        else if (k==6) ans=ans+"LX";
        else if (k==5) ans=ans+"L";
        else if (k==4) ans=ans+"XL";
        else if (k==3) ans=ans+"XXX";
        else if (k==2) ans=ans+"XX";
        else if (k==1) ans=ans+"X";
        t=t%10;
        if (t==9) ans=ans+"IX";
        else if (t==8) ans=ans+"VIII";
        else if (t==7) ans=ans+"VII";
        else if (t==6) ans=ans+"VI";
        else if (t==5) ans=ans+"V";
        else if (t==4) ans=ans+"IV";
        else if (t==3) ans=ans+"III";
        else if (t==2) ans=ans+"II";
        else if (t==1) ans=ans+"I";
        return ans;
    }
};