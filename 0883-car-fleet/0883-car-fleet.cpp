bool sort1(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> car;
        for (int i=0; i!=position.size(); i++)
        {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), sort1);
        vector<float> time(position.size(), 0);
        for (int i=0; i!=position.size(); i++)
        {
            time[i]=(float)(target-car[i][0])/car[i][1];
        }
        int ans=position.size();
        float temp=time[position.size()-1];
        for (int i=position.size()-2; i>=0; i--)
        {
            if (time[i]<=temp) ans--;
            else temp=time[i];
        }
        return ans;
    }
}; // ну бля какого хуя позиции не упорядочены