class Solution {
public:
    int twoEggDrop(int n) {
        int sum=0, i=0;
        while (sum<n)
        {
            i++;
            sum=sum+i;
        }
        return i;
    }
};