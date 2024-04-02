#include "stack.c"

int main(){

    Stack *S = Stack_create();
    int top_val;

    Stack_print(S);

    // puts("\nPeeking:");
    // top_val = Stack_peek(S);
    // printf("Top val: %d\n", top_val);

    // puts("\nPopping");
    // top_val = Stack_pop(S);
    // printf("Top val: %d\n", top_val);

    puts("Pushing 0, 10, 20:");
    Stack_push(S, 0);
    Stack_push(S, 10);
    Stack_push(S, 20);
    Stack_print(S);

    puts("\nPeeking:");
    top_val = Stack_peek(S);
    printf("Top val: %d\n", top_val); 
    Stack_print(S);

    puts("\nPopping:");
    top_val = Stack_pop(S);
    printf("Top val: %d\n", top_val); 
    Stack_print(S);

    puts("\nPushing 20, 30, 40: ");
    Stack_push(S, 20);
    Stack_push(S, 30);
    Stack_push(S, 40);
    Stack_print(S);
    long s = Stack_size(S);
    printf("Size: %ld\n", s);

    return 0;
}