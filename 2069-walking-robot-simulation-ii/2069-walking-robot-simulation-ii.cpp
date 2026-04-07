class Robot {
public:
    string dir;
    map<string,string>mp;
    int x,y;
    int p;
    int w,h;
    Robot(int width, int height) {
        p=2*(width+height)-4;
        w=width;
        h=height;
        dir="East";
        mp["East"]="North";
        mp["North"]="West";
        mp["West"]="South";
        mp["South"]="East";
        x=0;
        y=0;
    }
    
    void step(int num) {
        num %= p;
        if (num == 0) num = p;

        while (num > 0) {
            if (dir == "East") {
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = "North";
            } 
            else if (dir == "North") {
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = "West";
            } 
            else if (dir == "West") {
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = "South";
            } 
            else {
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = "East";
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */