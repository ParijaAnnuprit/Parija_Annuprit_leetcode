class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        vector<int>fin;
        sort(candyType.begin(),candyType.end());
        fin.push_back(candyType[0]);
        for(int i=1;i<candyType.size();i++){
            if(candyType[i]==candyType[i-1])
                continue;
            else
                fin.push_back(candyType[i]);
        }
        int n= (candyType.size())/2;
        if(n>=fin.size())
            return fin.size();
        return n;
    }
};