#define ll long long
class Solution {
public:
    ll dig_sum(int n)
    {
        ll sum=0;
        while(n!=0)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<tuple<ll,int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_tuple(dig_sum(nums[i]),i,nums[i]));
        }
        sort(v.begin(),v.end(),[&](auto &a,auto &b){
            if(get<0>(a)!=get<0>(b)) return get<0>(a)<get<0>(b);
            return get<2>(a)<get<2>(b);
        });
        //for(auto [d,ind,num]:v) cout<<d<<" "<<num<<endl;

        vector<bool> vis(n,false);
        int ans=0;
        //we would have disjoint cycles and swaps_requried=(cycle_length-1)
        //no changes are needed if sorted_index=original_index
        for(int i=0;i<n;i++)
        {
            if(vis[i]==true || i==get<1>(v[i])) continue;
            int len=0;
            int head=i;
            while(!vis[head])//until we see head again
            {
                vis[head]=true;
                head=get<1>(v[head]);
                len++;
            }
            ans+=(len-1);
        } 
        return ans;
    }
};