#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        class Node {
            public:
                string label;
                Node(string label) {
                    this->label = label;
                }
        };

        unordered_map <string, Node*> nodes;
        unordered_map <Node*, list<Node*>> adjList;

        void dfsRec(Node* node, unordered_set<Node *> &visited) {
            cout << node->label << " ";
            visited.insert(node);

            for (auto n: adjList[node]) {
                if (visited.find(n) == visited.end()) {
                    dfsRec(n, visited);
                }
            }
        }
        
        void topoRec(Node * node, stack <Node *> &topo, unordered_set< Node*> &visited) {
            if (visited.find(node) != visited.end()) {
                return;
            }

            visited.insert(node);
            for (auto n : adjList[node]) {
                if (visited.find(n) == visited.end()) {
                    topoRec(n, topo, visited);
                }
            }

            topo.push(node);
        }

        bool cycleRec(Node * node, unordered_set<Node *> &all, unordered_set<Node *> visiting, unordered_set<Node *> visited) {
            all.erase(node);
            visiting.insert(node);

            for (auto n: adjList[node]) {
                if (visited.find(n) != visited.end()) {
                    continue;
                }
                if (visiting.find(n) != visiting.end()) {
                    return true;
                }
                if (cycleRec(n, all, visiting, visited)) {
                    return true;
                }
            }

            visiting.erase(node);
            visited.insert(node);

            return false;
        }

    public:
        void addNode(string);
        void addEdge(string, string);
        void removeEdge(string, string);
        void removeNode(string);
        void print();
        void dfs(string);
        void dfsItr(string);
        void bfs(string);
        vector <string> topoSort();
        bool hasCycle();
};

void Graph :: addNode(string label) {
    Node * node = new Node(label);
    if (nodes.find(label) == nodes.end()) {
        nodes[label] = node;
    }

    if (adjList.find(node) == adjList.end()) {
        list<Node*> nl;
        adjList[node] = nl;
    }
}

void Graph :: addEdge(string from, string to) {
    Node* fromNode = nodes[from];
    if (fromNode == nullptr) {
        return;
    }

    Node* toNode = nodes[to];
    if (toNode == nullptr) {
        return;
    }

    adjList[fromNode].push_back(toNode);
}

void Graph :: removeEdge(string from, string to) {
    Node * fromNode = nodes[from];
    if (fromNode == nullptr) {
        return;
    }

    Node * toNode = nodes[to];
    if (toNode == nullptr) {
        return;
    }

    if (adjList.find(fromNode) != adjList.end()) {
        auto itr = adjList[fromNode].begin();
        while (itr != adjList[fromNode].end()) {
            Node * curr = *itr;
            if (curr == toNode) {
                break;
            }
            ++itr;
        }
        if (itr != adjList[fromNode].end()) {
            adjList[fromNode].erase(itr);
        }
    }
}

void Graph :: removeNode(string label) {
    Node * node = nodes[label];

    if (node != nullptr) {
        
        for (auto source: adjList) {
            Node * curr = source.first;
            removeEdge(curr->label, label);
        }

        nodes.erase(label);
        adjList.erase(node);   
    }
}

void Graph :: print() {
    for (auto source: adjList) {
        list <Node*> edges = source.second;
        if (!edges.empty()) {
            cout << source.first->label << " is connected with [ ";

            for (Node* edge: edges) {
                cout << edge->label << " ";
            }

            cout << "]" << endl;
        }
    }
}

void Graph :: dfs(string source) {
    if (nodes.find(source) != nodes.end()) {
        unordered_set <Node *> visited;
        dfsRec(nodes[source], visited);
    }
}

void Graph :: dfsItr(string source) {
    if (nodes.find(source) == nodes.end()) {
        return;
    }

    unordered_set <Node *> visited;
    stack <Node *> itr;
    itr.push(nodes[source]);

    while (!itr.empty()) {
        Node * curr = itr.top();
        itr.pop();

        cout << curr->label << " ";
        visited.insert(curr);

        for (auto n: adjList[curr]) {
            if (visited.find(n) == visited.end()) {
                itr.push(n);
            }
        }
    }
}

void Graph :: bfs(string source) {
    if (nodes.find(source) == nodes.end()) {
        return;
    }

    queue <Node *> q;
    unordered_set <Node *> visited;
    q.push(nodes[source]);

    while (!q.empty()) {
        Node * node = q.front();
        q.pop();

        if (visited.find(node) == visited.end()) {
            cout << node->label << " ";
            visited.insert(node);
        }

        for (auto n: adjList[node]) {
            if (visited.find(n) == visited.end()) {
                q.push(n);
            }
        }
    }
}

vector <string> Graph :: topoSort() {
    stack <Node *> topo;
    unordered_set <Node *> visited;
    vector <string> ans;

    for (auto node: nodes) {
        topoRec(node.second, topo, visited);
    }

    while (!topo.empty()) {
        ans.push_back(topo.top()->label);
        topo.pop();
    }

    return ans;
}

bool Graph :: hasCycle() {
    unordered_set <Node *> all;
    unordered_set <Node *> visiting;
    unordered_set <Node *> visited;

    for (auto node: nodes) {
        all.insert(node.second);
    }

    while (!all.empty()) {
        Node * node = *all.begin();
        if (cycleRec(node, all, visiting, visited)) {
            return true;
        }
    }

    return false;
}

int main() {

    Graph * graph = new Graph();
    graph->addNode("x");
    graph->addNode("a");
    graph->addNode("b");
    graph->addNode("p");

    graph->addEdge("x", "a");
    graph->addEdge("x", "b");
    graph->addEdge("a", "p");
    graph->addEdge("b", "p");
    graph->addEdge("p", "x");

    cout << graph->hasCycle();

    return 0;
}