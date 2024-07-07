bool comp(vector<int> a, vector<int> b) 
{ 
    return (abs(a[0]-a[1]) > abs(b[0]-b[1])); 
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        int a=0, b=0, sum=0, n=costs.size();
        for (int i=0; i!=n; i++)
        {
            if (costs[i][0]<costs[i][1])
            {
                if (a<n/2) {sum+=costs[i][0]; a++;}
                else {sum+=costs[i][1]; b++;}
            }
            else
            {
                if (b<n/2) {sum+=costs[i][1]; b++;}
                else {sum+=costs[i][0]; a++;}
            }
        }
        return sum;
    }
};