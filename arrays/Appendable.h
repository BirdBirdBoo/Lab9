#ifndef LAB9_APPENDABLE_H
#define LAB9_APPENDABLE_H


class Appendable {
    virtual void add(int newElement) = 0;

    virtual void addAll(const Collection &other) = 0;

    virtual void addAll(const int *nativeArray, size_t arraySize) = 0;

    Collection &operator+=(int element) {
        this->add(element);
        return *this;
    }

    Collection &operator+=(const Collection &other) {
        this->addAll(other);
        return *this;
    }
};


#endif //LAB9_APPENDABLE_H
