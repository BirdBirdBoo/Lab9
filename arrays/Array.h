#ifndef LAB9_ARRAY_H
#define LAB9_ARRAY_H

#include "Collection.h"
#include "Appendable.h"

class Array : public Collection, public Appendable {
public:
    Array();

    explicit Array(size_t initialSize);

    ~Array() override;

    void add(int element) override;

    void addAll(const Collection &other) override;

    void addAll(const int *nativeArray, size_t arraySize) override;

    int get(size_t index) const override;

    long long indexOf(int element) const override;

    size_t getLength() const override;

    int &operator[](size_t index);

    void clear() override;

    std::string toString() const override;

private:
    const static size_t DEFAULT_INITIAL_SIZE = 4;

    int *data = nullptr;
    size_t capacity = 0;
    size_t length = 0;

    void ensureCapacity(size_t expectedCapacity);

    void checkBounds(size_t index) const;
};


#endif //LAB9_ARRAY_H
