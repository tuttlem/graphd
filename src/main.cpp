
#include <iostream>
#include "./common.hpp"
#include "./core/log.hpp"
#include "./core/config.hpp"

#include "./db/graph.hpp"

void printGraph(const graphd::Graph& graph) {
    auto nodes = graph.getNodes();
    auto nodeData = graph.getNodeData();
    auto edges = graph.getEdges();
    auto edgeData = graph.getEdgeData();

    std::cout << "Nodes: " << nodes.size() << std::endl;
    std::cout << "Edges: " << edges.size() << std::endl;

    for (auto node : nodes) {
        std::cout << "Node: " << node.second->toString() << std::endl;
        std::cout << graphd::propertyMapToString(nodeData[node.second->getValue()]) << std::endl;
    }

    for (auto edge : edges) {
        std::cout << "Edge: " << edge.second.first->toString() << " -> " << edge.second.second->toString() << std::endl;
    }

    std::cout << "Done";
}


int main() {
    try {
        auto graph = graphd::Graph();

        auto a = graph.addNode({ {"name", "a"}, {"value", 1} });
        auto b = graph.addNode();
        auto c = graph.addNode();

        auto ab = graph.addEdge(a, b);
        auto bc = graph.addEdge(b, c);
        auto ca = graph.addEdge(c, a);

        printGraph(graph);

        graph.removeNode(b);
        printGraph(graph);

    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << "Bad shit";
    }

    return 0;
}