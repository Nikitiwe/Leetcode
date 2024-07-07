class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int sum=n, r=n-1;
        while (sum<k)
        {
            if (sum+25<k)
            {
                ans[r]='z';
                sum+=25;
                r--;
            }
            else
            {
                ans[r]=(char)('a'+k-sum);
                sum=k;
            }
        }
        return ans;
    }
};