#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int checkgap(std::vector<int> v, int gap, int c){
    int last = v[0];
    int cnt = 1;
    for(int i = 1; i<v.size(); i++){
        if(v[i] - last >= gap){
            last = v[i];
            cnt++;
            if(cnt == c)return 1;
        }
    }
    return 0;
}

void task(){
   int n, c; cin >> n >> c;
   std::vector<int> a(n);
   for(int i = 0; i<n; i++){
    cin >> a[i];
   }
   int ans = 0;
   sort(a.begin(), a.end());
   int low = 1, high = a[0] + a[n-1] + 1;
   while(low <= high){
    int gap = (low + high)/2;
    if(checkgap(a, gap, c)){
        ans = max(ans, gap);
        low = gap+1;
    }
    else high = gap - 1;
   }
   cout << ans << endl;
}
 
int main(){
    //ctrl+alt+b
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": "<<endl;
        task();
    }
      
return 0;
}
