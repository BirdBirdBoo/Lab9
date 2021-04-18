#ifndef LAB9_SET_H
#define LAB9_SET_H

#include "Collection.h"
#include "Appendable.h"

class Set : public Collection, Appendable {
public:
    Set();

    explicit Set(size_t initialSize);

    ~Set() override;

    int get(size_t index) const override;

    void add(int element) override;

    void addAll(const Collection &other) override;

    void addAll(const int *nativeArray, size_t arrayLength) override;

    long long indexOf(int element) const override;

    size_t getLength() const override;

    void clear() override;

    void print() const override;

protected:
    void printData() const override;

private:
    const static size_t DEFAULT_INITIAL_SIZE = 4;

    int *data = nullptr;
    size_t capacity = 0;
    size_t length = 0;

    void checkBounds(size_t index) const;

    bool elementExists(int element) const;

    size_t findInsertionIndex(int element) const;

    void insertAt(size_t index, int element);

    void ensureCapacity(size_t expectedCapacity);
};


#endif //LAB9_SET_H
