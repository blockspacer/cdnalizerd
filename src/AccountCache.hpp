#pragma once

#include "common.hpp"
#include "Rackspace.hpp"
#include "config_reader/config.hpp"

#include <jsonpp11/parse_to_json_class.hpp>

#include <functional>

namespace cdnalizerd {


struct CompareSharedPtr {
  bool operator()(const sstring &a, const sstring &b) const {
    return ((a ? *a : "") < (b ? *b : ""));
  }
};

using AccountCache = std::map<sstring, Rackspace, CompareSharedPtr>;

/// Worker that fills an account cache by logging on to all the RS accounts and getting the token and json
void fillAccountCache(yield_context &yield, const Config &config,
                      AccountCache &cache, std::function<void()> onDone);

} /* cdnalizerd  */ 