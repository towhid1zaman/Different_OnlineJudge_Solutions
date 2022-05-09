#include <bits/stdc++.h>
using namespace std;

int pipes[1001][1001];
int visit[1001][1001];
int n, m, X, Y, L;

struct node{
  int x, y, l;  
};

node Q[1000000];

int front, back;
void init(){
    front = back = 0;
}
void push(node temp){
    Q[back++] = temp;
}

node pop(){
    return Q[front++];
}

bool empty(){
    return (front == back);
}
bool valid(int x, int y){
    return (x < n and y < m and x>=0 and y>=0);
}

bool left(int x, int y){
    return (pipes[x][y] == 1 or pipes[x][y] == 3 or pipes[x][y] == 6 or pipes[x][y] == 7);
}
bool right(int x, int y){
    return (pipes[x][y] == 1 or pipes[x][y] == 3 or pipes[x][y] == 4 or pipes[x][y] == 5);
}
bool up(int x, int y){
    return (pipes[x][y] == 1 or pipes[x][y] == 2 or pipes[x][y] == 4 or pipes[x][y] == 7);
}
bool down(int x, int y){
    return (pipes[x][y] == 1 or pipes[x][y] == 2 or pipes[x][y] == 5 or pipes[x][y] == 6);
}

int bfs(int sx, int sy, int l){
    push({sx, sy, l});
    visit[sx][sy] = 1;
    int ans = 0;
    while(!empty()){
        node cur = pop();
        int x = cur.x, y = cur.y, l = cur.l;
        if(l == 0)continue;
        ans ++;
        
        //left y - 1
        if(valid(x, y-1) and left(x, y) and right (x, y-1) and !visit[x][y-1]){
            push({x, y-1, l-1});
            visit[x][y-1] = 1;
        }
        //right y + 1
        if(valid(x, y+1) and right(x, y) and left(x, y+1) and !visit[x][y+1]){
            push({x, y+1, l-1});
            visit[x][y+1] = 1;
        }
        //up x - 1
        if(valid(x-1, y) and up(x, y) and down(x-1, y) and !visit[x-1][y]){
            push({x-1, y, l-1});
            visit[x-1][y] = 1;
        }
        //down x+1
        if(valid(x+1, y) and down(x, y) and up(x+1, y) and !visit[x+1][y]){
            push({x+1, y, l-1});
            visit[x+1][y] = 1;
        }
    }
    return ans;
}

void solve(){
    cin >> n >> m >> X >> Y >> L;
    
    for(int i = 0; i<n; i++){
        for(int j = 0;j<m; j++){
            cin >> pipes[i][j];
            visit[i][j] = 0;
        }
    }
    init();
    
    if(pipes[X][Y]>0){
        cout << bfs(X, Y, L) << endl;
    }
    else cout << 0 << endl; 
    
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
