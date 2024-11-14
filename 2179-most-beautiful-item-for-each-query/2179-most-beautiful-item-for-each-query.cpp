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
        /*vector<int> f(arr.size(), 0), s(arr.size(), 0);
        for (int i=0; i!=arr.size(); i++)
        {
            f[i]=arr[i][0];
            s[i]=arr[i][1];
        }
        return s;*/
        for (int i=0; i!=q.size(); i++)
        {
            if (q[i]<arr[0][0]) q[i]=0;
            else if (q[i]>=arr[arr.size()-1][0]) q[i]=arr[arr.size()-1][1];
            else
            {
                int l=0, r=arr.size()-1, m=(l+r)/2;
                while (l<r-1)
                {
                    m=(l+r)/2;
                    if (arr[m][0]>q[i]) r=m-1;
                    else if (arr[m][0]==q[i]) break;
                    else if (arr[m][0]<q[i]) l=m;
                }
                if (arr[m][0]==q[i]) q[i]=arr[m][1];
                else if (arr[m][0]<q[i])
                {
                    while (m+1<arr.size()&&arr[m+1][0]<=q[i]) m++;
                    q[i]=arr[m][1];
                    /*if (m+1<arr.size()&&arr[m+1][0]<=q[i]) q[i]=arr[m+1][1];
                    else q[i]=arr[m][1];*/
                }
                else if (arr[m][0]>q[i])
                {
                    if (m==0) q[i]=0;
                    else
                    {
                        if (arr[m-1][0]<=q[i]) q[i]=arr[m-1][1];
                        else
                        {
                            if (m==1) q[i]=0;
                            else q[i]=arr[m-2][1];
                        }
                    }
                }
            }
        }
        return q;
    }
};