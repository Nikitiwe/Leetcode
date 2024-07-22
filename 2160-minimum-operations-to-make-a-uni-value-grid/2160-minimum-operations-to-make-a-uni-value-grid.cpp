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
        int ans=0, l=0, r=arr.size()-1, temp;
        if (l==r) return 0;
        while (l<r)
        {
            temp=arr[r]-arr[l];
            if (temp%x!=0||(arr[l+1]-arr[l])%x!=0) return -1;
            ans+=(temp/x);
            l++;
            r--;
        }
        return ans;
    }
};