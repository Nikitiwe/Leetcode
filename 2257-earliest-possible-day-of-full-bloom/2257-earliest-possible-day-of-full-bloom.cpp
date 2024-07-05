bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
}

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> time;
        for (int i=0; i!=plantTime.size(); i++)
        {time.push_back({plantTime[i], growTime[i]});}
        sort(time.begin(), time.end(), sortcol);
        int temp=0, max=0;
        for (int i=0; i!=time.size(); i++)
        {
            temp=temp+time[i][0];
            if (temp+time[i][1]>max) max=temp+time[i][1];
        }
        return max;
    }
};