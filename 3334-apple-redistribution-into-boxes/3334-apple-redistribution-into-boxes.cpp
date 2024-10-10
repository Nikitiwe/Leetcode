class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
        int sum=0, t=0;
        for (int i=0; i!=a.size(); i++) sum+=a[i];
        sort(c.rbegin(), c.rend());
        for (int i=0; i!=c.size(); i++)
        {
            t+=c[i];
            if (t>=sum) return i+1;
        }
        return -1;
    }
};