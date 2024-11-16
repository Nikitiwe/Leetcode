class Solution {
public:
    int nextBeautifulNumber(int n) {

        for (int i=n+1; i<n*100+2; i++)
        {
            int t=i;
            vector<int> arr(10, 0);
            while (t>0)
            {
                arr[t%10]++;
                t/=10;
            }
            bool isit=1;
            if (arr[0]!=0) isit=0;
            if (isit==1) for (int j=1; j!=10; j++)
            {
                if (arr[j]!=0&&arr[j]!=j)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) return i;
        }
        return -1;
    }
};