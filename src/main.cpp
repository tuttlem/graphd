
#include <iostream>
#include "./common.hpp"
#include "./core/log.hpp"
#include "./core/config.hpp"

#include "./db/graph.hpp"

int main() {
    try {
        // auto config = graphd::Config::getDefault();
        /*
        auto config = graphd::Config::loadFromFile("graphd.conf");
        graphd::Config::adjustWithEnvironment(config);

        log_info << config->_logLevel;

        auto graph = std::make_shared<graphd::Graph>();
        auto v1 = graph->addVertex();
        auto v2 = graph->addVertex();
        auto e1 = graph->addEdge(v1, v2);

        auto id1 = graph->seekVertexById(v1)->getId();
        log_info << "found: " << id1->toString();
        */

        auto id1 = graphd::Id::create();
        auto id2 = graphd::Id::create();

        std::ofstream outFile("ids.bin", std::ios::binary);
        id1->serialize(outFile);
        id2->serialize(outFile);
        outFile.close();

        std::ifstream inFile("ids.bin", std::ios::binary);
        auto id3 = graphd::Id::create(inFile);
        auto id4 = graphd::Id::create(inFile);
        inFile.close();

        log_info << "\n 1: " << id1->toString() << \
                    "\n 2: " << id2->toString() << \
                    "\n 3: " << id3->toString() << \
                    "\n 4: " << id4->toString();

        // log_info << "1 and 3 are equal? " << (*id1 == *id3);
        //log_info << "2 and 4 are equal? " << (*id2 == *id4);

    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << "Bad shit";
    }

    return 0;
}