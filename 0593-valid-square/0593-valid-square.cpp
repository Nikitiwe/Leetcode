class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        /*if (p2[0]>p1[0]) swap(p1, p2);
        if (p4[0]>p3[0]) swap(p3, p4);
        if (p3[0]>p1[0]) swap(p1, p3);
        if (p2[0]>p4[0]) swap(p2, p4);
        if (p3[0]>p2[0]) swap(p2, p3);*/
        if (p1==p2||p1==p3||p1==p4||p2==p3||p2==p4||p3==p4) return 0;
        unordered_set<int> m;
        m.insert((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
        m.insert((p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]));
        m.insert((p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1]));
        m.insert((p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]));
        m.insert((p2[0]-p4[0])*(p2[0]-p4[0])+(p2[1]-p4[1])*(p2[1]-p4[1]));
        m.insert((p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]));
        if (m.size()==2) return 1;
        else return 0;
        
    }
};