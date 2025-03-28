#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ExtractBits(const vector<unsigned char> &A, int bit) {
    vector<int> D(A.size());
    for (int i = 0; i < A.size(); ++i) {
        D[i] = (A[i] >> bit) & 1;
    }
    return D;
}

void BinaryRadixSort(vector<unsigned char> &A) {
    for (int bit = 0; bit < 8; ++bit) {
        //TODO CountingSortByBit(A, bit);
    }
}

void CountingSortByBit(vector<unsigned char> &A, int bit) {
    vector<int> D = ExtractBits(A, bit);
}

int main() {
    vector<unsigned char> A = {200, 3, 255, 128, 50, 100, 1, 2}; //samo za example

    for (const unsigned char num: A) {
        cout << static_cast<int>(num) << " ";
    }


    return 0;
}
