#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele){
    if(top<=MAX_SIZE-1){
        a[++top]=ele;
    }
    else{
        cout<<"Stack is full. Cannot push: "<<ele<<"\n";
    }
}

char pop(){
    if(top>=0){
        char ele = a[top];
        top--;
        return ele;
    }
    else{
        cout<<"Stack is empty. Cannot pop.\n";
        return '-1';
    }
}

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top>=MAX_SIZE;
}

int main(){
    string originalString = "Hello, World!";
    int stringLength = originalString.length();

    // Push each character onto the stack
    for (int i=0 ; i<stringLength ; i++){
        char c = originalString[i];
        push(c);
    }

    // Pop the characters from the stack to construct the reversed string
    string reversedString;
    while (!isEmpty()) {
        reversedString.push_back(pop());
    }
    cout<<reversedString<<"\n";
    return 0;
}