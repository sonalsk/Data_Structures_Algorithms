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

    struct Order {
        Node * node;
        int distance;
    };

    struct Compare {
        bool operator()(Order first, Order second) {
            if (first.distance > second.distance) {
                return true;
            }
            return false;
        }
    };

    struct CompareEdge {
        bool operator()(Edge first, Edge second) {
            if (first.weight > second.weight) {
                return true;
            }
            return false;
        }
    };

    unordered_map <string, Node *> nodes;
    unordered_map <Node *, list<Edge *>> adjList;

    bool findCycle(Node * node, Node * parent, unordered_set <Node *> visited) {
        visited.insert(node);

        for (auto edge: adjList[node]) {
            if (parent == edge->to) {
                continue;
            }
            if (visited.find(edge->to) != visited.end() ) {
                return true;
            }        
            if (findCycle(edge->to, node, visited)) {
                return true;
            }
        }

        return false;
    }

    Node * findParent(unordered_map <Node *, Node *> parent, Node * i) {
        if (parent[i] == nullptr) {
            return i;
        }
        return findParent(parent, parent[i]);
    }

    public:
        void addNode(string);
        void addEdge(string, string, int);
        void print();
        void Dijkstra(string, string);
        int dktraDist(string, string);
        vector <string> dktraPath(string, string);
        bool hasCycle();
        bool containsNode(string);
        WeightedGraph * prims();
        bool UnionFind();
        WeightedGraph * kruskal();
};

bool WeightedGraph::UnionFind() {
    unordered_map <Node *, Node *> parent;

    for (auto node: nodes) {
        parent[node.second] = nullptr;
    }

    for (auto node: nodes) {
        for (auto edge: adjList[node.second]) {
            Node * x = findParent(parent, edge->from);
            Node * y = findParent(parent, edge->to);
            
            if (x == y) {
                return true;
            }

            parent[y] = x;
        }
    }
    return false;
}

bool WeightedGraph::containsNode(string label) {
    return nodes.find(label) != nodes.end();
}

WeightedGraph * WeightedGraph::kruskal() {
    WeightedGraph * tree = new WeightedGraph();
    if (nodes.empty()) {
        return tree;
    }

    unordered_map <Node *, Node *> parent;

    for (auto node: nodes) {
        parent[node.second] = nullptr;
    }

    for (auto node: nodes) {
        for (auto edge: adjList[node.second]) {
            Node * x = findParent(parent, edge->from);
            Node * y = findParent(parent, edge->to);

            if (!tree->containsNode(x->label)) {
                tree->addNode(x->label);
            }
            if (!tree->containsNode(y->label)) {
                tree->addNode(y->label);
            }
            
            if (x == y) {
                continue;
            }
            else {
                tree->addEdge(x->label, y->label, edge->weight);
            }

            parent[y] = x;
        }
    }
    return tree;
}

WeightedGraph * WeightedGraph::prims() {

    WeightedGraph * tree = new WeightedGraph();
    if (nodes.empty()) {
        return tree;
    }

    priority_queue <Edge, vector <Edge>, CompareEdge> edges;

    auto itr = nodes.begin();
    Node * startNode = itr->second;
    for (Edge * edge: adjList[startNode]) {
        edges.push({edge->from, edge->to, edge->weight});
    }
    tree->addNode(startNode->label);

    if (edges.empty()) {
        return tree;
    }

    while (tree->nodes.size() < nodes.size()) {
        auto minEdge = edges.top(); edges.pop();
        auto nextNode = minEdge.to;

        if (tree->containsNode(nextNode->label)) {
            continue;
        }

        tree->addNode(nextNode->label);
        tree->addEdge(minEdge.from->label, nextNode->label, minEdge.weight);

        for (auto edge: adjList[nextNode]) {
            if (!tree->containsNode(edge->to->label)) {
                edges.push({edge->from, edge->to, edge->weight});
            }
        }
    }

    return tree;
}

bool WeightedGraph::hasCycle() {
    unordered_set <Node *> visited;
    for (auto node: nodes) {
        if (visited.find(node.second) == visited.end()) {
            if (findCycle(node.second, nullptr, visited)) {
                return true;
            }
        }
    }
    return false;
}

