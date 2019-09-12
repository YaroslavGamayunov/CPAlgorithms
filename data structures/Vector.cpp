#include <cstdio>

template<typename T>
class Vector {
private:
    const int initialSize = 10;
    int sizeForDoubling;
    int dataSize;
    T *data;

    void allocateMemory(int newSize) {
        T *tmpData = new T[newSize];

        for (int i = 0; i < dataSize; i++) {
            tmpData[i] = data[i];
        }
        data = tmpData;
    };
public:
    Vector() {
        dataSize = 0;
        sizeForDoubling = initialSize;
        data = new T[initialSize];
    }

    Vector(unsigned int n, T initValue) {
        dataSize = n;
        sizeForDoubling = initialSize;
        data = new T[initialSize];
        for (int i = 0; i < dataSize; i++) {
            data[i] = initValue;
        }
    }

    Vector(T *dataPointer, int n) {
        dataSize = n;
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = dataPointer[i];
        }
    }

    int size() {
        return dataSize;
    }

    void add(T x) {
        if (dataSize >= sizeForDoubling) {
            sizeForDoubling *= 2;
            allocateMemory(sizeForDoubling);
        }
        data[dataSize] = x;
        dataSize++;
    }

    void pop() {
        if (dataSize > 0) dataSize--;
    }

    T &operator[](int i) {
        return data[i];
    }
};

int main() {

}
