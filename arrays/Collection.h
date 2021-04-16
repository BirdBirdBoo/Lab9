#ifndef LAB9_COLLECTION_H
#define LAB9_COLLECTION_H

#include <cstddef>
#include <iostream>

using std::size_t;
using std::cout;
using std::endl;

class Collection {

public:
    virtual ~Collection() = default;
    Collection &operator=(const Collection &other) = delete;

    virtual int get(size_t index) const = 0;

    virtual void add(int newElement) = 0;
    virtual void addAll(const Collection &other) = 0;
    virtual void addAll(const int *nativeArray, size_t arraySize) = 0;

    virtual long long indexOf(int element) const = 0;

    virtual void clear() = 0;

    virtual size_t getLength() const = 0;

    virtual void print() const;

    int operator[](size_t index) const;

    Collection &operator+=(int element);
    Collection &operator+=(const Collection& other);

protected:
    virtual void printData() const;
};


#endif //LAB9_COLLECTION_H
