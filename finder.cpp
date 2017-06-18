#include "finder.hpp"

void Finder::processCmdArgs() {
    constexpr auto basicARGC(4);

    if(m_args.size() == basicARGC) {
        m_startingPoint = m_args.at(1);
        m_option = m_args.at(2);
        m_searchTerm = m_args.at(3);
    }

    /*To be continued...*/
}

void Finder::determineFindType() {
    if(m_option == "-name")
        m_unifiedFind = std::make_unique<FindByFilename>();

    /*To be continued*/
}

filesystem::path Finder::find() {
    return m_unifiedFind->find(m_startingPoint, m_searchTerm);
}
