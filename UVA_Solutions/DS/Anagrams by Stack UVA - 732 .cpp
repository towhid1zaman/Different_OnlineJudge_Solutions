
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()

#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;
/*
 *given two string , first input and second one is target.
 *we have to print some valid operations(means permutaions) that each line
 *of operations can generate target string from input string.
 *if two string isn't equal after sorting , then its not possible 
 *to generate any valid operations.
 *backtracking ?
*/

bool isEqual(string a, string b){
	sort(all(a));
	sort(all(b));
	return a==b;
}
string input, target;
void dfs(string a, string b, string stack,string path,int n){
	if(n == input.length()*2){
		if(b == target)cout << path << endl;
		return;
	}

	// push
	if(a.length()>0){
	 //path = path + (n==0 ? "i" : " i");
	 //a = a.substr(1,a.length()-1);
	// stack = stack+a[0];
	 dfs(a.substr(1,a.length()-1),b,stack+a[0],path + (n==0 ? "i" : " i"),n+1);
	}

	//pop
	bool criteriaForPop = (stack.length() > 0 and stack[stack.length()-1] == target[b.length()]);
	if(criteriaForPop){
		//path = path+" o";
		//b = b+stack[stack.length()-1];
		//stack = stack.substr(0, stack.length()-1);
		dfs(a,b+stack[stack.length()-1],stack.substr(0, stack.length()-1), path+" o",n+1);
	}
}

void task(){
        while( cin >> input ){
        	if(input.empty()){
        		break;
        	}
        	cin >> target;
        	cout << '[' << endl;
        	if(isEqual(input,target)){
        		dfs(input,"","","",0);
        	}
        	cout << ']' << endl;
        }
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; //cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


