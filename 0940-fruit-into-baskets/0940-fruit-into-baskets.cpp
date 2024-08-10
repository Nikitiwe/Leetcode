class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int ans=1, l=0, r=0;
        m[fruits[0]]++;
        while (r!=fruits.size())
        {
            if (m.size()<3)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==fruits.size()) break;
                m[fruits[r]]++;
            }
            else
            {
                m[fruits[l]]--;
                if (m[fruits[l]]==0) m.erase(fruits[l]);
                l++;
            }
        }
        return ans;
    }
};