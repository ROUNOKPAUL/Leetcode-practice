class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int count=0;
        string result="";
        for(char c:s){
            if(c=='('){
                if(count!=0)result.push_back(c);
                count++;
            }else{
                count--;
                if(count!=0)result.push_back(c);
            }
        }
        return result;
    }
};