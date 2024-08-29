class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        if (k>=skills.size()) return distance(skills.begin(), max_element(skills.begin(), skills.end()));
        //if (distance(skills.begin(), max_element(skills.begin(), skills.end()))<=k)
        //    return distance(skills.begin(), max_element(skills.begin(), skills.end()));
        int count=1, idw=0, l=2;
        if (skills[1]>skills[0])
        {
            idw++;
            skills.push_back(skills[0]);
        }
        else skills.push_back(skills[1]);
        if (count>=k) return idw;
        while (1)
        {
            if (skills[l]>skills[idw])
            {
                skills.push_back(skills[idw]);
                idw=l;
                count=1;
            }
            else
            {
                count++;
                if (count>=k) return idw;
                skills.push_back(skills[l]);
            }
            l++;
        }
        return -1;
    }
};