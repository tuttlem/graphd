//
// Created by michael on 3/3/20.
//

#include "graph.hpp"
#include "vertex.hpp"
#include "edge.hpp"

namespace graphd {

    /**
      * Retrieves the current in-memory managed table of vertices
      * @return std::vector<VertexLike*>
      */
    const std::vector<VertexLike*> Graph::getVertexTable(void) {
        std::vector<VertexLike*> vertices;
        std::transform(
                this->_vertexTable.begin(),
                this->_vertexTable.end(),
                vertices.begin(),
                [](std::pair<std::string, std::shared_ptr<VertexLike>> p) -> VertexLike* { return p.second.get(); }
        );

        return vertices;
    }

    /**
     * Retrieves the current in-memory managed table of edges
     * @return std::vector<EdgeLike*>
     */
    const std::vector<EdgeLike*> Graph::getEdgeTable(void) {
        std::vector<EdgeLike*> edges;
        std::transform(
                this->_edgeTable.begin(),
                this->_edgeTable.end(),
                edges.begin(),
                [](std::pair<std::string, std::shared_ptr<EdgeLike>> p) -> EdgeLike* { return p.second.get(); }
        );

        return edges;
    }

    /**
     * Attempts to seek a vertex by its id
     * @return VertexLike*
     */
    const VertexLike* Graph::seekVertexById(const Id* id) {
        auto s = id->toString();
        auto v = this->_vertexTable.find(s);

        if (v == this->_vertexTable.end()) {
            return nullptr;
        }

        return v->second.get();
    }

    /**
     * Creates a new vertex and makes it available to be attached to
     * within the graph
     * @return Id*
     */
    const Id* Graph::addVertex(void) {
        auto vertex = std::make_shared<Vertex>();
        auto id = vertex->getId();
        auto s = id->toString();

        if (this->_vertexTable.find(s) != this->_vertexTable.end()) {
            // todo: throw an exception here!
        }

        this->_vertexTable[s] = vertex;
        return vertex->getId();
    }

    /**
     * Retrieves the current in-memory managed table of edges
     * @return EdgeLike*
     */
    const EdgeLike* Graph::seekEdgeById(const Id* id) {
        auto s = id->toString();
        auto v = this->_edgeTable.find(s);

        if (v == this->_edgeTable.end()) {
            return nullptr;
        }

        return v->second.get();
    }

    /**
     * Creates a new edge between two nodes and adds it to the graph
     * @return Id*
     */
    const Id* Graph::addEdge(const Id* a, const Id* b) {
        auto edge = std::make_shared<Edge>();
        auto id = edge->getId();
        auto s = id->toString();

        if (this->_edgeTable.find(s) != this->_edgeTable.end()) {
            // todo: throw an exception here!
        }

        this->_edgeTable[s] = edge;
        return edge->getId();
    }

}