class Solution {
public:
    int minDistance(vector<int>& h, int kk) {
        sort(h.begin(), h.end());
        vector<vector<int>> sum(h.size(), vector<int>(h.size(), 0));
        for (int j=0; j!=h.size(); j++)
        {
            for (int i=j+1; i<h.size(); i++)
            {
                for (int t=0; t<=(i-j)/2; t++)
                {
                    sum[j][i] += h[i-t] - h[j+t];
                }
            }
        }
        vector<vector<int>> arr(h.size(), vector<int>(kk+1, 10000000));
        for (int i=0; i<h.size(); i++) arr[i][1] = sum[0][i];
        for (int k=2; k<=kk; k++)
        {
            for (int i=1; i<h.size(); i++)
            {
                arr[i][k] = arr[i-1][k-1];
                for (int j=0; j<i; j++)
                {
                    arr[i][k] = min(arr[i][k], arr[j][k-1] + sum[j+1][i]);
                }
            }
        }
        return arr[h.size()-1][kk];
    }
};


/*
for (int i=0; i<h.size(); i++) arr[i][1] = h[i] - h[0];
        for (int k=2; k<=kk; k++)
        {
            for (int i=1; i<h.size(); i++)
            {
                arr[i][k] = arr[i-1][k-1];
                for (int j=0; j<i; j++)
                {
                    arr[i][k] = min(arr[i][k], arr[j][k-1] + h[i] - h[j+1]);
                }
            }
        }
        return arr[h.size()-1][kk];
        */