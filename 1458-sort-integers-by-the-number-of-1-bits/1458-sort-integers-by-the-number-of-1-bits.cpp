bool ssort(int &aa, int &bb)
{
    int ca = 0, cb = 0, a = aa, b = bb;
    while (a > 0)
    {
        ca += a%2;
        a /= 2;
    }
    while (b > 0)
    {
        cb += b%2;
        b /= 2;
    }
    if (ca == cb) return aa < bb;
    else return ca < cb;

}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), ssort);
        return arr;
    }
};