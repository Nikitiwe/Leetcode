class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> m;
        double temp;
        long long t;
        long long ans=0;
        for (int i=0; i!=rectangles.size(); i++)
        {
            temp=(double)rectangles[i][0]/rectangles[i][1];
            if (m.count(temp)==0) m.insert({temp, 1});
            else m[temp]++;
        }
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            t=it->second;
            ans+=(t*(t-1)/2);
        }
        return ans;
    }
};