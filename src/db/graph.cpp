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

    const IdPtr Graph::removeNode(const IdPtr id) {
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

        return id;
    }

    const IdPtr Graph::removeEdge(const IdPtr id) {
        _edges.erase(id->getValue());
        _edgeData.erase(id->getValue());
        return id;
    }

    const IdPtr Graph::updateNode(const IdPtr id, const property_map_t& data) {
        _nodeData[id->getValue()] = data;
        return id;
    }

    const IdPtr Graph::updateEdge(const IdPtr id, const property_map_t& data) {
        _edgeData[id->getValue()] = data;
        return id;
    }

    const std::vector<IdPtr> Graph::getAdjacentNodes(const IdPtr id) const {
        std::vector<IdPtr> adjacentNodes;
        for (auto& [edgeId, edge] : _edges) {
            if (edge.first->getValue() == id->getValue()) {
                adjacentNodes.push_back(edge.second);
            }
        }
        return adjacentNodes;
    }

    const std::vector<IdPtr> Graph::getAdjacentEdges(const IdPtr id) const {
        std::vector<IdPtr> adjacentEdges;
        auto idVal = id->getValue();

        for (auto& [edgeId, edge] : _edges) {
            if (edge.first->getValue() == idVal || edge.second->getValue() == idVal) {
                adjacentEdges.push_back(edgeId);
            }
        }
        return adjacentEdges;
    }

}