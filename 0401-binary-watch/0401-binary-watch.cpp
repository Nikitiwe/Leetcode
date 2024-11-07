class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        vector<string> ans;
        for (int i=0; i!=720; i++)
        {
            int m=i%60, h=i/60;
            int a=m, b=h, s=0;
            while (a>0)
            {
                s+=a%2;
                a/=2;
            }
            while (b>0)
            {
                s+=b%2;
                b/=2;
            }
            if (s==n)
            {
                if (m>=10) ans.push_back(to_string(h)+':'+to_string(m));
                else ans.push_back(to_string(h)+":0"+to_string(m));
            }
        }
        return ans;
    }
};