#include<bits/stdc++.h>
using namespace std;

vector<int>G[1010];
bool vis[1010];

void dfs(int s){

   vis[s]=1;
   for(int i=0;i<G[s].size();i++){

      int node=G[s][i];

      if(vis[node]==0)

        dfs(node);
   }

}


int main(){

    int t;cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int node,edge;cin>>node>>edge;
        for(int i=0;i<edge;i++){
            int u,v;cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int cnt=0;

        for(int i=1;i<=node;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i);
            }
        }
        cout<<cnt<<"\n";
        for(int i=0;i<1010;i++)G[i].clear();
    }
return 0;
}
