class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum=0, shef=0, a, b, zero;
        double ans;
        zero=(double)0;
        for (int i=0; i!=customers.size(); i++)
        {
            a=(double)customers[i][0];
            b=(double)customers[i][1];
            sum+=max(shef-a, zero)+b;
            shef=b+max(shef, a);
        }
        ans=(double)sum/customers.size();
        return ans;
    }
};