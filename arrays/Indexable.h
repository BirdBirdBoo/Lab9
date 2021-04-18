#ifndef LAB9_INDEXABLE_H
#define LAB9_INDEXABLE_H

class Indexable {
    virtual long long indexOf(int element) const = 0;

    virtual int get(size_t index) const = 0;

    int operator[](size_t index) const {
        return get(index);
    }
};

#endif //LAB9_INDEXABLE_H
