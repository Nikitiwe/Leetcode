class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastM=0, lastP=0, lastG=0, countM=0, countP=0, countG=0, sum=0;
        vector<int> traveltoI;
        for (int i=garbage.size()-1; i>=0; i--)
        {
            for (int j=0; j<garbage[i].size(); j++)
            {
                if (garbage[i][j]=='M') {countM++; if (lastM==0) lastM=i;}
                else if (garbage[i][j]=='P') {countP++; if (lastP==0) lastP=i;}
                else {countG++; if (lastG==0) lastG=i;}
            }
        }
        traveltoI.push_back(0);
        for (int i=0; i<travel.size(); i++)
        {
            sum=sum+travel[i];
            traveltoI.push_back(sum);
        }
        return countM+countP+countG+traveltoI[lastM]+traveltoI[lastP]+traveltoI[lastG];
    }
};