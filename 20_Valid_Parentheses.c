#define SIZE 10000

int stack[SIZE];
int top = -1;

void push(int value){

    if(top == SIZE - 1){
        return;
    }

    top++;
    stack[top] = value;
}

void pop(){

    if(top == -1){
        return;
    }

    top--;
}

bool check(char s){

    if(top == -1) return false;

    if(s == ')' && stack[top] == '(') return true;
    if(s == ']' && stack[top] == '[') return true;
    if(s == '}' && stack[top] == '{') return true;

    return false;
}

bool isValid(char* s) {

    top = -1;

    int i = 0;

    while(s[i] != '\0'){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){

            push(s[i]);
        }

        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

            if(!check(s[i])){
                return false;
            }

            pop();
        }

        i++;
    }

    return top == -1;
}
