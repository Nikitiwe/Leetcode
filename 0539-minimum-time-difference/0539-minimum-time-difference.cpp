class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int m=9999;
        for (int i=0; i!=timePoints.size(); i++)
        {
            times.push_back((timePoints[i][0]-'0')*600+(timePoints[i][1]-'0')*60+(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0'));
        }
        for (int i=0; i!=timePoints.size()-1; i++)
        {
            for (int j=i+1; j!=timePoints.size(); j++)
            {
                m=min(m, min(abs(times[i]-times[j]), 1440-abs(times[i]-times[j])));
            }
        }
        return m;
    }
};