//
// Created by michael on 3/3/20.
//

#ifndef GRAPHD_VERTEX_HPP
#define GRAPHD_VERTEX_HPP

#include "../common.hpp"
#include "types/id.hpp"
#include "types/interfaces.hpp"

namespace graphd {

    class Vertex : public VertexLike {
    private:
        std::shared_ptr<Id> _id;

    public:
        /** Default constructor*/
        Vertex(void) : _id(Id::create()) { }

        /** Construct with an id */
        Vertex(const std::shared_ptr<Id> id) : _id(id) { }
        virtual ~Vertex(void) { }

        /**
         * Retrieves the id of this vertex
         * @return Id*
         */
        const Id* getId(void) const { return this->_id.get(); }
    };

}

#endif //GRAPHD_VERTEX_HPP
