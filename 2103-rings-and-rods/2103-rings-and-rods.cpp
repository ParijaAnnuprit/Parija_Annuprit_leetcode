class Solution {
public:
    int countPoints(string rings) {
        set<int>red;
        set<int>blue;
        set<int>green;
        for(int i=0;i<rings.length();i+=2){
            if(rings[i]=='R')
                red.insert(rings[i+1]-'0');
            if(rings[i]=='B')
                blue.insert(rings[i+1]-'0');
            if(rings[i]=='G')
                green.insert(rings[i+1]-'0');
        }
        int ans=0;
        for(int i=0;i<10;i++){
            if(red.count(i)>0 && blue.count(i)>0 && green.count(i)>0)
                ans++;
        }
        return ans;
    }
};