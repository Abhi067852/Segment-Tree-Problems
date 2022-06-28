#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define endl '\n'
#define ll       long long int
#define ld              long double
#define pb              push_back
#define P               pair<int,int>
#define F               first
#define S               second
#define inf             3e18
#define vi              vector<int>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MAXN            4e5+2
#define modu            1e9+7
// ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
// ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
// ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

// //1.DP se soch
// //2.DP se soch
// //3.DP se soch
// //graph, gcd, BS, seive
// //if NOTA,then
// //brute force hi optimal h
template<typename T>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ll ceil(ll a, ll b){
//     ll c=(a+b-1)/b;
//     return c;
// }

ll gcd(ll a , ll b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

/*ll NCR(ll n , ll r){
    n=fact[n];
    
    ll a=fact[r] , b=fact[n-r];
    a=power_mod(a,mod-2);
    b=power_mod(b , mod-2);
    a=(a*b)%mod;
    n=(n*a)%mod;
    return n;
 
}*/
void help(vector<int> &bit , int index , int k){
    while(index <bit.size()){
        bit[index]+=k;
        index+=(index&(-index));
    }
}
int quer(vector<int> &bit  , int index){
    int ans=0;
    while(index){
        ans+=bit[index];
        index-=(index &(-index));
    }
    return ans;
}
int query(vector<int> &bit , int a , int b){
    int ans=quer(bit ,b)-quer(bit ,a-1);
    return ans;
}
int ans=0;
const int mx = 1000006;

 
struct State {
    public:
        int pairs, eopen, eclose;
 
        State() {pairs = eopen = eclose = 0;}
} seg[5 * mx];

string s;
State combine(State a,State b)
{
    State res;
    res.pairs=a.pairs+b.pairs+min(a.eopen,b.eclose);
    res.eclose=a.eclose+b.eclose-min(a.eopen,b.eclose);
    res.eopen=a.eopen+b.eopen-min(a.eopen,b.eclose);
    return res;
}
void build(int ind,int l,int h)
{
    if(l==h)
    {
        if(s[l]=='(')
        {
            ++seg[ind].eopen;
        }
        else
        {
           ++seg[ind].eclose;
        }
        
        return;
    }
    int mid=(l+h)/2;
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,h);
 seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
  
    return;
}
State query(int ind,int l,int r,int low,int high)
{
    
    if(l == low && r == high) return seg[ind];
    int m = (l + r) / 2;
    if(high <= m) return query(2 * ind + 1, l, m, low, high);
    else if(low > m) return query(2 * ind + 2, m + 1, r, low, high);
    return combine(query(2 * ind + 1, l, m, low, m), query(2 * ind + 2, m + 1, r, m + 1, high));
}

void solve()
{
    
    cin>>s;
    // seg.resize(4*s.size(),vector<int>(3,0));
    build(0,0,s.size()-1);
    int q;
    cin>>q;
    // cout<<seg[0].pairs;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        // cout<<l<<r<<" ";
        State ans=query(0,0,s.size()-1,l,r);
        cout<<ans.pairs*2<<endl;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    
    return 0;
}
