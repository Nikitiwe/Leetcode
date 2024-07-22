class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[i].size(); j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int ans=0, l=0, r=arr.size()-1;
        if (l==r) return 0;
        while (l<r)
        {
            if ((arr[r]-arr[l])%x!=0||(arr[l+1]-arr[l])%x!=0) return -1;
            ans+=((arr[r]-arr[l])/x);
            l++;
            r--;
        }
        return ans;
    }
};