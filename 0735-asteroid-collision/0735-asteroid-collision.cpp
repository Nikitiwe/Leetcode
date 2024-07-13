class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.push_back(asteroids[0]);
        for (int i=1; i!=asteroids.size(); i++)
        {
            ans.push_back(asteroids[i]);
            while (ans.size()>1&&ans[ans.size()-2]>0&&ans[ans.size()-1]<0)
            {
                if (ans[ans.size()-2]>abs(ans[ans.size()-1])) ans.erase(ans.end()-1);
                else if (ans[ans.size()-2]<abs(ans[ans.size()-1])) ans.erase(ans.end()-2);
                else {ans.erase(ans.end()-1); ans.erase(ans.end()-1);}
            }
        }
        return ans;
    }
};