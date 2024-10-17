class ParkingSystem {
private:
    int x, y, z;
public:
    ParkingSystem(int b, int m, int s) {
        x=b;
        y=m;
        z=s;
    }
    
    bool addCar(int t) {
        if (t==1)
        {
            if (x>0)
            {
                x--;
                return 1;
            }
            else return 0;
        }
        else if (t==2)
        {
            if (y>0)
            {
                y--;
                return 1;
            }
            else return 0;
        }
        else
        {
            if (z>0)
            {
                z--;
                return 1;
            }
            else return 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */