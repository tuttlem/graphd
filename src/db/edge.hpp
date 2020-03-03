//
// Created by michael on 3/3/20.
//

#ifndef GRAPHD_EDGE_HPP
#define GRAPHD_EDGE_HPP

#include "../common.hpp"
#include "types/id.hpp"
#include "types/interfaces.hpp"

namespace graphd {

    class Edge : public EdgeLike {
    private:
        std::shared_ptr<Id> _id;
        std::vector<std::shared_ptr<Id>> _vertexIds;

    public:
        /** Default constructor*/
        Edge(void) : _id(Id::create()) { }

        /** Construct with an id */
        Edge(const std::shared_ptr<Id> id) : _id(id) { }
        virtual ~Edge(void) { }

        /**
         * Retrieves the id of this edge
         * @return Id*
         */
        const Id* getId(void) const { return this->_id.get(); }

        std::vector<Id*> getVertexIds(void) {
            std::vector<Id*> ids;
            std::transform(
                this->_vertexIds.begin(),
                this->_vertexIds.end(),
                ids.begin(),
                [](std::shared_ptr<Id> i) -> Id* { return i.get(); }
            );

            return ids;
        }

    };

}

#endif //GRAPHD_EDGE_HPP
