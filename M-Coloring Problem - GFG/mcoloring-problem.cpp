// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isPossible(bool graph[101][101],int node,int n,vector<int>&color,int colorNumber){
    
    for(int i=0;i<n;i++)
    {
        if(graph[node][i]==true && color[i]==colorNumber)
        return false;
    }
    
    return true;
}

bool graphColor(bool graph[101][101],int node,vector<int>&color,int n,int m){
    
    if(node==n)
    return true;
    
    for(int colorNumber=1;colorNumber<=m;colorNumber++){
        if(isPossible(graph,node,n,color,colorNumber)){
            
            color[node]=colorNumber;
            bool possible=graphColor(graph,node+1,color,n,m);
            
            if(possible)
            return true;
            
            
            color[node]=0;
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<int>color(n,0);
    
    return graphColor(graph,0,color,n,m);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends