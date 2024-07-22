class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m=0, ans=0, l=0, r=0;
        while (l<arr.size())
        {
            m=arr[l];
            r=l;
            for (int i=l; i<arr.size(); i++)
            {
                if (arr[i]<m)
                {
                    r=i;
                    for (int j=l+1; j<r; j++)
                    {
                        m=max(m, arr[j]);
                    }
                }
            }
            l=r+1;
            ans++;
        }
        return ans;
    }
};