#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<int> graph[],int n)
{
    for(int i=1;i<n+1;i++){
        cout << i << " ";
        for(int x: graph[i]){
           cout << "-> " << x << " ";
        }
        cout << endl;
    }
}

void BFS(vector<int> graph[], int V)
{
    int s;
    s = 1;
    list<int> q;
    q.push_back(s);
    bool *visited = new bool[V];
    for(int i=1;i<V+1;i++)
    {
        visited[i]=false;
    }
    visited[s]=true;
    vector<int>::iterator itr;
    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop_front();
        for(itr=graph[s].begin();itr!=graph[s].end();itr++){
            if(visited[*itr]==false){
                visited[*itr]=true;
                q.push_back(*itr);
            }
        }
    }
}


void DFS(vector<int> graph[], int s, bool visited[])
{
    cout << s << " ";
    visited[s] = true;
    vector<int>::iterator itr;
    for(itr=graph[s].begin();itr!=graph[s].end();itr++){
        if(visited[*itr]==false){
            DFS(graph, *itr, visited);
        }
    }

}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> graph[V+1];
    int start, destination;
    for(int i=1;i<E+1;i++)
    {
        cin >> start >> destination;
        graph[start].push_back(destination);
    }

    printGraph(graph, E);
    cout << endl;
    cout << "BFS :" ;
    BFS(graph, V);
    cout << endl;
    bool *visited = new bool[V+1];
    for(int i=1;i<V+1;i++){
        visited[i] = false;
    }
    cout << endl << "DFS : ";
    DFS(graph, 1, visited);
    return 0;
}
