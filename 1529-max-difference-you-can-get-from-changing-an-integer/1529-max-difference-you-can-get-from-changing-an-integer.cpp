class Solution {
public:
    int maxDiff(int num) {
        string t=to_string(num);
        int ans=0;
        if (t[0]!='9')
        {
            char c=t[0];
            for (int i=0; i!=t.size(); i++)
            {
                if (t[i]==c) t[i]='9';
            }
        }
        else
        {
            int j=0;
            while (j<t.size()&&t[j]=='9') j++;
            if (j<t.size())
            {
                char c=t[j];
                for (int i=j; i<t.size(); i++)
                {
                    if (t[i]==c) t[i]='9';
                }
            }
        }
        ans+=stoi(t);
        t=to_string(num);
        if (t[0]!='1')
        {
            char c=t[0];
            for (int i=0; i!=t.size(); i++)
            {
                if (t[i]==c) t[i]='1';
            }
        }
        else
        {
            int j=0;
            while (j<t.size()&&(t[j]=='1'||t[j]=='0')) j++;
            if (j<t.size())
            {
                char c=t[j];
                for (int i=j; i<t.size(); i++)
                {
                    if (t[i]==c) t[i]='0';
                }
            }
        }
        ans-=stoi(t);
        return ans;
    }
};