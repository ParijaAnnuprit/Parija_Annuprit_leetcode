class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>v;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()) st.push(asteroids[i]);
            else if(st.top()*asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(true){
                  if(st.empty()){
                      st.push(asteroids[i]);
                      break;
                    }
                else if(st.top()*asteroids[i]>0){
                    st.push(asteroids[i]);
                    break;
                    }
                    else{
                        if(asteroids[i]<0){
                            int x = asteroids[i]*-1;
                            if(x==st.top()){
                                st.pop();
                                break;
                            }
                            else if(x<st.top()) break;
                            else if(x>st.top()) st.pop();
                        }
                        else if(st.top()<0){
                            st.push(asteroids[i]);
                            break;
                        }
                    } 
                }
            }
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};