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

void CountingSortByBit(vector<unsigned char> &A, int bit) {
    int size = A.size();
    vector<unsigned char> B(size); //to bo izhodno polje

    vector<int> C(2, 0);

    vector<int> D = ExtractBits(A, bit);

    for (int i = 0; i < size; ++i) {
        C[D[i]]++;
    }

    C[1] += C[0];

    for (int i = size - 1; i >= 0; --i) {
        B[--C[D[i]]] = A[i];
    }

    swap(A, B);
}

void BinaryRadixSort(vector<unsigned char> &A) {
    for (int bit = 0; bit < 8; ++bit) {
        CountingSortByBit(A, bit);
    }
}

void testExtractBits(const vector<unsigned char> &A, int bit) {
    vector<int> D = ExtractBits(A, bit);

    cout << "Polje D za bit " << bit << ": ";
    for (int b: D) {
        cout << b << " ";
    }
    cout << endl;
}

int main() {
    vector<unsigned char> A = {200, 3, 255, 128, 50, 100, 1, 2}; //samo za example

    for (const unsigned char num: A) {
        cout << static_cast<int>(num) << " ";
    }

    //testExtractBits(A, 3);

    return 0;
}
