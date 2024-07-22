class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m=0, ans=0, l=0, r=0, tempm;
        while (l<arr.size())
        {
            m=arr[l];
            r=l;
            tempm=l;
            for (int i=l; i<arr.size(); i++)
            {
                if (arr[i]<m)
                {
                    r=i;
                    for (int j=tempm; j<r; j++)
                    {
                        if (arr[j]>m)
                        {
                            m=arr[j];
                            tempm=j;
                        }
                    }
                }
            }
            l=r+1;
            ans++;
        }
        return ans;
    }
};