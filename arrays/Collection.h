#ifndef LAB9_COLLECTION_H
#define LAB9_COLLECTION_H

#include <cstddef>
#include <string>
#include <sstream>
#include "Indexable.h"

using std::size_t;

class Collection: public Indexable {

public:
    virtual ~Collection() = default;

    Collection &operator=(const Collection &other) = delete;

    virtual void clear() = 0;

    virtual size_t getLength() const = 0;

    virtual std::string toString() const;

protected:
    virtual std::string dataString(char leftBracket = '[', char rightBracket = ']') const;
};


#endif //LAB9_COLLECTION_H
