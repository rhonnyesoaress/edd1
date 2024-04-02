
#include "static_stack.c"

int main(){

    StaticStack *S = StaticStack_create(5);
    int top_val;

    StaticStack_print(S);

    // puts("\nPeeking:");
    // top_val = StaticStack_peek(S);
    // printf("Top val: %d\n", top_val);

    // puts("\nPopping");
    // top_val = StaticStack_pop(S);
    // printf("Top val: %d\n", top_val);

    puts("Pushing 0, 10, 20:");
    StaticStack_push(S, 0);
    StaticStack_push(S, 10);
    StaticStack_push(S, 20);
    StaticStack_print(S);

    puts("\nPeeking:");
    top_val = StaticStack_peek(S);
    printf("Top val: %d\n", top_val); 
    StaticStack_print(S);

    puts("\nPopping:");
    top_val = StaticStack_pop(S);
    printf("Top val: %d\n", top_val); 
    StaticStack_print(S);

    puts("\nPushing 20, 30, 40: ");
    StaticStack_push(S, 20);
    StaticStack_push(S, 30);
    StaticStack_push(S, 40);
    StaticStack_print(S);
    long s = StaticStack_size(S);
    printf("Size: %ld\n", s);

    return 0;
}