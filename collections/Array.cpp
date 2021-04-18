#include "Array.h"

Array::Array() : Array(DEFAULT_INITIAL_SIZE) {
}

Array::Array(size_t initialSize) {
    if (initialSize == 0)
        return;

    ensureCapacity(initialSize);
}

Array::~Array() {
    if (data == nullptr)
        return;

    free(data);
}

void Array::add(int element) {
    ensureCapacity(length + 1);
    data[length] = element;
    ++length;
}

void Array::addAll(const Collection &other) {
    const size_t newLength = length + other.getLength();
    ensureCapacity(newLength);

    for (size_t i = length; i < newLength; ++i) {
        data[i] = other[i - length];
    }

    length = newLength;
}

void Array::addAll(const int *nativeArray, size_t arraySize) {
    const size_t newLength = length + arraySize;
    ensureCapacity(newLength);

    memcpy(data + length, nativeArray, arraySize);

    length = newLength;
}

int Array::get(size_t index) const {
    checkBounds(index);
    return data[index];
}

int &Array::operator[](size_t index) {
    checkBounds(index);
    return data[index];
}

void Array::set(size_t index, int element)
{
    checkBounds(index);
    data[index] = element;
}

void Array::clear() {
    length = 0;
}


size_t Array::getLength() const {
    return length;
}

void Array::checkBounds(size_t index) const {
    if (index >= length) {
        throw std::invalid_argument("Index is bigger than length!");
    }
}

void Array::ensureCapacity(size_t expectedCapacity) {
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

std::string Array::toString() const
{
    std::stringstream out;
    out << "Array of length " << length << " : " << dataString();
    return out.str();
}

long long Array::indexOf(int element) const {
    for (size_t i = 0; i < length; ++i) {
        if (data[i] == element) {
            return (long long) i;
        }
    }
    return -1;
}
