#include<bits/stdc++.h> 
using namespace std; 
   
void printWords(string str) { 
    // word variable to store word 
    string word; 
    // making a string stream 
    stringstream iss(str); 
    // Read and print each word. 
    while (iss >> word){ 
        reverse(word.begin(),word.end()); 
        cout<<word<<" "; 
    } 
} 

int main() { 
    string s;
    fflush(stdin);
    getline(cin, s);
    printWords(s); 
    return 0; 
} 
