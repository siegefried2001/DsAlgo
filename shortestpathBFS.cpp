#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
#define ll long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(i,a,n) for(int i=a;i<n;i++)
#define repD(i,a,n) for(int i=a;i>=n;i--)
bool shortestpath(int s,int e,int n,int **edges,map<int,int> &m){
    if(s==e){
        return true;
    }
    queue<int> nodes;
    bool *visited=new bool[n];
    rep(i,n){
        visited[i]=false;
    }
    visited[s]=true;
    nodes.push(s);
    while(!nodes.empty()){
        int curr=nodes.front();
        rep(i,n){
            if(!visited[i] && edges[curr][i]){
                nodes.push(i);visited[i]=true;
                m[i]=curr;
                if(i==e)
                    return true;  
            }
        }
        nodes.pop();
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;cin>>n>>e;
    map<int, int> m;
    int ** edges=new int *[n];
    rep(i,n){
        edges[i]=new int[n];
        rep(j,n) edges[i][j]=0;
    }
    rep(i,e){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int a,b;cin>>a>>b;
    if(shortestpath(a,b,n,edges,m)){
        int curr=b;
        cout<<b<<" ";
        while(curr!=a){
            cout<<m[curr]<<" ";
            curr=m[curr];
        }
    }
}