#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

 
bool check(std::vector<int> a, int c, int minD){
    int cnt = 1;
    int last = a[0];
    for(int i = 1; i<a.size(); i++){
        if(a[i] - last >= minD){
            last = a[i];
            cnt++;
        }
        if(cnt == c)return true;
    }
    return false;
}
 
int main(){
    
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        std::vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll r = a[0] + a[n-1] + 1;
        ll l = 0;
        while(r-l > 0){
            ll mid = (r+l+1)/2;
            if(check(a, c, mid)){
                l = mid;
            }
            else r = mid - 1;
        }
        cout << l << endl;
    }
return 0;
}
 
