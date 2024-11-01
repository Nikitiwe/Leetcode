class Solution {
public:
    string baseNeg2(int n) {
        if (n==0) return "0";
        vector<int> s;
        while (n>0)
        {
            if (n%2==1)
            {
                s.push_back(1);
            }
            else s.push_back(0);
            n/=2;
        }
        s.push_back(0); s.push_back(0); s.push_back(0); s.push_back(0); s.push_back(0);
        vector<int> t(s.size(), 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (i%2==0)
            {
                t[i]+=s[i];
            }
            else
            {
                if (s[i]==1)
                {
                    t[i]+=s[i];
                    t[i+1]++;
                }
            }
        }
        for (int i=0; i<t.size()-2; i++)
        {
            if (i%2==0)
            {
                if (t[i]>=2)
                {
                    t[i+1]++;
                    t[i+2]++;
                    t[i]-=2;
                }
                else if (t[i]==-1)
                {
                    t[i]++;
                    t[i+1]++;
                }
            }
            else
            {
                if (t[i]==2)
                {
                    t[i]-=2;
                    t[i+1]--;
                }
            }
        }
        while(t.back()==0) t.pop_back();
        string ans;
        while(t.size()>0)
        {
            ans+=t.back()+'0';
            t.pop_back();
        }
        return ans;
    }
};