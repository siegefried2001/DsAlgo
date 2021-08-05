#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
#define ll long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(i,a,n) for(int i=a;i<n;i++)
#define repD(i,a,n) for(int i=a;i>=n;i--)

void printBFS(int s,int n,int **edges,bool* visited){
    queue<int> nodes;
    visited[s]=true;
	nodes.push(s);
    // cout<<s<<" ";
    while(!nodes.empty()){
        int curr=nodes.front();
        cout<<curr<<" ";
        rep(i,n){
            if(edges[curr][i]==1 && !visited[i]){
            	nodes.push(i);
            	visited[i]=true;
        	}
        }
        nodes.pop();
    }
}
void printDFS(int s,int n,int **edges,bool* visited){
	if(visited[s])
		return;
	visited[s]=true;
	cout<<s<<" ";
	rep(i,n){
		if(edges[s][i])
			printDFS(i,n,edges,visited);
	}
}
void BFS(int s,int n,int **edges){
	bool* visited=new bool[n];
	rep(i,n) visited[i]=false;
	rep(i,n){
		if(visited[i])
			continue;
		printBFS(i,n,edges,visited);
	}
	delete []visited;
}
void DFS(int s,int n,int **edges){
	bool* visited=new bool[n];
	rep(i,n) visited[i]=false;
	rep(i,n){
		if(visited[i])
			continue;
		printDFS(i,n,edges,visited);
	}
	delete []visited;
}
int main()
{
	ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // int t;
    // cin >> t;
    int n,e;
	cin>>n>>e;
    int ** edges=new int*[n];
    rep(i,n){
    	edges[i]=new int[n];
    	rep(j,n){
    		edges[i][j]=0;
    	}
    }
    rep(i,e){
    	int x,y;
    	cin>>x>>y;
    	edges[x][y]=1;
    	edges[y][x]=1;
    }
    cout<<"BFS"<<endl;
    BFS(0,n,edges);cout<<endl;
    cout<<"DFS"<<endl;
    DFS(0,n,edges);cout<<endl;
    return 0;
}