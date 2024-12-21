class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int k=1, t;
        while(num-k*1000>=0) {ans+="M"; k++;}
        t=num%1000;
        k=t/100;
        if (k==9) ans+="CM";
        else if (k==8) ans+="DCCC";
        else if (k==7) ans+="DCC";
        else if (k==6) ans+="DC";
        else if (k==5) ans+="D";
        else if (k==4) ans+="CD";
        else if (k==3) ans+="CCC";
        else if (k==2) ans+="CC";
        else if (k==1) ans+="C";
        t=t%100;
        k=t/10;
        if (k==9) ans+="XC";
        else if (k==8) ans+="LXXX";
        else if (k==7) ans+="LXX";
        else if (k==6) ans+="LX";
        else if (k==5) ans+="L";
        else if (k==4) ans+="XL";
        else if (k==3) ans+="XXX";
        else if (k==2) ans+="XX";
        else if (k==1) ans+="X";
        t=t%10;
        if (t==9) ans+="IX";
        else if (t==8) ans+="VIII";
        else if (t==7) ans+="VII";
        else if (t==6) ans+="VI";
        else if (t==5) ans+="V";
        else if (t==4) ans+="IV";
        else if (t==3) ans+="III";
        else if (t==2) ans+="II";
        else if (t==1) ans+="I";
        return ans;
    }
};