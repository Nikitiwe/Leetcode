class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //vector<int> arr(stations.size()+1, 0);
        vector<int> f;
        int ans=0;
        int i=0;
        while (i<stations.size())
        {
            if (startFuel<stations[i][0]&&f.size()==0) return -1;
            else if (startFuel>=stations[i][0])
            {
                f.push_back(stations[i][1]);
                sort(f.begin(), f.end());
                i++;
            }
            else
            {
                startFuel+=f[f.size()-1];
                f.pop_back();
                ans++;
            }
        }
        while (target>startFuel&&f.size()>0)
        {
            startFuel+=f[f.size()-1];
            f.pop_back();
            ans++;
        }
        if (target>startFuel) return -1;
        else return ans;
    }
};