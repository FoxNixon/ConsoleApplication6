
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int requestArrSize(size_t* num);
void printArray(int* array, size_t arrSize);
void printSquareArray(int** array, size_t arrSize);
void createFile(string* fileName);
void printArrayToFile(int* array, size_t arrSize, string fileName);
void writeFileToFile(string inputFile, string outputFile);
void findWordInFile(string fileName, string targetWord, bool * isFound);
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();

string filename1, filename2, filename3;

int main(){

    //Task1();
    //Task2();
    //Task3();
    //Task4();
    Task5();

    return 0;
}



int requestArrSize(size_t* num) {
    size_t number;
    cout << "Enter array size" << endl;
    cin >> number;
    *num = number;

    return 0;
}

void printArray(const int* array, const size_t arrSize) {

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

void printArrayToFile(int* array, size_t arrSize, string fileName) {

    ofstream fout;
    string filename = fileName;
    fout.open(filename);
    for (size_t i = 0; i < arrSize; i++) {
        fout << array[i] << " ";
    }
    fout.close();

}

void writeFileToFile(string inputFile, string outputFile) {

    ifstream fin(inputFile);
    ofstream fout(outputFile, ios_base::app);

    if (fin.is_open() && fout.is_open()) {

        /*const size_t buffSize = 255;
        char buffer[buffSize] = {0};*/
        string buffer;

        while (!fin.eof()) {
            //fin.getline(buffer, buffSize);
            ////fout.end;
            //fout.write(buffer, buffSize);
            getline(fin, buffer);
            fout << buffer;

        }
        fin.close();
        fout.close();
    }
    else if (!fin.is_open()) {
        cout << "Can't open file " << inputFile << endl;
    }
    else {
        cout << "Can't open file " << outputFile << endl;
    }
}

void findWordInFile(string fileName, string targetWord, bool* isFound) {
    ifstream fin(fileName);

    if (fin.is_open()) {

        string str;
        while (!fin.eof()) {
            getline(fin, str);
            if (str.find(targetWord) != string::npos){
                *isFound = true;
            }
            else {
                *isFound = false;
            }
        }
    }
    else {
        cout << "Can't open file!"
    }
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
    delete(array2);
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
    filename1 = "1.txt";
    filename2 = "2.txt";
    createFile(&filename3);
    writeFileToFile(filename1, filename3);
    writeFileToFile(filename2, filename3);
}

void Task5() {
    string fileName, targetWord, result;
    bool bFlag = false;
    cout << "5.Enter the filename to check" << endl;
    cin >> fileName;
    cout << "Enter the text to search" << endl;
    cin >> targetWord;
    findWordInFile( fileName, targetWord, &bFlag);
    result = (bFlag == true) ? " is found " : " is not found ";

    cout << "Target text " << targetWord << result << "in the file " << fileName << endl;
}