class Solution {
public:
    int closestTarget(vector<string>& s, string target, int startIndex) {
        int ans = 1000;
        for (int i=0; i<s.size(); i++)
        {
            if (s[(i+startIndex)%s.size()] == target)
            {
                ans = min(ans, i);
                break;
            }
        }
        for (int i=0; i<s.size(); i++)
        {
            if (s[(-i+startIndex + s.size())%s.size()] == target)
            {
                ans = min(ans, i);
                break;
            }
        }
        if (ans < 1000) return ans;
        else return -1;
    }
};