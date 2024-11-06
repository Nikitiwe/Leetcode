class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int c) {
        int d=0;
        for (int i=0; i!=t.size(); i++) d=max(d, t[i][2]);
        vector<int> arr(d+1, 0);
        for (int i=0; i!=t.size(); i++)
        {
            arr[t[i][1]]+=t[i][0];
            arr[t[i][2]]-=t[i][0];
        }
        if (arr[0]>c) return 0;
        for (int i=1; i<arr.size(); i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]>c) return 0;
        }
        return 1;
    }
};