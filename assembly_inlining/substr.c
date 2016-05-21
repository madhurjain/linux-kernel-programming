/* Sub string using gcc inline assembly */

#include <stdio.h>
#include <string.h>

static inline char *sub_str(char *dst, char *src, int start, int end) {
	char *index = src + start;
	char *dPtr = dst;
	end = end - start + 1;
	while(end-- && *index) {
		*dPtr++ = *index++;
	}
	*dPtr = '\0';
	return dst;
}

static inline char *asm_sub_str(char *dst, char *src, long int start, long int end) {
	long int d0, d1, d2; // long int because address is 64-bit by default on 64-bit OS
	__asm__ __volatile__ (
		"add %5, %0\n"	// ESI = ESI + start
		"sub %5, %6\n"	// end = end - start
		"inc %6\n"	// end++
		"1: lodsb\n"	// ESI -> EAX
		"stosb\n"	// EAX -> EDI
		"dec %6\n"	// end--
		"jne 1b\n"	// jump to 1 if not 0
		"mov $0, %2\n"	// '\0' -> EAX
		"stosb"		// EAX -> EDI
		:"=&S" (d0), "=&D" (d1), "=&A" (d2)
		: "0" (src), "1" (dst), "b" (start), "c" (end)
		: "memory"
	);
	return dst;
}

int main(char *argc, char **argv) {
	char src[100], dst1[100], dst2[100];
	char *d1, *d2;
	int start, end;

	// get string and starting and ending indices from command line	
	printf("Enter a string: ");
	scanf("%[^\n]s", src);
	printf("Enter start index and end index: ");
	scanf("%d %d", &start, &end);
	
	// sub string in C	
	d1 = sub_str(dst1, src, start, end);

	// sub string in assembly
	d2 = asm_sub_str(dst2, src, start, end);

	printf("Entered String: [%s]\nSubstring in C:   [%s]\nSubstring in asm: [%s]\n", src, d1, d2);

	printf("strcmp result = %d\n", strcmp(d1, d2));

	return 0;
}


