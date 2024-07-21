class Solution {
public:
    int minChanges(int n, int k) {
        vector<int> n1, k1;
        while (n>0)
        {
            n1.push_back(n%2);
            n/=2;
        }
        while (k>0)
        {
            k1.push_back(k%2);
            k/=2;
        }
        while (k1.size()<n1.size())
        {
            k1.push_back(0);
        }
        while (k1.size()>n1.size())
        {
            n1.push_back(0);
        }
        int ans=0;
        for (int i=0; i<n1.size(); i++)
        {
            if (n1[i]==1&&k1[i]==0) ans++;
            else if (n1[i]==0&&k1[i]==1) return -1;
        }
        return ans;
    }
};