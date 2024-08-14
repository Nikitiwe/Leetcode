class Solution {
public:
    string solveEquation(string equation) {
        int k=0, t=0;
        int i=0;
        bool isit=0;
        char sign='+';
        long temp=0;
        while (i<equation.size())
        {
            if (equation[i]=='=') {isit=1; sign='+'; i++;}
            else if (equation[i]=='+') {sign='+'; i++;}
            else if (equation[i]=='-') {sign='-'; i++;}
            else if (equation[i]=='x')
            {
                if (isit==0&&sign=='+') {k++;}
                else if (isit==0&&sign=='-') {k--;}
                else if (isit==1&&sign=='+') {k--;}
                else {k++;}
                i++;
            }
            else
            {
                while (equation[i]>='0'&&equation[i]<='9')
                {
                    temp=temp*10+equation[i]-'0';
                    i++;
                }
                if (i<equation.size()&&equation[i]=='x')
                {
                    if (isit==0&&sign=='+') {k+=temp;}
                    else if (isit==0&&sign=='-') {k-=temp;}
                    else if (isit==1&&sign=='+') {k-=temp;}
                    else {k+=temp;}
                    i++;
                }
                else
                {
                    if (isit==0&&sign=='+') {t+=temp;}
                    else if (isit==0&&sign=='-') {t-=temp;}
                    else if (isit==1&&sign=='+') {t-=temp;}
                    else {t+=temp;}
                }
                temp=0;
                //i++;
            }
        }
        //return "k="+to_string(k)+" "+to_string(isit);
        if (k==0&&t==0) return "Infinite solutions";
        else if (k==0&&t!=0) return "No solution";
        else return "x="+to_string(-t/k);
    }
};