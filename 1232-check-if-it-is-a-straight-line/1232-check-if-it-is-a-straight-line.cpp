class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)
            return true;
        int x = (coordinates[1][0]-coordinates[0][0]);
        int y = (coordinates[1][1]-coordinates[0][1]);
        for(int i=2;i<coordinates.size();i++){
            int k = (coordinates[i][0]-coordinates[0][0]);
            int l = (coordinates[i][1]-coordinates[0][1]);
            if(k*y != l*x)
                return false;
        }
        return true;
    }
};