#include "Collection.h"

void Collection::print() const {
    cout << "Collection of size " << getLength() << endl;
    printData();
}

Collection &Collection::operator+=(int element) {
    this->add(element);
    return *this;
}

Collection &Collection::operator+=(const Collection& other) {
    this->addAll(other);
    return *this;
}

void Collection::printData() const {
    cout << "Data: [";

    if (getLength() > 0) {
        for (size_t i = 0; i < getLength() - 1; ++i) {
            cout << (*this)[i] << ", ";
        }
        cout << (*this)[getLength() - 1];
    }
    cout << "]" << endl;
}

int Collection::operator[](size_t index) const {
    return get(index);
}
