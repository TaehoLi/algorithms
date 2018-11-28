//무방향 무가중치
#include <iostream>
using namespace std;

struct AdjListNode
{
    int data;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode *head;
};

class Graph {
    private:
        int V;
        struct AdjList* array;

    public:
        Graph(int V) {

            this->V = V;
            array = new AdjList[V];
            for (int i = 0; i < V; ++i)
                array[i].head = NULL;
        }

        void DFS(int node) {
            bool *state = new bool[V];
            for (int i = 0; i < V; i++)
                state[i] = false;

            cout << "DFS 방식" << endl;
            runDFS(node, state, array[node].head);
            cout << endl;
        }

        void runDFS(int node, bool state[], AdjListNode* temp) {

            state[node] = true; cout << node << " ";
            while (temp != NULL)
            {
                if (state[temp->data] == false) {
                    runDFS(temp->data, state, array[temp->data].head);
                }
                else
                    temp = temp->next;
            }
        }

        AdjListNode* newAdjListNode(int data) {
            AdjListNode* newNode = new AdjListNode;
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }

        void addEdge(int src, int data ) {
            AdjListNode* newNode = newAdjListNode(data);
            newNode->next = array[src].head;
            array[data].head = newNode;
        }

        void printGraph() {

            for (int i = 0; i < V; ++i) {
                AdjListNode* pCrawl = array[i].head;
                cout << "\n Adjacency list of vertex" << i << "\n head";
                while (pCrawl)
                {
                    cout << "->" << pCrawl->data;
                    pCrawl = pCrawl->next;
                }
                cout << endl;
            }
            cout << "----------------------------" << endl;
        }
};

int main() {

    Graph gh(7);

    gh.addEdge(0, 1);
    gh.printGraph();
    gh.addEdge(0, 3);
    gh.printGraph();
    gh.addEdge(0, 6);
    gh.printGraph();
    gh.addEdge(1, 2);
    gh.printGraph();
    gh.addEdge(1, 4);
    gh.printGraph();
    gh.addEdge(1, 5);
    gh.printGraph();
    gh.addEdge(1, 6);
    gh.printGraph();
    gh.addEdge(3, 4);
    gh.printGraph();
    gh.addEdge(3, 6);
    gh.printGraph();
    gh.addEdge(4, 5);
    gh.printGraph();

    gh.DFS(5);
    return 0;
}
