/// Makes sure that we can read the /etc/cdnalzier.conf config file
#include "config_reader.hpp"
#include <bandit/bandit.h>
#include <sstream>

go_bandit([](){
    using namespace bandit;
    using namespace cdnalizerd;

    describe("config_reader", [&](){
        it("1. Can read an empty config", [&] {
            std::stringstream empty;
            Config a = read_config(empty);
        });
        it("2. Can read a username", [&] {
            std::stringstream config;
            config << "username=james_bond";
            Config c = read_config(config);
            AssertThat(c.usernames.size(), Equals(size_t(1)));
        });
        it("3. Can read an apikey", [&] {
            std::stringstream config;
            config << "apikey=james_bond";
            Config c = read_config(config);
            AssertThat(c.apikeys.size(), Equals(size_t(1)));
        });
        it("4. Can read a container", [&] {
            std::stringstream config;
            config << "container=james_bond";
            Config c = read_config(config);
            AssertThat(c.containers.size(), Equals(size_t(1)));
        });
    });
});

int main(int argc, char** argv) {
    return bandit::run(argc, argv);
}
