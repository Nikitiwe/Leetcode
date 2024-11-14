class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        arr.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i][0]==arr[arr.size()-1][0]) arr[arr.size()-1][1]=max(arr[arr.size()-1][1], nums[i][1]);
            else if (nums[i][1]>arr[arr.size()-1][1]) arr.push_back(nums[i]);
        }
        for (int i=0; i!=q.size(); i++)
        {
            if (q[i]<arr[0][0]) q[i]=0;
            else if (q[i]>=arr[arr.size()-1][0]) q[i]=arr[arr.size()-1][1];
            else
            {
                int l=0, r=arr.size()-1, m=(l+r)/2, ans=0;
                while (l<r)
                {
                    m=(l+r)/2;
                    if (arr[m][0]>q[i])
                    {
                        r=m-1;
                    }
                    else if (arr[m][0]<=q[i])
                    {
                        ans=max(ans, arr[m][1]);
                        l=m+1;
                    }
                }
                m=(l+r)/2;
                if (arr[m][0]<=q[i]) ans=max(ans, arr[m][1]);
                q[i]=ans;
            }
        }
        return q;
    }
};