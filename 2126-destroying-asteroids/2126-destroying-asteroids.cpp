class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long temp = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i: asteroids){
            if(temp<i) return false;
            temp+=i;
        }
        return true;
    }
};