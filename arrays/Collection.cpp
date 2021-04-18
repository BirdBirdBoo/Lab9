#include "Collection.h"

void Collection::print() const {
    cout << "Collection of size " << getLength() << endl;
    printData();
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