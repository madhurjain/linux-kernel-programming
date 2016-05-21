/* Sum of numbers between x and y using gcc inline assembly */

#include <stdio.h>

int asm_sum(int x, int y) {
	int op;
	__asm__ __volatile__ (
		"movl $0, %0\n"		// OP = 0	
		"loop: cmpl %1, %2\n"	// Check x < y
		"jl exit\n"		// exit if equal
		"addl %1, %0\n"		// OP = OP + x
		"incl %1\n"		// x++
		"jmp loop\n"		// loop to check above
		"exit: nop"		
		: "=&r" (op)		// output
		: "r" (x), "r" (y)	// input
		: // clobber list
	);
	printf("\nx = %d, y = %d\n", x, y);
	return op;
}

int main(int argc, int **argv) {
	int a, b;
	printf("Enter x and y: ");
	scanf("%d %d", &a, &b);
	printf("\nSum is: %d\n", asm_sum(a, b));
	return 0;
}
