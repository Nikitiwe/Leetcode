class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans=special[0]-bottom, l=1;
        for (l; l!=special.size(); l++)
        {
            ans=max(ans, special[l]-special[l-1]-1);
        }
        ans=max(ans, top-special[special.size()-1]);
        return ans;
    }
};