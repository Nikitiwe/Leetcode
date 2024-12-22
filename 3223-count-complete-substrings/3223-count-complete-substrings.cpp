class Solution {
public:
    int countCompleteSubstrings(string s, int k) {
        int ans=0;
        vector<int> zero(26, 0), nl(s.size(), 0);
        for (int i=1; i<s.size(); i++) if (abs(s[i]-s[i-1])>2) nl[i]++;
        for (int n=1; n<=26; n++)
        {
            int m=n*k;
            if (m<=s.size())
            {
                vector<int> arr(26, 0);
                int l=0;
                for (int i=0; i<s.size(); i++)
                {
                    if (nl[i]==0)
                    {
                        arr[s[i]-'a']++;
                        l++;
                        if (l==m)
                        {
                            bool isit=1;
                            for (int j=0; j!=26; j++)
                            {
                                if (arr[j]==0||arr[j]==k) continue;
                                else
                                {
                                    isit=0;
                                    break;
                                }
                            }
                            if (isit==1) ans++;
                        }
                        else if (l>m)
                        {
                            arr[s[i-m]-'a']--;
                            bool isit=1;
                            for (int j=0; j!=26; j++)
                            {
                                if (arr[j]==0||arr[j]==k) continue;
                                else
                                {
                                    isit=0;
                                    break;
                                }
                            }
                            if (isit==1) ans++;
                        }
                    }
                    else
                    {
                        arr=zero;
                        arr[s[i]-'a']++;
                        l=1;
                        if (l==m)
                        {
                            bool isit=1;
                            for (int j=0; j!=26; j++)
                            {
                                if (arr[j]==0||arr[j]==k) continue;
                                else
                                {
                                    isit=0;
                                    break;
                                }
                            }
                            if (isit==1) ans++;
                        }
                        else if (l>m)
                        {
                            arr[s[i-m]-'a']--;
                            bool isit=1;
                            for (int j=0; j!=26; j++)
                            {
                                if (arr[j]==0||arr[j]==k) continue;
                                else
                                {
                                    isit=0;
                                    break;
                                }
                            }
                            if (isit==1) ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};