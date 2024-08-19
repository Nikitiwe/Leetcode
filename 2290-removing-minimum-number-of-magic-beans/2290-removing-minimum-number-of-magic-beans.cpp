class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        vector<long> l(beans.size()+1, 0);
        long sum=0, ans=99999999999;
        for (int i=0; i!=beans.size(); i++)
        {
            sum+=beans[i];
            l[i+1]=sum;
        }
        for (int i=0; i!=beans.size(); i++)
        {
            l[i]+=(sum-l[i+1])-beans[i]*(beans.size()-1-i);
        }
        for (int i=0; i!=beans.size(); i++)
        {
            ans=min(ans, l[i]);
        }
        return ans;
    }
};