class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nrn = 0;
        int n = data.size();
        for(int i=0;i<n;i++){
            if(nrn == 0){
                if(data[i]>>5 == 0b110) nrn = 1;
                else if(data[i]>>4 == 0b1110) nrn = 2;
                else if(data[i]>>3 == 0b11110) nrn = 3;
                else if(data[i]>>7 != 0b0) return false;
            }
            else{
                if(data[i]>>6 != 0b10) return false;
                nrn--;
            }
        }
        if(nrn==0) return true;
        return false;
    }
};