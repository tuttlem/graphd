//
// Created by michael on 3/3/20.
//

#ifndef GRAPHD_GRAPH_HPP
#define GRAPHD_GRAPH_HPP

#include "../common.hpp"
#include "types/interfaces.hpp"

namespace graphd {

    /**
     * The graph data structure implementation
     */
    class Graph : public GraphLike {
    private:
        std::map<std::string, std::shared_ptr<VertexLike>> _vertexTable;
        std::map<std::string, std::shared_ptr<EdgeLike>> _edgeTable;

    public:
        /**
         * Default constructor
         */
        Graph(void) { }

        Graph(const Graph&) = delete;
        Graph(Graph&&) = delete;

        virtual ~Graph(void) = default;

        /**
          * Retrieves the current in-memory managed table of vertices
          * @return std::vector<VertexLike*>
          */
        const std::vector<VertexLike*> getVertexTable(void);

        /**
         * Retrieves the current in-memory managed table of edges
         * @return std::vector<EdgeLike*>
         */
        const std::vector<EdgeLike*> getEdgeTable(void);

        /**
         * Attempts to seek a vertex by its id
         * @return VertexLike*
         */
        const VertexLike* seekVertexById(const Id* id);

        /**
         * Creates a new vertex and makes it available to be attached to
         * within the graph
         * @return Id*
         */
        const Id* addVertex(void);

        /**
         * Retrieves the current in-memory managed table of edges
         * @return EdgeLike*
         */
        const EdgeLike* seekEdgeById(const Id* id);

        /**
         * Creates a new edge between two nodes and adds it to the graph
         * @return Id*
         */
        const Id* addEdge(const Id* a, const Id* b);
    };

}

#endif //GRAPHD_GRAPH_HPP
