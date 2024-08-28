class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<int> f;
        int ans=0;
        int i=0;
        while (i<stations.size())
        {
            if (startFuel<stations[i][0]&&f.size()==0) return -1;
            else if (startFuel>=stations[i][0])
            {
                f.push_back(stations[i][1]);
                int j=f.size()-1;
                while (j>0&&f[j]<f[j-1])
                {
                    swap(f[j], f[j-1]);
                    j--;
                }
                i++; // тут как бы надо переписать с приорити кью
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