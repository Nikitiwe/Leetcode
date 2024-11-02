class Solution {
public:
    long long validSubstringCount(string s, string w) {      
        long long ans=0;
        vector<int> t(26, 0), arr=t;
        int l=0, r=0;
        for (int i=0; i!=26; i++) t[i]=0;
        for (int i=0; i!=w.size(); i++) t[w[i]-'a']++;

            for (int i=0; i!=26; i++)
            {
                while (r<s.size()&&arr[i]<t[i])
                {
                    arr[s[r]-'a']++;
                    r++;
                }
            }

        if (r==s.size())
        {
            bool isit=1;
            for (int i=0; i!=26; i++)
            {
                if (arr[i]<t[i]) isit=0;
            }
            if (isit==1) ans++;
        }
        else ans+=s.size()-r+1;
        while (l<s.size())
        {
            int k=s[l]-'a';
            arr[k]--;
            l++;
            while (r<s.size()&&arr[k]<t[k])
            {
                arr[s[r]-'a']++;
                r++;
            }
            if (r==s.size())
            {
                for (int i=0; i!=26; i++)
                {
                    if (arr[i]<t[i]) return ans;
                }
                ans++;
            }
            else ans+=s.size()-r+1;
        }
        return ans;
    }
};