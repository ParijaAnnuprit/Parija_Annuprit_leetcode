// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
        
//     }
// };
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<int, string> hashes;
        int n = dictionary.size(), base = 27;
        vector<string> words;
        long long int prime = 1000000007 , maxBase = 1, currentHash = 0;
        string word = "";
		//from here we start step1.
        for(int i = 0; i < n; i++){
            currentHash = 0;
            word = dictionary[i];
            int m = word.size();
            for(int j = 0 ; j < m; j++){
                currentHash = currentHash*base % prime;
                currentHash += word[j] - 'a' + 1;
            }
            
            hashes[currentHash] = word;
        }
		//step 1 ends here
        string answer = "";
        int start = 0;
        currentHash = 0;
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] != ' '){
                currentHash  = currentHash*base % prime;
                currentHash += sentence[i] - 'a' + 1;
                if(hashes.find(currentHash) != hashes.end()){
				//we replace or append as stated in step 3 and jump on to the next word in sentence using while loop
                    answer = answer + hashes[currentHash];
                    answer += ' ';
                    currentHash = 0;
                    while(i < sentence.size()){
                        if(sentence[i] != ' '){
                            i++;
                        }
                        else{
                            break;
                        }
                    }
                    start = i+1;
                }
            }
            else{
                currentHash = 0;
              answer += sentence.substr(start , i - start);
                start = i+1;
                answer  += ' ';
            }    
			// this statement is just for an edge case 
           if(i == sentence.size()-1){
               for(int i = start ; i < sentence.size(); i++){
                   answer += sentence[i];
               }   
                answer += ' ';
            }
        }
		//we pop out the additional space added from our answer string.
        answer.pop_back();
        return answer;
    
    }
};