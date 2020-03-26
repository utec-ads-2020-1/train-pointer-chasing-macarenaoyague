#include <iostream>
using namespace std;
#include <sstream>
#include <vector>

void chasing(int **A[], int a, int *B[], int b, int C[], int c);

bool checkLine(string line);

int main() {
    int a = 5, b = 4, c = 3;
    int **A[5] = {}, *B[4] = {}, C[3] = {2, 1, 4};
    chasing(A, a, B, b, C, c);

    int **ansA[5] = {} ,*ansB[4] = {};
    for (int i = 0; i < a; i++)
        ansA[i] = NULL;
    for (int i = 0; i < b; i++)
        ansB[i] = NULL;
    ansA[2] = &B[1], ansA[3] = &B[0], ansB[1] = &C[1], ansB[2] = &C[0];
    /*Check A*/
    for (int i = 0; i < a; i++)
        if (A[i] != ansA[i] )
            printf("A[%d] wrong answer!\n", i);

    /*Check B*/
    for (int i = 0; i < b; i++)
        if (B[i] != ansB[i] )
            printf("B[%d] wrong answer!\n", i);
    return 0;
}

void chasing(int **A[], int a, int *B[], int b, int C[], int c){

    string line;
    vector <bool> output;
    string word;

    while (getline(cin, line)){
        vector <string> words;

        //check end of tests
        if(line=="endtest")
            break;

            //check max lenght of line
        else if (line.size()>64)
            output.push_back(false);

            //validate the instructions
        else {
            stringstream stream(line);
            while (getline(stream, word, ' '))
                if (word!="")
                    words.push_back(word);

            //check character integer character integer
            if (words.size()!=4)
                output.push_back(false);
            else
            {
                //check if the index are digits only
                bool areDigits = true;
                for (int i=0; i<words[1].size(); i++)
                    if (!isdigit(words[1][i]))
                        areDigits=false;
                if (areDigits)
                {
                    int indexFrom = stoi(words[1]);
                    int indexTo = stoi(words[3]);
                    if (words[0]=="A" and words[2]=="B" and indexFrom<a and indexTo<b)
                    {
                        A[indexFrom]=&B[indexTo];
                        output.push_back(true);
                    }
                    else if (words[0]=="B" and words[2]=="C" and indexFrom<b and indexTo<c)
                    {
                        B[indexFrom]=&C[indexTo];
                        output.push_back(true);
                    }
                    else
                        output.push_back(false);
                }
            }
        }
    }

    for (int i=0; i<output.size(); i++)
        cout<<output[i]<<endl;
}


//https://judgegirl.csie.org/problem/0/50092
//falta lo de los espacios
//    A 3 B 0