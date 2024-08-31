class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l=0, temp, ans=0;
        for (int i=0; i!=houses.size(); i++)
        {
            while (l+1<heaters.size()&&abs(houses[i]-heaters[l])>=abs(houses[i]-heaters[l+1])) l++;
            temp=abs(houses[i]-heaters[l]);
            ans=max(ans, temp);
        }
        return ans;
    }
};