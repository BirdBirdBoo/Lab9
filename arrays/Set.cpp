#include "Set.h"

Set::Set() : Set(DEFAULT_INITIAL_SIZE) {

}

Set::Set(size_t initialSize) {
    ensureCapacity(initialSize);
}

Set::~Set() {
    if (data != nullptr) {
        free(data);
    }
}

int Set::get(size_t index) const {
    checkBounds(index);
    return data[index];
}

void Set::add(int element) {
    size_t insertionIndex = findInsertionIndex(element);

    if (data[insertionIndex] == element) {
        // then the element already exists
        return;
    }

    ensureCapacity(length + 1);
    insertAt(insertionIndex, element);
    ++length;
}

void Set::addAll(const Collection &other) {
    for (int i = 0; i < other.getLength(); ++i) {
        add(other[i]);
    }
}

void Set::addAll(const int *nativeArray, size_t arrayLength) {
    for (int i = 0; i < arrayLength; ++i) {
        add(nativeArray[i]);
    }
}

long long Set::indexOf(int element) const {
    if (length == 0) {
        return -1;
    }

    if (element > data[length - 1]) {
        return -1;
    }

    size_t l = 0, r = length - 1;
    while (r - l > 1) {
        size_t m = (l + r) / 2;

        if (data[m] == element) {
            return (long long) m;
        } else if (element < data[m]) {
            r = m;
        } else {
            l = m;
        }
    }
    if (element == data[l]) {
        return (long long) l;
    } else if (element == data[r]) {
        return (long long) r;
    }
    return -1;
}

void Set::clear() {
    length = 0;
}

bool Set::elementExists(int element) const {
    return indexOf(element) != -1;
}

size_t Set::findInsertionIndex(int element) const {
    if (length == 0 || element < data[0])
        return 0;

    if (data[length - 1] < element) {
        return length;
    }

    size_t l = 0, r = length - 1;

    while (r - l > 1) {
        size_t m = (l + r) / 2;

        if (element < data[m]) {
            r = m;
        } else {
            l = m;
        }
    }
    if (element > data[l]) {
        return r;
    } else {
        return l;
    }
}

void Set::insertAt(size_t index, int element) {
    if (index < length) {
        int *pStart = data + index;

        size_t newLength = length + 1;
        size_t byteCount = (newLength - index) * sizeof(int);

        memmove(pStart + 1, pStart, byteCount);
    }

    data[index] = element;
}

size_t Set::getLength() const {
    return length;
}

void Set::checkBounds(size_t index) const {
    if (index >= length) {
        throw std::invalid_argument("Index is bigger than length!");
    }
}

void Set::ensureCapacity(size_t expectedCapacity) {
    if (expectedCapacity <= capacity) {
        return;
    }

    if (data == nullptr) {
        data = (int *) calloc(expectedCapacity, sizeof(int));
    } else {
        data = (int *) realloc(data, expectedCapacity * sizeof(int));
    }
    capacity = expectedCapacity;
}

std::string Set::toString() const
{
    std::stringstream out;
    out << "Set of size " << length << ": " << dataString('{', '}');
    return out.str();
}
