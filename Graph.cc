#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>

using namespace std;

typedef struct node
{
    int b;
    int weightOfNode;
}node;

class Graph
{
   public:
            Graph(int aInVertices)
            {
                vertices = aInVertices;
                adjacencyList = new vector<int>[aInVertices];
                parent = new int[aInVertices];

                for(int i =0;i<aInVertices;i++)
                    parent[i] = -1;
            }

            virtual ~Graph()
            {
                delete[] adjacencyList;
                delete[] parent;
            }

            void BFS(int aInStartNode);
            void DFS(int aInStartNode);
            void DFSUtil(int aInStartNode, bool *visited);
            void addEdge(int aInStartNode, int aInEndNode);
            void findPath(int aInStartNode, int aInEndNode);
            void ClearParent();

    private:
            vector<int>* adjacencyList;
            int vertices;
            int* parent;

};

void Graph::ClearParent()
{
    for(int i =0;i<vertices;i++)
        parent[i] = -1;

}

void Graph::DFSUtil(int aInStartNode, bool *visited)
{

   visited[aInStartNode] = true;
   cout<<aInStartNode<< " ";

   vector<int>::iterator it;
   for(it = adjacencyList[aInStartNode].begin(); it != adjacencyList[aInStartNode].end();it++) {
        if(!visited[*it]) {
            parent[*it] = aInStartNode;
            DFSUtil(*it, visited);
        }
   }
}

void Graph::DFS(int aInStartNode)
{
   bool * visited;
   visited = new bool[vertices];

   for(int i =0;i<vertices;i++) {
        visited[i] = false;
   }

   cout<<"DFS: ";
   DFSUtil(aInStartNode, visited);
}

void Graph::BFS(int aInStartNode)
{
    queue<int> q;
    bool *visited;

    visited = new bool[vertices];

    for(int i =0;i<vertices;i++)
        visited[i] = false;

    visited[aInStartNode] = true;
    q.push(aInStartNode);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout<<v<< " ";

        // add all the edge nodes for v
        vector<int>::iterator it = adjacencyList[v].begin();
        while(it != adjacencyList[v].end()) {
            if(visited[*it] != true) {
                visited[*it] = true;
                parent[*it] = v;
                q.push(*it);
            }

            it++;
        }
    }
}


void Graph::addEdge(int aInStartNode, int aInEndNode)
{
    adjacencyList[aInStartNode].push_back(aInEndNode);
    adjacencyList[aInEndNode].push_back(aInStartNode);
}

void Graph::findPath(int aInStartNode, int aInEndNode)
{
    stack<int> st;
    int end = aInEndNode;
    st.push(aInEndNode);

    while(parent[aInEndNode] != -1) {
        st.push(parent[aInEndNode]);
        aInEndNode = parent[aInEndNode];
    }

    if(st.size() == 1) {
        cout<<" No path from "<<aInStartNode<<" to "<<end<<endl;
        return;

    }
    cout<<endl<<"Path from "<<aInStartNode<<" to "<<end;
    while(!st.empty()) {
        cout<<endl<<st.top()<<endl;
        st.pop();
    }

}

int main()
{
    Graph g(5);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(2,3);
    g.BFS(1);
    g.findPath(1,0);

    g.ClearParent();
    g.DFS(0);
    g.findPath(0,4);
    cout<<endl;

    return 0;
}
