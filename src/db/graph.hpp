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

        inline const size_t getNodeCount(void) const { return _nodes.size(); }
        inline const size_t getEdgeCount(void) const { return _edges.size(); }

        inline const bool hasNode(const IdPtr id) const { return _nodes.find(id->getValue()) != _nodes.end(); }
        inline const bool hasEdge(const IdPtr id) const { return _edges.find(id->getValue()) != _edges.end(); }

        /**
         * Get the node with the given id
         * @param id The id of the node to get
         * @return The node with the given id
         */
        inline const property_map_t getNodeData(const IdPtr id) const {
            if (!this->hasNode(id)) {
                throw std::invalid_argument("Node does not exist");
            }

            return _nodeData.at(id->getValue());
        }

        const IdPtr addNode(const property_map_t& data = property_map_t());
        const IdPtr addEdge(const IdPtr from, const IdPtr to, const property_map_t& data = property_map_t());

        const void removeNode(const IdPtr id);
        const void removeEdge(const IdPtr id);

        const void updateNode(const IdPtr id, const property_map_t& data = property_map_t());
        const void updateEdge(const IdPtr id, const property_map_t& data = property_map_t());

        /**
         * Gets all of the connected objects, normalised into a vector of pairs
         * @param id {IdPtr} The id of the node to get the edges of
         * @return {std::vector<std::pair<IdPtr, IdPtr>>} The edges <node, edge>
         */
        const std::vector<std::pair<IdPtr, IdPtr>> getAdjacentEdges(const IdPtr id) const;

        /**
         * Get the adjacent nodes to the given node
         * @param id {IdPtr} The id of the node to get the adjacent nodes of
         * @return {std::vector<IdPtr>} The adjacent nodes
         */
        const std::vector<IdPtr> getAdjacentNodes(const IdPtr id) const;

        const std::vector<IdPtr> findPath(const IdPtr &from, const IdPtr &to) const;

    private:
        node_map_t _nodes;
        data_map_t _nodeData;

        edge_map_t _edges;
        data_map_t _edgeData;
    };

}

#endif //GRAPHD_GRAPH_HPP
