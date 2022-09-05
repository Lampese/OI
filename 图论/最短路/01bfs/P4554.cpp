#include<bits/stdc++.h>
using namespace std;
int dis[505][505],n,m,X1,Y1,X2,Y2,dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
char c[505][505];
bool vis[505][505];
struct _{int x,y;};
void bfs(){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    deque<_>q;
    dis[X1][Y1]=0;
    q.push_back({X1,Y1});
    while(!q.empty()){
        _ u=q.front();
        q.pop_front();
        int x=u.x,y=u.y;
        for(register int i=1;i<=4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>n||ny>m||nx<1||ny<1)continue;
            int w=(c[x][y]!=c[nx][ny]);
            if(dis[nx][ny]>dis[x][y]+w){
                dis[nx][ny]=dis[x][y]+w;
                if(w==0)q.push_front({nx,ny});
                else q.push_back({nx,ny});
            }
        }
    }
}
int main(){
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)return 0;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
               cin>>c[i][j];
        cin>>X1>>Y1>>X2>>Y2;
        ++X1,++Y1,++X2,++Y2;
        bfs();
        cout<<dis[X2][Y2]<<endl;
    }
}