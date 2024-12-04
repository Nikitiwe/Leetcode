class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& q, int l) {
        vector<long long> ans(q.size(), -1);
        //sort(q.begin(), q.end());
        if (l%2==0)
        {
            long long a=1;
            for (int i=1; i<l/2; i++) a*=10;            
            for (int i=0; i!=q.size(); i++)
            {
                long long x=a+q[i]-1;
                string b=to_string(x);
                if (b.size()>l/2) continue;
                string c=b;
                reverse(c.begin(), c.end());
                ans[i]=stoll(b+c);
            }
        }
        else
        {
            long long a=1;
            for (int i=0; i<l/2; i++) a*=10;            
            for (int i=0; i!=q.size(); i++)
            {
                long long x=a+q[i]-1;
                string b=to_string(x);
                if (b.size()>(l+1)/2) continue;
                string c=b;
                c.pop_back();
                reverse(c.begin(), c.end());
                ans[i]=stoll(b+c);
            }
        }
        return ans;
    }
};