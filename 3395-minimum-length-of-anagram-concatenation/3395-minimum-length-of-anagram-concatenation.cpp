class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> arr(26, 0), arr1(26, 0), arrz(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        int l=0;
        while (arr[l]==0) l++;
        int g=arr[l];
        for (int i=l+1; i<arr.size(); i++)
        {
            if (arr[i]!=0) g=gcd(g, arr[i]);
        }
        int range=s.size()/g;
        //return max(range, g);
        for (int i=1; i<(s.size()+2)/2; i++)
        {
            arr=arrz;
            arr1=arrz;
            if (s.size()%i==0)
            {
                int r=0;
                while (r<i)
                {
                    arr[s[r]-'a']++;
                    r++;
                }
                bool isit=1;
                while (r<s.size())
                {
                    arr1[s[r]-'a']++;
                    r++;
                    if (r%i==0)
                    {
                        if (arr1!=arr) {isit=0; break;}
                        arr1=arrz;
                    }
                    if (r==s.size()&&isit==1) return i;
                }
            }
        }
        return s.size();
    }
};