class Solution {
public:
    int minCut(string ss) {
        string s="1";
        s+=ss;
        vector<int> arr(s.size(), 3000);
        arr[0]=1;
        arr[1]=1;
        for (int i=2; i<s.size(); i++)
        {
            for (int j=2; j<=i; j++)
            {
                bool isit=1;
                for (int a=0; a<=(i-j)/2; a++)
                {
                    if (s[j+a]!=s[i-a]) {isit=0; break;}
                }
                if (isit==1)
                {
                    arr[i]=min(arr[i], arr[j-1]+1);
                }
            }
            {
                bool isit=1;
                for (int a=0; a<=i/2; a++)
                {
                    if (s[1+a]!=s[i-a]) {isit=0; break;}
                }
                if (isit==1)
                {
                    arr[i]=min(arr[i], arr[0]);
                }
            }
        }
        return arr[s.size()-1]-1;
    }
};