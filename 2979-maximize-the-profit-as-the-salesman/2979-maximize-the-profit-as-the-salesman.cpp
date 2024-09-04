class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& o) {
        sort(o.begin(), o.end());
        vector<int> arr(n+1, 0);
        int j=0;
        for (int i=0; i!=n; i++)
        {
            if (i>0) arr[i]=max(arr[i], arr[i-1]);
            while (j<o.size()&&o[j][0]==i)
            {
                arr[o[j][1]+1]=max(arr[i]+o[j][2], arr[o[j][1]+1]);
                j++;
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};