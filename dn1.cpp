#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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

bool BranjeStevil(vector<unsigned char> &A, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (input >> st) {
        A.push_back(st);
    }

    input.close();
    return true;
}

void IzpisStevil(const unsigned char *polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i < velikost; ++i) {
        output << static_cast<int>(polje[i]) << " ";
    }
}

int main(int argc, const char *argv[]) {
    vector<unsigned char> A;

    if (!BranjeStevil(A, argv[1])) return 0;
    for (const unsigned char num: A) {
        cout << static_cast<int>(num) << " ";
    }
    //testExtractBits(A, 3);

    BinaryRadixSort(A);
    cout << "\nPo sortiranju:" << endl;
    for (const unsigned char num: A) {
        cout << static_cast<int>(num) << " ";
    }

    IzpisStevil(&A[0], A.size());

    return 0;
}
