#ifndef LAB9_COLLECTION_H
#define LAB9_COLLECTION_H

#include <cstddef>
#include <iostream>
#include "Indexable.h"

using std::size_t;
using std::cout;
using std::endl;

class Collection: Indexable {

public:
    virtual ~Collection() = default;

    Collection &operator=(const Collection &other) = delete;

    virtual void clear() = 0;

    virtual size_t getLength() const = 0;

    virtual void print() const;

protected:
    virtual void printData() const;
};


#endif //LAB9_COLLECTION_H
