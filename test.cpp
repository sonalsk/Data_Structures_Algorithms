#include <bits/stdc++.h>

using namespace std;

class WeightedGraph {
    class Node {
        public:
            int label;
            Node (int val) {
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

    unordered_map <int, Node *> nodes;
    unordered_map <Node *, list<Edge *>> adjList;

    public:
        void addNode(int);
        void addEdge(int, int, int);
        int dktraDist(int, int);
};

int WeightedGraph::dktraDist(int from, int to) {
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
        Node * curr = bfs.top().node; bfs.pop();
        visited.insert(curr);

        for (Edge * edge: adjList[curr]) {
            if (visited.find(edge->to) == visited.end()) {
                if (edge->weight + distances[curr] < distances[edge->to]) {
                    distances[edge->to] = edge->weight + distances[curr];
                    bfs.push({edge->to, distances[edge->to]});
                }
            }
        }
    }

    return distances[toNode];
}

void WeightedGraph::addNode(int label) {
    Node * node = new Node(label);
    if (nodes.find(label) == nodes.end()) {
        nodes[label] = node;
    }
    if (adjList.find(node) == adjList.end()) {
        list <Edge *> nl;
        adjList[node] = nl;
    }
}

void WeightedGraph::addEdge(int from, int to, int weight) {
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

int main() {
    WeightedGraph * graph = new WeightedGraph();
    int n, m;
    cin >> n >> m;

    for (int i = 1; i<= n; i++) {
        graph->addNode(i);
    }
    
    int s, t;
    cin >> s >> t;

    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> w;
        graph->addEdge(v1, v2, w);
    }

    int minPath = graph->dktraDist(s, t);
    cout << minPath << endl;

    return 0;
}