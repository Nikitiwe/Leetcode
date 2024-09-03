class Solution {
public:
    bool canTransform(string a, string b) {
        int cl=0, cr=0;
        vector<int> a1, b1;
        for (int i=0; i!=a.size(); i++)
        {
            if (a[i]=='R')
            {
                if (cl==0) cr++;
                else
                {
                    a1.push_back(-cl);
                    cl=0;
                    cr++;
                }
            }
            else if (a[i]=='L')
            {
                if (cr==0) cl++;
                else
                {
                    a1.push_back(cr);
                    cr=0;
                    cl++;
                }
            }
        }
        if (cr>0) a1.push_back(cr);
        else if (cl>0) a1.push_back(-cl);

        cl=0; cr=0;
        for (int i=0; i!=b.size(); i++)
        {
            if (b[i]=='R')
            {
                if (cl==0) cr++;
                else
                {
                    b1.push_back(-cl);
                    cl=0;
                    cr++;
                }
            }
            else if (b[i]=='L')
            {
                if (cr==0) cl++;
                else
                {
                    b1.push_back(cr);
                    cr=0;
                    cl++;
                }
            }
        }
        if (cr>0) b1.push_back(cr);
        else if (cl>0) b1.push_back(-cl);

        if (a1!=b1) return 0;

        int la=0, lb=0;
        while (la<a.size()&&lb<b.size())
        {
            while (la<a.size()&&a[la]==b[lb]) {la++; lb++;}
            if (la==a.size()) break;
            if (b[lb]=='L')
            {
                if (a[lb]=='R') return 0;
                else
                {
                    while (la<a.size()&&a[la]=='X') la++;
                    if (la==a.size()) return 0;
                    if (a[la]=='R') return 0;
                    if (a[la]=='L')
                    {
                        swap(a[la], a[lb]);
                    }
                }
            }
            else if (a[la]=='L') return 0;
        lb++;
        la=lb;
        }

        la=a.size()-1; lb=la;
        while (la>=0&&lb>=0)
        {
            while (la>=0&&a[la]==b[lb]) {la--; lb--;}
            if (la==-1) break;
            if (b[lb]=='R')
            {
                if (a[lb]=='L') return 0;
                else
                {
                    while (la>=0&&a[la]=='X') la--;
                    if (la==-1) return 0;
                    if (a[la]=='L') return 0;
                    if (a[la]=='R')
                    {
                        swap(a[la], a[lb]);
                    }
                }
            }
            else if (a[la]=='R') return 0;
        lb--;
        la=lb;
        }
        return 1;
    }
};