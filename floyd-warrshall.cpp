#include<bits/stdc++.h>
using namespace std;
//global vertices and edges
int n,m;

//range 
const int N=1e3+5;

//infinity range
const int INF=1e9+7;

//adjacency matrix
int d[N][N];

//dist initialize
void dist_initialize(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i!=j) d[i][j]=INF;
            
        }
    }

}
void print_matrix(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout<<"X ";
            else cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    
    cin>>n>>m;

    //distance initialize
    dist_initialize();
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
        d[v][u]=w;
    }

    print_matrix();
    //floyd warrshall implementation
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    cout<<"After apply floyd warshall"<<endl<<endl;
    print_matrix();
    
    
    return 0;
}