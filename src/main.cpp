
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
         */

        auto graph = std::make_shared<graphd::Graph>();
        auto v1 = graph->addVertex();
        auto v2 = graph->addVertex();
        auto e1 = graph->addEdge(v1, v2);


        log_info << "found: " << graph->seekVertexById(v1)->getId()->toString();
    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << "Bad shit";
    }

    return 0;
}