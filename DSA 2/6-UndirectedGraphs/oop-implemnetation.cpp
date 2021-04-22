#include <bits/stdc++.h>

using namespace std;

class WeightedGraph {
    class Node {
        public:
            string label;
            Node(string val) {
                label = val;
            }
    };

    class Edge {
        public:
            Node * from;
            Node * to;
            int weight;
            Edge(Node * f, Node * t, int w) {
                from = f;
                to = t;
                weight = w;
            }
    };

    unordered_map <string, Node *> nodes;
    unordered_map <Node *, list<Edge *>> adjList;

    public:
        void addNode(string);
        void addEdge(string, string, int);
        void print();
};

void WeightedGraph::addNode(string label) {
    Node * node = new Node(label);
    if (nodes.find(label) == nodes.end()) {
        nodes[label] = node;
    }
    if (adjList.find(node) == adjList.end()) {
        list <Edge *> nl;
        adjList[node] = nl;
    }
}

void WeightedGraph::addEdge(string from, string to, int weight) {
    if (nodes.find(from) == nodes.end()) {
        return;
    }
    if (nodes.find(to) == nodes.end()) {
        return;
    }
    Node * fromNode = nodes[from];
    Node * toNode = nodes[to];
    
    adjList[fromNode].push_back(new Edge(fromNode, toNode, weight));   
    adjList[toNode].push_back(new Edge(toNode, fromNode, weight));  
}

void WeightedGraph::print() {
    for (auto source: adjList) {
        auto target = source.second;
        
        if (!target.empty()) {
            for (Edge * t: target) {
                cout << source.first->label << " is connected to ";
                cout << t->to->label << " with weight " << t->weight << endl;
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    WeightedGraph * graph = new WeightedGraph();
    graph->addNode("A");
    graph->addNode("B");
    graph->addNode("C");

    graph->addEdge("A", "B", 3);
    graph->addEdge("A", "C", 2);
    graph->print();

    return 0;
}