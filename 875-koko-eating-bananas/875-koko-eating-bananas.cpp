class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l =1;
        int e =0;
        for(int i=0; i<n; i++){
            e = max(e, piles[i]);
        }
        while(l<e){
            int m = l+ ((e-l)/2);
            int uh = 0;
            for(int j=0; j<n; j++){
                if(piles[j]%m==0)
                    uh = uh+ (piles[j]/m);
                else if(piles[j]%m != 0)
                    uh = uh+ (piles[j]/m) + 1;
            }
            if(uh>h)
                l = m+1;
            else
                e=m;
        }
        return e;
    }
};