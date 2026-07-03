int calculate(char* s) {
    long long stack[300005], top = -1;
    long long result = 0, num = 0, sign = 1;

    for(int i = 0; s[i]; i++){
        if(isdigit(s[i]))
            num = num * 10 + (s[i] - '0');

        else if(s[i] == '+' || s[i] == '-'){
            result += sign * num;
            num = 0;
            sign = (s[i] == '+') ? 1:-1;
        }

        else if(s[i] == '('){
            stack[++top] = result; //append the before result
            stack[++top] = sign; //Append the before sign
            //Reset for new calculation inside the brackets
            result = 0; 
            sign = 1;
        }

        else if(s[i] == ')'){
            result += sign*num;
            num = 0;
            result *= stack[top--];
            result += stack[top--];
        }
    }
    result += sign * num; //Last number

    return (int)result;
}
