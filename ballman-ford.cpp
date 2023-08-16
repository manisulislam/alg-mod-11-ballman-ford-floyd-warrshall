#include<bits/stdc++.h>
using namespace std;
//global vertices and edges
 int n, m;
typedef pair<int, int>pii;
//range
const int N =1e3+5;

//infinity range
const int INF=1e9+7;

//adjacency list
vector<pii>adj[N];

//list of edges
vector<pair<pii, int>>list_of_edges;

//distance
int d[N];




//bellman ford implementation
void bellman_ford(int s){
    for(int i=1; i<=n; i++){
        d[i]=INF;
    }
    d[s]=0;

    for(int i=1; i<n; i++){
        //all edges relaxation
        // for(int u=1; u<=n; u++){
        //     for(pii vPair: adj[u]){
        //         int v=vPair.first;
        //         int w=vPair.second;
        //         if(d[u]!=INF && d[v]>d[u]+w){
        //             d[v]=d[u]+w;
        //         }
        //     }
        // }
        for(auto edge: list_of_edges){
            int u=edge.first.first;
            int v=edge.first.second;
            int w=edge.second;
            if(d[u]!=INF && d[v]>d[u]+w){
                     d[v]=d[u]+w;
                 }

            
        }
    }

}
int main(){
   
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        //adj[u].push_back({v,w});
        list_of_edges.push_back({{u,v},w});
    }

    bellman_ford(1);

    for(int i=1; i<=n; i++){
        cout<<"Distance of Node "<<i<<": ";
        cout<<d[i]<<endl;
    }
    
    return 0;
}