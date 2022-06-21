class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int sj = jewels.length();
        int ss = stones.length();
        int jc = 0;
        for(int i=0;i<ss;i++){
            for(int j=0;j<sj;j++){
                if(stones[i]== jewels[j])
                    jc++;
            }
        }
        return jc;
    }
};