#ifndef BASICFIND_HPP
#define BASICFIND_HPP

#include <string>
#include <boost/filesystem.hpp>
using namespace boost;

class BasicFind {
public:
    virtual filesystem::path find
        (const filesystem::path& startingPoint, std::string searchTerm) = 0;
};

#endif
