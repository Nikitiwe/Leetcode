class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& mee) {
        sort(mee.begin(), mee.end());
        vector<int> ans(n, 0);
        vector<long> arr(n, 0);
        int temp;
        for (int i=0; i<mee.size(); i++)
        {
            temp=0;
            for (int j=0; j!=n; j++)
            {
                if (arr[j]<=mee[i][0])
                {
                    arr[j]=mee[i][1];
                    ans[j]++;
                    temp=-1;
                    break;
                }
                else if (arr[j]<arr[temp]) temp=j;
            }
            if (temp!=-1)
            {
                arr[temp]+=mee[i][1]-mee[i][0];
                ans[temp]++;
            }
        }
        return distance(ans.begin(), max_element(ans.begin(), ans.end()));
    }
};