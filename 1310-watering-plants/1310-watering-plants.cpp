class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0, maxIwat=0, can=capacity;
        while (maxIwat!=plants.size())
        {
            while (can>=plants[maxIwat])
            {
                can=can-plants[maxIwat];
                if (maxIwat!=plants.size()-1) maxIwat++;
                else return ans+1;
                ans++;
            }
            can=capacity;
            ans=ans+2*maxIwat;
        }
        return ans+1;
    }
};