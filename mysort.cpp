#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    
    for (int i=0; i<argc; i++){
        cout << "argv["<<i<<"]: "<<argv[i] << endl;
    }

    ifstream fin;
    fin.open(argv[1], ios::in);
    
    int* numArray = nullptr;
    int capacity = 10;
    int size = 0;
    int num;

    numArray = new int[capacity];

    while (fin >> num) {
        if (size == capacity) {
            capacity *= 2;
            int* tempArray = new int[capacity];

            for (int i = 0; i < size; ++ i) {
                tempArray[i] = numArray[i];
            }

            delete[] numArray;
            numArray = tempArray;
        }
        numArray[size] = num;
        ++size;
    }

    fin.close();

    for (int i = 0; i < size; ++i) {
        bool swapped = false;

        for (int j = 0; j < size - 1; ++j) {
            if (numArray[j] > numArray[j + 1]) {
                swap(numArray[j], numArray[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
    ofstream fout;
    fout.open(argv[2], ios::out);
    for (int i = 0; i < size; ++i) {
        fout << numArray[i] << endl;
    }

    fout.close();
    delete[] numArray;
    

}