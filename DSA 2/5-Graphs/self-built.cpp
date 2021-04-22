#include <bits/stdc++.h>

using namespace std;

class Graph {
    private:
        class Node {
            public:
                string label;
                Node(string s) {
                    label = s;
                }
        };

        unordered_map <string, Node *> nodes;
        unordered_map <Node *, list<Node *>> adjList;
        
        void dfsTraverseRec(Node * node, unordered_set<Node *> & visited) {
            if (visited.find(node) == visited.end()) {
                cout << node->label << " ";        
            }
            visited.insert(node);

            for (Node * n: adjList[node]) {
                dfsTraverseRec(n, visited);
            }
        }

        void topoSort(Node * node, unordered_set <Node *> &visited, stack <Node *> &topo) {
            if (visited.find(node) != visited.end()) {
                return;
            }
            visited.insert(node);

            for (Node * n: adjList[node]) {
                topoSort(n, visited, topo);
            }

            topo.push(node);
        }

        bool cycle(Node * node, unordered_set <Node *> &all, unordered_set <Node *> visiting, unordered_set <Node *> visited) {
            all.erase(node);
            visiting.insert(node);

            for (Node * n: adjList[node]) {
                if (visited.find(n) != visited.end()) {
                    continue;
                }
                if (visiting.find(n) != visiting.end()) {
                    return true;
                }
                if (cycle(n, all, visiting, visited)) {
                    return true;
                }
            }

            visiting.erase(node);
            visited.insert(node);
            
            return false;
        }

    public:
        void addNode(string);
        void removeNode(string);
        void addEdge(string, string);
        void removeEdge(string, string);
        void print();
        void dfsRec(string);
        void dfsItr(string);
        void bfs(string);
        vector <string> topologicalSort();
        bool hasCycle();
};

bool Graph::hasCycle() {
    unordered_set <Node *> all;
    unordered_set <Node *> visiting;
    unordered_set <Node *> visited;

    for (auto node: nodes) {
        all.insert(node.second);
    }

    while (!all.empty()) {
        auto itr = all.begin();
        Node * curr = *itr;
        if (cycle(curr, all, visiting, visited)) {
            return true;
        }
    }
    return false;
}

void Graph::addNode(string label) {
    Node * node = new Node(label);
    if (nodes.find(label) == nodes.end()) {
        nodes[label] = node;
    }
    if (adjList.find(node) == adjList.end()) {
        list <Node *> nl;
        adjList[node] = nl;
    }
}

void Graph::removeNode(string label) {
    Node * node;

    if (nodes.find(label) != nodes.end()) {
        node = nodes[label];

        for (auto source: adjList) {
            auto target = source.second;
            Node * curr = source.first;
            removeEdge(curr->label, label);
        }

        nodes.erase(label);
        adjList.erase(node);   
    }
}

void Graph::addEdge(string from, string to) {
    Node * fromNode = nodes[from];
    if (fromNode == nullptr) {
        return;
    }
    Node * toNode = nodes[to];
    if (toNode == nullptr) {
        return;
    }

    adjList[fromNode].push_back(toNode);
}

void Graph::removeEdge(string from, string to) {
    Node * fromNode = nodes[from];
    Node * toNode = nodes[to];
    if (fromNode == nullptr) {
        return;
    }
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

void Graph::print() {
    for (auto source: adjList) {
        auto target = source.second;
        
        if (!target.empty()) {
            cout << source.first->label << " is connected to ";
            for (auto t: target) {
                cout << t->label << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void Graph::dfsRec(string label) {
    if (nodes.find(label) == nodes.end()) {
        return;
    }
    unordered_set <Node *> visited;
    dfsTraverseRec(nodes[label], visited);
}

void Graph::dfsItr(string label) {
    Node * node = nodes[label];
    if (nodes.find(label) == nodes.end()) {
        return;
    }
    
    set <Node *> visited;
    stack <Node *> neighbours;
    neighbours.push(node);

    while (!neighbours.empty()) {
        Node * curr = neighbours.top();
        neighbours.pop();

        if (visited.find(curr) == visited.end()) {
            cout << curr->label << " ";
            visited.insert(curr);
        }
        
        for (Node * n: adjList[curr]) {
            neighbours.push(n);
        }
    }
    
}

void Graph::bfs(string label) {
    Node * node = nodes[label];
    if (nodes.find(label) == nodes.end()) {
        return;
    }

    unordered_set <Node *> visited;
    queue <Node *> trav;
    trav.push(node);
    
    while (!trav.empty()) {
        Node * curr = trav.front();
        trav.pop();

        if (visited.find(curr) != visited.end()) {
            continue;
        }

        cout << curr->label << " ";
        visited.insert(curr);

        for (Node * n: adjList[curr]) {
            if (visited.find(n) == visited.end()) {
                trav.push(n);
            }
        }
    }
}

vector <string> Graph::topologicalSort() {
    
    vector <string> ans;
    unordered_set <Node *> visited;
    stack <Node *> topo;

    for (auto node: nodes) {
        topoSort(node.second, visited, topo);
    }

    while (!topo.empty()) {
        ans.push_back(topo.top()->label);
        topo.pop();
    }

    return ans;
}

int main() {

    Graph * graph = new Graph();
    // graph->addNode("a");
    // graph->addNode("b");
    // graph->addNode("c");
    // graph->addNode("d");
    // graph->addNode("e");

    // graph->addEdge("a", "b");
    // graph->addEdge("a", "e");
    // graph->addEdge("b", "e");
    // graph->addEdge("c", "a");
    // graph->addEdge("c", "b");
    // graph->addEdge("c", "d");
    // graph->addEdge("d", "e");

    // graph->addNode("a");
    // graph->addNode("b");
    // graph->addNode("c");
    // graph->addNode("d");

    // graph->addEdge("a", "b");
    // graph->addEdge("a", "c");
    // graph->addEdge("b", "d");
    // graph->addEdge("d", "c");

    graph->addNode("a");
    graph->addNode("b");
    graph->addNode("p");
    graph->addNode("x");

    graph->addEdge("x", "a");
    graph->addEdge("x", "b");
    graph->addEdge("a", "p");
    graph->addEdge("b", "p");
    graph->addEdge("p", "x");

    cout << graph->hasCycle() << endl;

    // vector <string> sorted;
    // sorted = graph->topologicalSort();
    // for (auto i: sorted) {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}