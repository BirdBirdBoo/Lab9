#include "Collection.h"

std::string Collection::toString() const {
    std::stringstream builder;
    builder << "Collection of size" << getLength() << ": " << dataString();
    return builder.str();
}

std::string Collection::dataString(char leftBracket, char rightBracket) const {
    std::stringstream builder;
    builder << "Data: " << leftBracket;

    if (getLength() > 0) {
        for (size_t i = 0; i < getLength() - 1; ++i) {
            builder << (*this)[i] << ", ";
        }
        builder << (*this)[getLength() - 1];
    }
    builder << rightBracket;

    return builder.str();
}
