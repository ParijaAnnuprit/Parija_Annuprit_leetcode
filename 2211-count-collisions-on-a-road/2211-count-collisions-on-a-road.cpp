class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int count = 0;
        for(int i=0;i<directions.length();i++){
            if(st.empty()) st.push(directions[i]);
            else if(st.top()=='R' && directions[i]=='L'){
                count+=2;
                st.pop();
                int x = 0;
                while(!st.empty() && st.top()=='R'){
                    st.pop();
                    x++;
                    count++;
                }
                while(x>0){
                    st.push('S');
                    x--;
                }
                st.push('S');
                st.push('S');
            }
            else if(st.top()=='R' && directions[i]=='S'){
                count+=1;
                st.pop();
                int x = 0;
                while(!st.empty() && st.top()=='R'){
                    st.pop();
                    x++;
                    count++;
                }
                while(x>0){
                    st.push('S');
                    x--;
                }
                st.push('S');
                st.push('S');
            }
            else if(st.top()=='S' && directions[i]=='L'){
                count++;
                st.push('S');
            }
            else st.push(directions[i]);
        }
        return count;
    }
};


