//
// Created by michael on 3/3/20.
//

#ifndef GRAPHD_GRAPH_HPP
#define GRAPHD_GRAPH_HPP

#include "../common.hpp"
#include "./types/id.hpp"
#include "./types/properties.hpp"

namespace graphd {

    typedef std::map<id_val_t, IdPtr> node_map_t;
    typedef std::map<id_val_t, std::pair<IdPtr, IdPtr>> edge_map_t;


    /**
     * The graph data structure implementation
     */
    class Graph {
    public:
        /**
         * Default constructor
         */
        Graph(void) { }

        Graph(const Graph&) = delete;
        Graph(Graph&&) = delete;

        virtual ~Graph(void) = default;

        inline const node_map_t getNodes(void) const { return _nodes; }
        inline const data_map_t getNodeData(void) const { return _nodeData; }
        inline const edge_map_t getEdges(void) const { return _edges; }
        inline const data_map_t getEdgeData(void) const { return _edgeData; }

        const IdPtr addNode(const property_map_t& data = property_map_t());
        const IdPtr addEdge(const IdPtr from, const IdPtr to, const property_map_t& data = property_map_t());

        const IdPtr removeNode(const IdPtr id);
        const IdPtr removeEdge(const IdPtr id);

        const IdPtr updateNode(const IdPtr id, const property_map_t& data = property_map_t());
        const IdPtr updateEdge(const IdPtr id, const property_map_t& data = property_map_t());

        const std::vector<IdPtr> getAdjacentNodes(const IdPtr id) const;
        const std::vector<IdPtr> getAdjacentEdges(const IdPtr id) const;


    private:
        node_map_t _nodes;
        data_map_t _nodeData;

        edge_map_t _edges;
        data_map_t _edgeData;
    };

}

#endif //GRAPHD_GRAPH_HPP
