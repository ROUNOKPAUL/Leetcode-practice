class Solution {
public:
    long long countCommas(long long n) {
        long long totalcommas=0;
        long long currentInterval=1000;
        while(n>=currentInterval){
            totalcommas+=(n-currentInterval+1);
            if(currentInterval>LLONG_MAX/1000)break;
            currentInterval*=1000;
        }
        return totalcommas;
    }
};