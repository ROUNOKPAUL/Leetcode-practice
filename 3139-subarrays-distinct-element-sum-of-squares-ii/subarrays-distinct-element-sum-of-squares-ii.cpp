#define ll long long int  
class Solution {
public:
    const ll mod = 1e9 + 7;
    vector<ll> seg_tree, lazy, sq_sum;
    void apply(int x, ll len, ll k)
    {


        sq_sum[x] = (sq_sum[x] + (2 * seg_tree[x] * k) + k * k * len)%mod;
        seg_tree[x] = (seg_tree[x] + k * len)%mod;

        lazy[x] = (lazy[x] + k)%mod;


    }
    void update(int i, int j, int x, int l, int r)
    {
        if(j < l || r < i)
            return;

        if(l <= i && j <= r)
        {
            
            ll len = (ll)(j-i+1);
            apply(x, len, 1);
            
            return;

        }




        int mid = (i + j)/2;

        if(lazy[x] != 0)
        {

            
            apply(2*x+1, mid-i+1, lazy[x]);
            apply(2*x+2, j-mid, lazy[x]);

            lazy[x] = 0;

        }

        update(i, mid, 2*x + 1, l, r);
        update(mid + 1, j, 2*x + 2, l, r);

        seg_tree[x] = seg_tree[2*x + 1] + seg_tree[2*x + 2];
        sq_sum[x] =  sq_sum[2*x + 1] + sq_sum[2*x + 2];

    }
    int sumCounts(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> last(1e5+1, -1);
        seg_tree.resize(4*n,0);
        lazy.resize(4*n, 0);
        sq_sum.resize(4*n, 0);


        ll ans = 0;

        for(int i = 0; i < n; i++)
        {
            update(0, n - 1, 0, last[nums[i]]+1, i);
            last[nums[i]] = i;
            ans = (ans%mod + sq_sum[0]%mod)%mod;

        }

        return ans;    
        
    }
};