class Solution {
private:
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        bool isit = 0;
        double a, b;
        while(isit == 0)
        {
            a = x - r + 2*r*rand()/RAND_MAX;
            b = y - r + 2*r*rand()/RAND_MAX;
            if ( (x-a)*(x-a) + (y-b)*(y-b) < r*r ) isit = 1;
        }
        return {a, b};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */