class Solution {
public:
    string fractionAddition(string expression) {
        long long a=0, b=0, c=0, d=0, znak=1, up=1;
        for (int i=0; i!=expression.size(); i++)
        {
            if (expression[i]=='-') {znak=-1; up=1; c=0;}
            else if (expression[i]=='+') {znak=1; up=1; c=0;}
            else if (expression[i]=='/') {up=0; d=0;}
            else
            {
                if (up==1) c=c*10+expression[i]-'0';
                else
                {
                    d=d*10+expression[i]-'0';
                    if (i+1==expression.size()||expression[i+1]=='-'||expression[i+1]=='+')
                    {
                        if (b==0)
                        {
                            a=c*znak;
                            b=d;
                        }
                        else
                        {
                            a=a*d+b*c*znak;
                            b*=d;
                        }
                    }
                }
            }
        }
        if (a==0) return "0/1";
        up=gcd(a, b);
        a/=up;
        b/=up;
        return to_string(a)+'/'+to_string(b);
    }
};