
#include <iostream>
#include <fstream>

using namespace std;

int requestArrSize(size_t* num);
void printArray(int* array, size_t arrSize);
void printSquareArray(int** array, size_t arrSize);
void createFile(string* fileName);
void printArrayToFile(int* array, size_t arrSize, string fileName);

void Task1();
void Task2();
void Task3();
void Task4();

string filename1, filename2;

int main()
{
    //Task1();
    //Task2();
    //Task3();

}



int requestArrSize(size_t* num) {
    size_t number;
    cout << "Enter array size" << endl;
    cin >> number;
    *num = number;

    return 0;
}

void printArray(int* array, size_t arrSize) {

    cout << "Array is: ";
    for (size_t i = 0; i < arrSize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printSquareArray(int** array, size_t arrSize) {

    cout << "Square array is: " << endl;
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = 0; j < arrSize; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void createFile(string* fileName) {
    string filename;
    cout << "Define the name of the text file" << endl;
    cin >> filename;
    filename = filename + ".txt";
    //cout << filename;
    ofstream fout(filename);
    *fileName = filename;
}

void printArrayToFile (int* array, size_t arrSize, string fileName) {
    
    ofstream fout;
    string filename = fileName;
    fout.open(filename);
    for (size_t i = 0; i < arrSize; i++) {
        fout << array[i] << " ";
    }
    fout.close();
    
}

void Task1() {
    size_t arraySize = 0;
    requestArrSize(&arraySize);
    int* array1 = (int*)malloc(arraySize * sizeof(int));
    array1[0] = 1;
    for (size_t i = 1; i < arraySize; i++)
    {
        array1[i] = array1[i - 1] * 2;

    }
    printArray(array1, arraySize);
    free(array1);
}

void Task2() {
    const size_t ARRAY2_SIZE = 4;
    const size_t NUM_LIMIT = 256;
    int** array2 = nullptr;

    array2 = new (nothrow) int* [ARRAY2_SIZE];
    for (size_t i = 0; i < ARRAY2_SIZE; i++)
    {
        array2[i] = new (nothrow) int[ARRAY2_SIZE];
        for (size_t j = 0; j < ARRAY2_SIZE; j++)
        {
            array2[i][j] = rand() % NUM_LIMIT;

        }
    }
    printSquareArray(array2, ARRAY2_SIZE);
}

void Task3() {
    //string filename1, filename2;
    const size_t ARRAY3_SIZE = 50;
    cout << "1. ";
    createFile(&filename1);
    cout << "2. ";
    createFile(&filename2);
    //cout << filename1 << "\t" << filename2 << endl;

    int array3[ARRAY3_SIZE] = { 0 };
    for (size_t i = 0; i < ARRAY3_SIZE; i++){
        array3[i] = rand() % 256;
    }
    printArrayToFile(array3, ARRAY3_SIZE, filename1);
    printArrayToFile(array3, ARRAY3_SIZE, filename2);

}

void Task4() {
    ifstream fin;
    
}