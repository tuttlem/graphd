
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
        std::cout << "Node: " << node.second->toString() << " ";
        std::cout << graphd::propertyMapToString(nodeData[node.second->getValue()]) << std::endl;
    }

    for (auto edge : edges) {
        std::cout << "Edge: " << graphd::Id::fromValue(edge.first)->toString();
        std::cout << " (" << edge.second.first->toString() << " -> " << edge.second.second->toString() << ")" << std::endl;
    }

    std::cout << std::endl;
}

struct make_string_functor {
    std::string operator()(const std::string &x) const { return x; }
    std::string operator()(int x) const { return std::to_string(x); }
};


int main() {
    try {
        auto graph = graphd::Graph();

        auto frank = graph.addNode({{"type", "person"}, {"name", "Frank"}});
        auto fay = graph.addNode({{"type", "person"}, {"name", "Fay"}});
        auto stan = graph.addNode({{"type", "person"}, {"name", "Stan"}});
        auto ethel = graph.addNode({{"type", "person"}, {"name", "Ethel"}});
        auto dad = graph.addNode({{"type", "person"}, {"name", "Neil"}});
        auto mum = graph.addNode({{"type", "person"}, {"name", "Andrea"}});
        auto ryan = graph.addNode({{"type", "person"}, {"name", "Ryan"}});
        auto me = graph.addNode({{"type", "person"}, {"name", "Michael"}});

        graph.addEdge(dad, mum, {{"type", "married"}});
        graph.addEdge(dad, ryan, {{"type", "father"}});
        graph.addEdge(dad, me, {{"type", "father"}});
        graph.addEdge(mum, ryan, {{"type", "mother"}});
        graph.addEdge(mum, me, {{"type", "mother"}});

        printGraph(graph);

        auto adjacentNodes = graph.getAdjacentNodes(dad);

        for (auto node : adjacentNodes) {
            std::cout << node->toString() << std::endl;
        }

        auto adjacentEdges = graph.getAdjacentEdges(dad);

        for (auto edge : adjacentEdges) {
            std::cout << edge->toString() << std::endl;
        }

        std::cout << std::endl;


        auto path = graph.findPath(frank, me);

        for (auto edge : path) {
            std::cout << edge->toString() << " " << std::endl;
        }

    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << e.what();
    }

    return 0;
}