#include<bits/stdc++.h>
#define Pair pair<int,int>
using namespace std;
vector<Pair> G[510];
priority_queue<Pair,vector<Pair>,greater<Pair> >Q;
int dist[510];

void Dijkstra(int src,int w){
   Q.push(make_pair(src,w));
   dist[src]=0;///w=0;
   while(!Q.empty()){
       Pair u;///node with cost
       u=Q.top();
       Q.pop();

       for(int i=0;i<G[u.first].size();i++){
         Pair v=G[u.first][i];
         int cost=v.second;
         if((dist[u.first]+cost)<dist[v.first]){
            dist[v.first]=dist[u.first]+cost;
            Q.push(make_pair(v.first,dist[v.first]));
         }
       }
    }
}


int main(){
   int t;scanf("%d",&t);
   for(int kase=1;kase<=t;kase++){
      int nodes,edges;scanf("%d%d",&nodes,&edges);
      for(int i=1;i<=nodes;i++)dist[i]=INT_MAX;
      memset(visited,0,sizeof(visited));
      for(int i=1;i<=edges;i++){
          int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
          G[u].push_back(make_pair(v,cost));
          G[v].push_back(make_pair(u,cost));
      }int src;scanf("%d",&src);
    Dijkstra(src,0);

    for(int i=0;i<=nodes;i++)
        printf("%d-->%d\n",i,dist[i]);
    }



return 0;
}
