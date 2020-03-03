//
// Created by michael on 3/3/20.
//

#ifndef GRAPHD_INTERFACES_HPP
#define GRAPHD_INTERFACES_HPP

#include "id.hpp"

namespace graphd {

    class VertexLike {
    public:
        virtual const Id* getId(void) const = 0;
    };

    class EdgeLike {
    public:
        virtual const Id* getId(void) const = 0;

        virtual std::vector<Id*> getVertexIds(void) = 0;
    };

    class GraphLike {
    public:
        /**
         * Retrieves the current in-memory managed table of vertices
         * @return std::vector<VertexLike*>
         */
        virtual const std::vector<VertexLike*> getVertexTable(void) = 0;

        /**
         * Retrieves the current in-memory managed table of edges
         * @return std::vector<EdgeLike*>
         */
        virtual const std::vector<EdgeLike*> getEdgeTable(void) = 0;

        /**
         * Attempts to seek a vertex by its id
         * @return VertexLike*
         */
        virtual const VertexLike* seekVertexById(const Id* id) = 0;

        /**
         * Creates a new vertex and makes it available to be attached to
         * within the graph
         * @return Id*
         */
        virtual const Id* addVertex(void) = 0;

        /**
         * Retrieves the current in-memory managed table of edges
         * @return EdgeLike*
         */
        virtual const EdgeLike* seekEdgeById(const Id* id) = 0;

        /**
         * Creates a new edge between two nodes and adds it to the graph
         * @return Id*
         */
        virtual const Id* addEdge(const Id* a, const Id* b) = 0;

    };

}

#endif //GRAPHD_INTERFACES_HPP
