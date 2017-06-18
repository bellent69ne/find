#ifndef FINDBYFILENAME_HPP
#define FINDBYFILENAME_HPP

#include "basicFind.hpp"

class FindByFilename: public BasicFind {
public:
    filesystem::path find
        (const filesystem::path& startingPoint, std::string searchTerm) override {
        auto recursiveDirItr(
            static_cast<filesystem::recursive_directory_iterator>
                (startingPoint)
        );

        filesystem::path fileWasFound("");

        while(recursiveDirItr != filesystem::recursive_directory_iterator()) {
            filesystem::path currentPath(*recursiveDirItr);
            if(currentPath.filename() == searchTerm) {
                fileWasFound = filesystem::path(*recursiveDirItr);
                break;
            }

            ++recursiveDirItr;
        }

        return fileWasFound;
    }
};

#endif
