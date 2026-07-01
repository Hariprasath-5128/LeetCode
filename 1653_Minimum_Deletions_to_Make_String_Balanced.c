char stack[100000];
int top = -1;

// Push
void push(char ch) {
    stack[++top] = ch;
}

// Pop
char pop() {
    return stack[top--];
}

// Peek (Top element)
char peek() {
    return stack[top];
}

// Check if empty
bool isEmpty() {
    return top == -1;
}

//According to the question: the sequence should be -> a^m b^n where m, n > 0
int minimumDeletions(char* s) {
    memset(stack, '\0', 1000 * sizeof(char));
    top = -1;
    int n = strlen(s);

    int deleteCount = 0;

    for(int i = 0; i < n; i++){

        if(!isEmpty() && peek() == 'b' && s[i] == 'a'){
            deleteCount++;
            pop();
        }

        else{
            push(s[i]);
        }
    }

    return deleteCount;
}
