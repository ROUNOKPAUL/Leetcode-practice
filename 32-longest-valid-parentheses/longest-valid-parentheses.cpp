class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int open=0,close=0;
        int mx=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='('){
                open++;
            }else{
                close++;
            }
            if(open==close){
                int len=open+close;
                mx=max(mx,len);
            }
            else if(close>open){
                open=close=0;
            }
        }
        open=close=0;
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            if(c=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
                int len=open+close;
                mx=max(mx,len);
            }
            if(open>close){
                open=close=0;
            }
        }
        return mx;
    }
};