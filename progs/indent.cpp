#include<string.h>
#include<iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    const char* outFile="indented.log";
    const char *pad="\t", *inFile;

    if(argc==3){
        inFile=argv[1];
        outFile=argv[2];
    }
    else if(argc==2)
        inFile=argv[1];
    else{
        cout<<"arg0: log file, arg1: optional outfile"<<endl;
        return 0;
    }

    char ch;
    ifstream fin(inFile, fstream::in);
    ofstream out (outFile);
    int lenpad = strlen(pad);

    int indent = -1; // Miss one indentaion
    while (fin >> noskipws >> ch) {
        out.put(ch);
        if(ch == '(')   indent++;
        else if(ch == ')')   indent--;
        else if(ch == '\n'){
            for(int j=0; j<indent; j++){
                for(int i=0; i<lenpad; i++){
                    out.put(pad[i]);
                }
            }
        }
    }
    fin.close();
    out.close();
    cout<<"Output written to file "<<outFile<<endl;
    return 0;
}
