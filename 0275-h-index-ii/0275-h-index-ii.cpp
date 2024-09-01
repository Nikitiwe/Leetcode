class Solution {
public:
    int hIndex(vector<int>& cit) {
        int l=0, r=cit.size()-1, m=(l+r)/2;
        while (l<r)
        {
            if (cit[m]>=cit.size()-m) {r=m;}
            else {l=m+1;}
            m=(l+r)/2;
        }
        return min((int)cit.size()-m, cit[m]);
    }
};