class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& nums) {
        vector<int> xb(2*nums.size()+1), xe=xb, yb(2*nums.size()+1), ye=yb;
        vector<vector<int>> mx, my;
        for (int i=0; i!=nums.size(); i++)
        {
            mx.push_back({nums[i][0], 1});
            mx.push_back({nums[i][2], -1});
            my.push_back({nums[i][1], 1});
            my.push_back({nums[i][3], -1});
        }
        sort(mx.begin(), mx.end());
        sort(my.begin(), my.end());
        for (int i=0; i!=mx.size(); i++)
        {
            if (mx[i][1]==1) xb[i]++;
            else xe[i+1]--;
            if (my[i][1]==1) yb[i]++;
            else ye[i+1]--;
        }
        bool isit=0;
        int c=0;
        for (int i=1; i<xe.size()-1; i++)
        {
            xe[i]+=xe[i-1];
            xe[i]+=xb[i-1];
            if (xe[i]==0)
            {
                c++;
                if (c==2)
                {
                    isit=1;
                    break;
                }
            }
        }
        c=0;
        if (isit==0) for (int i=1; i<ye.size()-1; i++)
        {
            ye[i]+=ye[i-1];
            ye[i]+=yb[i-1];
            if (ye[i]==0)
            {
                c++;
                if (c==2)
                {
                    isit=1;
                    break;
                }
            }
        }
        if (isit==1) return 1;
        else return 0;
    }
};