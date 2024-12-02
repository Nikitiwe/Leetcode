class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        if (num.size()<3) return {};
        vector<long> ans;
        int l=0;
        long a=0, b=0;
        for (int i=1; i<=10; i++)
        {
            ans.clear();
            l=0;
            a=0;
            while (l<num.size()&&l<i)
            {
                a*=10;
                a+=num[l]-'0';
                l++;
            }
            ans.push_back(a);
            for (int j=1; j<=10; j++)
            {
                vector<long> anss=ans;
                l=i;
                b=0;
                while (l<num.size()&&l<i+j)
                {
                    b*=10;
                    b+=num[l]-'0';
                    l++;
                }
                anss.push_back(b);
                long c=0;
                bool isit=0;
                while (l<num.size())
                {
                    c=0;
                    while (l<num.size())
                    {
                        c*=10;
                        c+=num[l]-'0';
                        l++;
                        if (c>=anss[anss.size()-1]+anss[anss.size()-2])
                        {
                            break;
                        }
                    }
                    if (c==anss[anss.size()-1]+anss[anss.size()-2])
                    {
                        anss.push_back(c);
                        isit=1;
                        continue;
                    }
                    else if (c>anss[anss.size()-1]+anss[anss.size()-2])
                    {
                        isit=0;
                        break;
                    }
                    else isit=0;
                }
                if (isit==1&&anss.size()>2&&l==num.size())
                {
                    bool is=1;
                    int d=0;
                    for (int x=0; x!=anss.size(); x++)
                    {
                        d+=to_string(anss[x]).size();
                        if (anss[x]>9&&to_string(anss[x])[0]=='0')
                        {
                            is=0;
                        }
                    }
                    if (is==1&&d==num.size())
                    {
                        vector<int> ansss;
                        for (int x=0; x!=anss.size(); x++)
                        {
                            if (anss[x]<=2147483647) ansss.push_back((int)anss[x]);
                        }
                        if (ansss.size()==anss.size()) return ansss;
                    }
                }
            }
        }
        return {};
    }
};