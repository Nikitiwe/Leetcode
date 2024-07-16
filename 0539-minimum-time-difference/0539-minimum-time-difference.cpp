class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int m=720;
        for (int i=0; i!=timePoints.size(); i++)
        {
            times.push_back((timePoints[i][0]-'0')*600+(timePoints[i][1]-'0')*60+(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0'));
        }
        sort(times.begin(), times.end());
        for (int i=0; i!=timePoints.size()-1; i++)
        {
            m=min(m, min(times[i+1]-times[i], 1440-(times[i+1]-times[i])));
        }
        m=min(m, min(times[timePoints.size()-1]-times[0], 1440-(times[timePoints.size()-1]-times[0])));
        return m;
    }
};