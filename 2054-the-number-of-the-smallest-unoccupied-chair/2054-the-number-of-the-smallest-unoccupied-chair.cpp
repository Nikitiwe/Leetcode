class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int st=times[targetFriend][0];
        sort (times.begin(), times.end());
        vector<int> arr(times.size(), 0);
        for (int i=0; i!=times.size(); i++)
        {
            for (int j=0; j!=times.size(); j++)
            {
                if (arr[j]<=times[i][0])
                {
                    arr[j]=times[i][1];
                    if (times[i][0]==st) return j;
                    break;
                }
            }
        }
        return -1;
    }
};