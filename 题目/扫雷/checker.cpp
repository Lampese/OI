#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int _map[105][105],fcnt;
bitset<105>vis[105],flag[105];
int main(int argc,char* argv[]){
    setName("BOOM");
    registerInteraction(argc,argv);
    int opt,x,y,done(0),error(0);
    srand(time(0));
    summon();
    for(register int i=1;i<=16;++i)
        for(register int j=1;j<=30;++j){
            if(_map[i][j]==9)continue;
            else _map[i][j]=find(i,j);
        }
    while(true){
        if(done==99)quit(_ok,"You AK IOI!");
        cin>>opt>>x>>y;
        if(opt==1){
            if(vis[x][y])quit(_wa,"Ask repeat!");
            if(flag[x][y])quit(_wa,"Why ask flag?");
            if(_map[x][y]==9){
                ++error;
                if(error>9)quit(_wa,"Boom!");
                cout<<-1<<endl;
                continue;
            }
            vis[x][y]=1;
            cout<<_map[x][y];
        }else if(opt==2){
            if(fcnt>99)quit(_wa,"Do you want to hack?");
            if(vis[x][y])quit(_wa,"Here no boom!");
            if(flag[x][y])quit(_wa,"Flag repeat!");
            flag[x][y]=1;
            ++fcnt;
            if(_map[x][y]==9){
                ++done;
                continue;
            }
        }else{  
            if(vis[x][y])quit(_wa,"How to cancel?");
            if(!flag[x][y])quit(_wa,"Here no Flag!");
            flag[x][y]=0;
            --fcnt;
            if(_map[x][y]==9)--done;
        }
    }
}