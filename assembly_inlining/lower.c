/* toLower using gcc inline assembly */

#include <stdio.h>
#include <string.h>

static inline char *asm_lower(char *dst, char *src) {
	int d0, d1; 
	__asm__ __volatile__ (
		"ld: lodsb\n"			// ESI -> EAX
		"mov %%al, %%bl\n"		// EAX -> EBX
		"cmp $0x41, %%bl\n"		// Char < 65?
		"jl cnt\n"			// Skip
		"cmp $0x5A, %%bl\n"		// Char > 90?
		"jg cnt\n"			// Skip
		"add $0x20, %%bl\n"		// Add 32 to char to make it lower before storing
		"cnt:\n"
		"mov %%bl, %%al\n"		// EBX -> EAX
		"stosb\n"			// EAX -> EDI
		"testb %%al, %%al\n"		// AND AL with AL (Check if AL=\0)
		"jne ld\n"			// jump to load if not \0
		:"=&S" (d0), "=&D" (dst)
		: "0" (src), "1" (dst)
		: "memory"
	);
	return dst;
}

int main(char *argc, char **argv) {
	char src[100], dst[100];
	char *start = src;
	// get string from command line
	printf("Enter a string: ");
	scanf("%[^\n]s", src);
	asm_lower(dst, src);

	printf("\nlower result = %s\n", dst);

	return 0;
}


