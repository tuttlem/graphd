//
// Created by michael on 3/3/20.
//

#include "graph.hpp"

namespace graphd {
    const IdPtr Graph::addNode(const property_map_t& data) {
        auto id = Id::create();
        _nodes[id->getValue()] = id;
        _nodeData[id->getValue()] = data;
        return id;
    }

    const IdPtr Graph::addEdge(const IdPtr from, const IdPtr to, const property_map_t& data) {
        auto id = Id::create();
        _edges[id->getValue()] = std::make_pair(from, to);
        _edgeData[id->getValue()] = data;
        return id;
    }

    const void Graph::removeNode(const IdPtr id) {
        auto idVal = id->getValue();

        std::vector<id_val_t> toRemove;
        for (auto& [edgeId, edge] : _edges) {
            if (edge.first->getValue() == idVal || edge.second->getValue() == idVal) {
                toRemove.push_back(edgeId);
            }
        }

        for (auto& edgeId : toRemove) {
            _edges.erase(edgeId);
            _edgeData.erase(edgeId);
        }

        _nodes.erase(id->getValue());
        _nodeData.erase(id->getValue());
    }

    const void Graph::removeEdge(const IdPtr id) {
        _edges.erase(id->getValue());
        _edgeData.erase(id->getValue());
    }

    const void Graph::updateNode(const IdPtr id, const property_map_t& data) {
        if (id == nullptr) {
            throw std::invalid_argument("Cannot update edge with null id");
        }

        _nodeData[id->getValue()] = data;
    }

    const void Graph::updateEdge(const IdPtr id, const property_map_t& data) {
        if (id == nullptr) {
            throw std::invalid_argument("Cannot update edge with null id");
        }

        _edgeData[id->getValue()] = data;
    }

    /**
     * Gets all of the connected objects, normalised into a vector of pairs
     * @param id {IdPtr} The id of the node to get the edges of
     * @return {std::vector<std::pair<IdPtr, IdPtr>>} The edges <node, edge>
     */
    const std::vector<std::pair<IdPtr, IdPtr>> Graph::getEdges(const IdPtr id) const {
        std::vector<std::pair<IdPtr, IdPtr>> edges;

        // handle nulls quietly
        if (id == nullptr) {
            return edges;
        }

        for (auto& [edgeId, edge] : _edges) {
            if (edge.first->getValue() == id->getValue()) {
                edges.push_back(std::make_pair(edge.second, Id::fromValue(edgeId)));
            } if (edge.second->getValue() == id->getValue()) {
                edges.push_back(std::make_pair(edge.first, Id::fromValue(edgeId)));
            }
        }

        return edges;
    }

    const std::vector<IdPtr> Graph::getAdjacentNodes(const IdPtr id) const {
        std::vector<IdPtr> adjacentNodes;

        // handle nulls quietly
        if (id == nullptr) {
            return adjacentNodes;
        }

        for (auto& [edgeId, edge] : _edges) {
            if (edge.first->getValue() == id->getValue()) {
                adjacentNodes.push_back(edge.second);
            } else if (edge.second->getValue() == id->getValue()) {
                adjacentNodes.push_back(edge.first);
            }
        }
        return adjacentNodes;
    }

    const std::vector<IdPtr> Graph::findPath(const IdPtr &from, const IdPtr &to) const {

    }
}