vector <string> WeightedGraph::dktraPath(string from, string to) {
    vector <string> path;
    
    if (nodes.find(from) == nodes.end()) return path;
    if (nodes.find(to) == nodes.end()) return path;
    Node * fromNode = nodes[from];
    Node * toNode = nodes[to];

    unordered_map <Node *, int> distances;
    for (auto node: nodes) {
        distances[node.second] = INT_MAX;
    }
    distances[fromNode] = 0;

    unordered_set <Node *> visited;
    priority_queue <Order, vector <Order>, Compare> bfs;
    bfs.push({fromNode, 0});

    unordered_map <Node *, Node *> previousNode;
    
    while (!bfs.empty()) {
        Node * current = bfs.top().node; bfs.pop();
        visited.insert(current);
    
        for (Edge * edge: adjList[current]) {
            if (visited.find(edge->to) == visited.end()) {
                if (edge->weight + distances[current] < distances[edge->to]) {
                    distances[edge->to] = edge->weight + distances[current];
                    previousNode[edge->to] = current;
                    bfs.push({edge->to, distances[edge->to]});
                }                
            }
        }
    }

    stack <Node *> p;
    p.push(toNode);    
    Node * prev = previousNode[toNode];

    while (prev != nullptr) {
        p.push(prev);
        prev = previousNode[prev];
    }

    while (!p.empty()) {
        path.push_back(p.top()->label);
        p.pop();
    }
    return path;
}

int WeightedGraph::dktraDist(string from, string to) {
    // validate
    if (nodes.find(from) == nodes.end()) return -1;
    if (nodes.find(to) == nodes.end()) return -1;
    Node * fromNode = nodes[from];
    Node * toNode = nodes[to];

    // initialise distances with max value
    unordered_map <Node *, int> distances;
    for (auto node: nodes) {
        distances[node.second] = INT_MAX;
    }
    distances[fromNode] = 0;

    // bfs on nodes
    unordered_set <Node *> visited;
    priority_queue <Order, vector <Order>, Compare> bfs;
    bfs.push({fromNode, 0});
    
    while (!bfs.empty()) {
        Node * current = bfs.top().node; bfs.pop();
        visited.insert(current);
    
        for (Edge * edge: adjList[current]) {
            if (visited.find(edge->to) == visited.end()) {
                if (edge->weight + distances[current] < distances[edge->to]) {
                    distances[edge->to] = edge->weight + distances[current];
                    bfs.push({edge->to, distances[edge->to]});
                }                
            }
        }
    }
    return distances[toNode];
}

void WeightedGraph::Dijkstra(string from, string to) {
    if (nodes.find(from) == nodes.end()) return;
    if (nodes.find(to) == nodes.end()) return;

    Node * fromNode = nodes[from];
    Node * toNode = nodes[to];

    unordered_map <Node *, int> distances;
    unordered_map <Node *, Node *> previousNode;
    unordered_set <Node *> visited;
    
    priority_queue <Order, vector <Order>, Compare> bfs;

    bfs.push({fromNode, 0});

    while (!bfs.empty()) {
        Node * fromNode = bfs.top().node; bfs.pop();
        visited.insert(fromNode);
    
        for (Edge * edge: adjList[fromNode]) {

            if (visited.find(edge->to) == visited.end()) {
                if (distances.find(edge->to) != distances.end()) {
                    if (edge->weight + distances[fromNode] < distances[edge->to]) {
                        distances[edge->to] = edge->weight + distances[fromNode];
                        previousNode[edge->to] = fromNode;
                    }
                }
                else {
                    distances[edge->to] = edge->weight;
                    previousNode[edge->to] = fromNode;
                }
                bfs.push({edge->to, distances[edge->to]});
            }
        }
    }
    cout << distances[toNode] << endl;
}

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
    graph->addEdge("B", "C", 4);
    graph->addEdge("A", "C", 5);

    WeightedGraph * tree = graph->kruskal();
    tree->print();

    return 0;
}