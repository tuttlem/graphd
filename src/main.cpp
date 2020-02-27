
#include <iostream>
#include "./common.hpp"
#include "./core/log.hpp"
#include "./core/server.hpp"
#include "./db/types/id.hpp"

void doingSomething() {
    log_fn();
    log_info << "doing something";
}

int main() {
    try {
        log_scope("main");
        log_trace << "creating server object";

        /* the single server object that will manage the entire system */
        graphd::Server server = graphd::Server(
                std::make_shared<graphd::Telemetry>()
        );

        log_trace << "initializing logging system";
        graphd::configureLogger("debug", "/tmp/graphd_%N.log");

        log_trace << "ok, shouldn\'t see this one";
        log_debug << "here now";
        log_info << "here now";
        log_error << "here now";
        log_fatal << "here now";

        auto id = graphd::Id::create();
        std::cout << id->toString();
        // initialize

        doingSomething();
        // run

        // teardown

    } catch (std::exception e) {
        BOOST_LOG_TRIVIAL(error) << "Bad shit";
    }

    return 0;
}