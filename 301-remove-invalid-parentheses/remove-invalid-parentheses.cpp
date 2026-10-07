class Solution {
public:
    bool isValid(string s){
        int open=0;
        int close=0;
        for(char c:s){
            if(c=='('){
                open++;
            }else if(c==')'){
                if(open>0)open--;
                else{
                    return false;
                }
            }
        }
        return open==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>visited;
        queue<string>q;
        visited.insert(s);
        q.push(s);
        vector<string>result;

        while(!q.empty()){
            string curr_string=q.front();
            q.pop();
            if(isValid(curr_string)){
                result.push_back(curr_string);
                while(!q.empty()){
                    string next_string=q.front();
                    q.pop();
                    if(isValid(next_string)){
                        result.push_back(next_string);
                    }
                }
                break;
            }
            for(int i=0;i<curr_string.size();i++){
                if(curr_string[i]=='('||curr_string[i]==')'){
                    string removed_string=curr_string.substr(0,i)+curr_string.substr(i+1);
                    if((visited.find(removed_string))==visited.end()){
                        q.push(removed_string);
                        visited.insert(removed_string);
                    }
                }
                
            }
        }
        return result;
    }
};