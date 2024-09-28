class Solution {
public:
    vector<int> validSequence(string s, string w) {
        if (w.size()==1) return {0};
        vector<int> ans(w.size(), 0);
        for (int i=0; i<w.size(); i++)
        {
            if (i>0)
            {
                int a=0, b=i-1;
                if (i>1) a=ans[i-2]+1;
                while (a<s.size()&&s[a]!=w[b]) a++;
                if (a==s.size()) return {};
                ans[b]=a;
                ans[i]=ans[i-1]+1;
            }
            if (i==w.size()-1)
            {
                ans[i]=ans[i-1]+1;
                if (ans[i]<s.size()) return ans;
                else return {};
            }
            
            if (s[ans[i]]!=w[i])
            {
            int l=ans[i]+1, r=i+1;
            bool isit=0;
            while (l<s.size()&&r<w.size())
            {
                if (s[l]==w[r])
                {
                    ans[r]=l;
                    l++;
                    r++;
                    if (r==w.size()) isit=1;
                }
                else l++;
            }
            if (isit==1) return ans;
            }
        }
        return {};
    }
};