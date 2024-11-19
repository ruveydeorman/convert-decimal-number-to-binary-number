#include <stdio.h>
#include<stdlib.h>
#define SIZE 32

typedef struct {
	int items[SIZE];
	int top;
}Stack;
void init_stack(Stack* ps) {
	return ps->top = -1;
}
int is_empty(Stack* ps) {
	if (ps->top == -1)
		return 1;
	else return 0;
}
int is_full(Stack* ps) {
	if (ps->top == SIZE - 1)
		return 1;
	else return 0;
}
void push(Stack* ps, int item) {
	if (is_full(ps)) {
		printf("stack owerflow!");
	}
	else {
		ps->top++;
		ps->items[ps->top] = item;
	}
}
int pop(Stack* ps) {
	int item;
	if (is_empty(ps)) {
		printf("stack underflow!");
	}
	else {
		item =ps->items[ps->top];
		ps->top--;
		return item;
	}
}
void decimal_to_binary(int n) {
	Stack s;
	init_stack(&s);
	if (n == 0) {
		printf("binary:0\n");
	}
	while (n > 0) {
		push(&s, n % 2);
		n = n / 2;

	}
	printf("binary:");
	while (!is_empty(&s)) {
		printf("%d", pop(&s));

	}

}
int main() {
	printf("decimal to binary\n\n");
	printf("enter an int:");
	int n;
	scanf_s("%d", &n);
	decimal_to_binary(n);
}
