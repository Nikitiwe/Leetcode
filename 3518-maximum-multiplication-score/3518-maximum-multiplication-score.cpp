class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long> prev(b.size()+1, -999999999999), next=prev, zero=next;
        for (int i=0; i<b.size(); i++)
        {
            prev[i+1]=(long)b[i]*a[0];
            prev[i+1]=max(prev[i+1], prev[i]);
        }
        for (int k=1; k<=3; k++)
        {
            for (int i=k; i<b.size(); i++)
            {
                next[i+1]=prev[i]+(long)b[i]*a[k];
                next[i+1]=max(next[i+1], next[i]);
            }
            prev=next;
            next=zero;
        }
        return prev.back();
    }
};