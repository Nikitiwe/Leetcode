class Solution {
public:
    int maximumPopulation(vector<vector<int>>& l) {
        vector<int> arr(101, 0);
        for (int i=0; i!=l.size(); i++)
        {
            arr[l[i][0]-1950]++;
            arr[l[i][1]-1950]--;
        }
        int ans=0;
        for (int i=1; i<arr.size(); i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]>arr[ans]) ans=i;
        }
        return ans+1950;
    }
};