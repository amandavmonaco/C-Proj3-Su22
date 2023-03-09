#include <iostream>
#include <fstream>
#include <cstring>
using namespace std

const int LETTERS = 26, WORDS = 1001;

//function that will read in the file using the file name the user inputs and place them into an array
//will prompt the user for a file name until an existing file name is used.
int readFile(char words[][LETTERS]){
    char file_name[51];
    cout << "What is the name of your file?: ";
    cin >> file_name;

    ifstream file;

    bool ask = true;

    while(ask){
        ask = false;
        file.open(file_name);
        if(!file.is_open()){
                cout << "Problem reading file. Try entering another file name: ";
                cin >> file_name;
                ask = true;
        }
    }

    int i = 0;
    while(file >> words[i]){
        i++;
    }
    file.close();
    return i;
}

//function that will sort each word's characters into alphbetical order
void makeAnagram(char words[][LETTERS], int numWords){
    char word[26];
    bool flag = true;

    while(flag){
        flag = false;
        for(int i = 0; i < numWords; i++){
            strcpy(word, words[i]);
            for(int j = 1; j < strlen(word); j++){
                if(word[j] < word[j-1]){
                    char temp = word[j];
                    word[j] = word[j-1];
                    word[j-1] = temp;
                    strcpy(words[i], word);
                    flag = true;
                }
            }
        }
    }
}

//function that will sort the list of alphabetically ordered characters into an alphabetical
//order list
void sortList(char anagrams[][LETTERS], int numWords){
    char a1[LETTERS];
    char a2[LETTERS];
    bool flag = true;

    while(flag) {
        flag = false;
        for(int i = 1; i < numWords; i++) {
            strcpy(a1, anagrams[i-1]);
            strcpy(a2, anagrams[i]);
            if(strcmp(a1,a2) > 0) {
                strcpy(anagrams[i], a1);
                strcpy(anagrams[i-1], a2);
                flag = true;
            }
        }
    }
}

//function that will look for duplicates and moves other word in the array move up one element
//reference variable for int numWords so that the number of words is updated when the function is used in main
void removeDups(char anagrams[][LETTERS], int& numWords){
    char a1[LETTERS];
    char a2[LETTERS];

    for(int i = 0; i < numWords-1; i++){
        strcpy(a1, anagrams[i]);
        strcpy(a2, anagrams[i+1]);
        if(strcmp(a1,a2) == 0){
            strcpy(anagrams[i], a2);
            for(int j = i+1; j < numWords; j++){
                strcpy(anagrams[j], anagrams[j+1]);
            }
            i--;
            numWords -= 1;
        }
    }
}


//function that will ask the user for the name of an output file and create one using the passed in the final
//unique set of character sets.
void outputFile(char anagrams[][LETTERS], int numWords){
    char outfile_name[50];
    cout << "What is the name of the file you would like to store the character sets in?: ";
    cin >> outfile_name;

    ofstream fileout(outfile_name);
    if(!fileout.is_open()){
        cout << "Problem printing file. Please enter the file name and try again: ";
        cin >> outfile_name;
    }

    for(int i = 0; i < numWords; i++){
        fileout << anagrams[i] << endl;
    }
    fileout.close();
}

//main will create a char double array sized 1001x26 and declare an int to the return variable of
//readFile function. then uses those as parameters in all preceding functions. calls makeAnagram then sortList
//then removeDups then outputFile.

int main() {
    char words[WORDS][LETTERS];
    int numOfWords = readFile(words);

    makeAnagram(words, numOfWords);
    sortList(words, numOfWords);
    removeDups(words, numOfWords);
    outputFile(words, numOfWords);
}

//code that i placed in main to test all the functions
//    for(int i = 0; i < numOfWords; i++){
//        cout << words[i] << endl;
//    }
//    cout << endl;
//    for(int i = 0; i < numOfWords; i++){
//        cout << words[i] << endl;
//    }
//
//    cout << endl;

//    for(int i = 0; i < numOfWords; i++){
//        cout << words[i] << endl;
//    }

//    cout << endl;

//    for(int i = 0; i < numOfWords; i++){
//        cout << words[i] << endl;
//    }