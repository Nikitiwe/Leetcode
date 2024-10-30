class Solution {
public:
    double average(vector<int>& s) {
        int sum=0, mi=1000000, ma=1000;
        for (int i=0; i!=s.size(); i++)
        {
            sum+=s[i];
            mi=min(mi, s[i]);
            ma=max(ma, s[i]);
        }
        return (double)(sum-mi-ma)/(s.size()-2);
    }
};