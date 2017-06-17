#ifndef FINDER_HPP
#define FINDER_HPP

#include <string>
#include <map>
#include <boost/filesystem.hpp>
using namespace boost;

class Finder {
private:
    // <starting point>, where to start searching
    filesystem::path m_startingPoint;
    // <options>, find has different options, we need some container
    // for that options
    std::map<std::string, bool> m_searchOptions {
        {"-amin",       false},
        {"-anewer",     false},
        {"-atime",      false},
        {"-cmin",       false},
        {"-cnewer",     false},
        {"-ctime",      false},
        {"-empty",      false},
        {"-executable", false},
        {"-false",      false},
        {"-fstype",     false},
        {"-gid",        false},
        {"-group",      false},
        {"-ilname",     false},
        {"-iname",      false},
        {"-inum",       false},
        {"-ipath",      false},
        {"-iregex",     false},
        {"-links",      false},
        {"-lname",      false},
        {"-mmin",       false},
        {"-mtime",      false},
        {"-name",       false},
        {"-newer",      false},
        {"-nogroup",    false},
        {"-nouser",     false},
        {"-path",       false},
        {"-readable",   false},
        {"-regex",      false},
        {"-type",       false},
        {"-uid",        false},
        {"-user"        false},
        {"-writable",   false}
    }
    // <search term>, term which we will need to search for,
    // for example filename or last accessed time etc.
    std::string m_searchTerm;

public:

};

#endif
