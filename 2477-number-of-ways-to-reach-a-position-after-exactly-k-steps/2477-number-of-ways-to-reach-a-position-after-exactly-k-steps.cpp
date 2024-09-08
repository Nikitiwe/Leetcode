class Solution {
public:
    int numberOfWays(int s, int e, int k) {
        int n=abs(s-e);
        if ((s-e-k)%2!=0||n>k) return 0;
        n=(k+n)/2;
        if (n>k/2) n=k-n;
        vector<int> arr, arrn(1, 1);
        for (int i=0; i<=k; i++)
        {
            arr.push_back(1);
            arr=arrn;
            arrn.push_back(1);
            for (int j=1; j<arr.size()-1; j++)
            {
                arrn[j]=arr[j-1]+arr[j];
                arrn[j]%=1000000007;
            }
        }
        return arrn[n];

    }
};