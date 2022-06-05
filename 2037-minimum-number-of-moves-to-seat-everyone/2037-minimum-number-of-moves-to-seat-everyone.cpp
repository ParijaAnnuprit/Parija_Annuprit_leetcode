class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int k = seats.size();
        int minmov = 0;
        for(int i=0;i<k;i++){
            int d = abs(seats[i]-students[i]);
            minmov = minmov+d;
        }
        return minmov;
    }
};