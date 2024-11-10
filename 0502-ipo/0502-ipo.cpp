class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<vector<int>> arr(c.size(), vector<int> (2, 0));
        for (int i=0; i!=c.size(); i++)
        {
            arr[i][0]=c[i];
            arr[i][1]=p[i];
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> m;
        int l=0;
        while (l<c.size()&&arr[l][0]<=w)
        {
            m.push(arr[l][1]);
            l++;
        }
        while (k>0)
        {
            if (m.size()==0) break;
            w+=m.top();
            m.pop();
            k--;
            while (l<c.size()&&arr[l][0]<=w)
            {
                m.push(arr[l][1]);
                l++;
            }
        }
        return w;
    }
};