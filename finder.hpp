#ifndef FINDER_HPP
#define FINDER_HPP

#include <string>
#include <map>
#include <memory>
#include "findByFilename.hpp"
#include <boost/filesystem.hpp>
using namespace boost;

class Finder {
private:
    // <starting point>, where to start searching
    filesystem::path m_startingPoint;
    // <options>, find has different options, we need some container
    // for that options
    std::string m_option;
    /*std::map<std::string, std::shared_ptr<BasicFind>> m_searchOptions {
        {"-name", std::make_shared<FindByFilename>()}
        /*{"-amin",       },
        {"-anewer",     },
        {"-atime",      },
        {"-cmin",       },
        {"-cnewer",     },
        {"-ctime",      },
        {"-empty",      },
        {"-executable", },
        {"-false",      },
        {"-fstype",     },
        {"-gid",        },
        {"-group",      },
        {"-ilname",     },
        {"-iname",      },
        {"-inum",       },
        {"-ipath",      },
        {"-iregex",     },
        {"-links",      },
        {"-lname",      },
        {"-mmin",       },
        {"-mtime",      },
        {"-name",       },
        {"-newer",      },
        {"-nogroup",    },
        {"-nouser",     },
        {"-path",       },
        {"-readable",   },
        {"-regex",      },
        {"-type",       },
        {"-uid",        },
        {"-user"        },
        {"-writable",   }
    };*/
    // <search term>, term which we will need to search for,
    // for example filename or last accessed time etc.
    std::string m_searchTerm;
    // unified find is a function object which can find anything according
    // to the search pattern... Actually it's a polymorphic function object
    std::unique_ptr<BasicFind> m_unifiedFind;

    std::vector<std::string> m_args;

    void processCmdArgs();

    void determineFindType();
public:
    /*template<
        typename StartingP,
        typename SearchT,
        typename = std::enable_if_t<
            std::is_constructible<
                filesystem::path, StartingP
            >::value &&
            std::is_constructible<
                std::string, SearchT
            >::value
        >
    >
    explicit Finder(StartingP&& startingPoint,
                    SearchT&& option, SearchT&& searchTerm):
                    m_startingPoint(std::forward<StartingP>(startingPoint)),
                    m_option(std::forward<SearchT>(option)),
                    m_searchTerm(std::forward<SearchT>(searchTerm)) {

    }*/
    template<
        typename T,
        typename cmdArgs
        //typename = std::enable_if_t<
        //    std::is_integral<std::decay<T>>::value &&
        //    std::is_constructible<
        //        std::string,
        //        std::decay_t<cmdArgs>
        //    >::value
        //>
    >
    explicit Finder(T&& paramsNum, cmdArgs params):
                        m_args(params, params + paramsNum) {
        processCmdArgs();

        determineFindType();
    }

    template<
        typename StartingP,
        typename SearchT,
        typename = std::enable_if_t<
            std::is_assignable<
                filesystem::path, StartingP
            >::value &&
            std::is_assignable<
                std::string, SearchT
            >::value
        >
    >
    auto find(StartingP startingPoint, SearchT searchTerm) {
        m_startingPoint = std::forward<StartingP>(startingPoint);
        m_searchTerm = std::forward<SearchT>(searchTerm);

        return find();
    }

    filesystem::path find();

};

#endif
