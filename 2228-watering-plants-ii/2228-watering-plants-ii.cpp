class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a=capacityA, b=capacityB, l=0, r=plants.size()-1, ans=0;
        while (l<r)
        {
            if (plants[l]<=a) a-=plants[l];
            else {ans++; a=capacityA-plants[l];}
            l++;
            if (plants[r]<=b) b-=plants[r];
            else {ans++; b=capacityB-plants[r];}
            r--;
        }
        if (l==r)
        {
            if (plants[l]>a&&plants[r]>b) ans++;
        }
        return ans;
    }
};