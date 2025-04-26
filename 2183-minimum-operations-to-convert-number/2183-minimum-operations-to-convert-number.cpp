class Solution {
public:
    int minimumOperations(vector<int>& nums, int s, int k) {
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        q.push({s, 0});
        seen.insert(s);
        while (q.size() > 0)
        {
            int t = q.front().first, l = q.front().second;
            q.pop();
            for (int i=0; i!=nums.size(); i++)
            {
                int a = t + nums[i];
                if (seen.count(a) == 0)
                {
                    if (a == k) return l+1;
                    if (a >= 0 && a <= 1000) {q.push({a, l+1});
                    seen.insert(a);}
                }
                a = t - nums[i];
                if (seen.count(a) == 0)
                {
                    if (a == k) return l+1;
                    if (a >= 0 && a <= 1000) {q.push({a, l+1});
                    seen.insert(a);}
                }
                a = t ^ nums[i];
                if (seen.count(a) == 0)
                {
                    if (a == k) return l+1;
                    if (a >= 0 && a <= 1000) {q.push({a, l+1});
                    seen.insert(a);}
                }
            }
        }
        return -1;
    }
};