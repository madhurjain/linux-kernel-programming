/* strcpy using gcc inline assembly */
/* gcc asm_strcpy.c -o asm_strcpy */

#include <stdio.h>
#include <string.h>

char * asm_strcpy(char *dest, char *src);

int main() {
  char *s, d[100], *e;
  char f[100], *g;
  s="Hello, World!";
  printf("----------\n");
  printf("before: s=[%s] d=[%s] e=[%s]\n",s,d,e);
  e = asm_strcpy(d,s);
  printf("after:  s=[%s] d=[%s] e=[%s]\n",s,d,e);
  printf("----------\n");

  printf("before: s=[%s] f=[%s] g=[%s]\n",s,f,g);
  g = strcpy(f,s);
  printf("after:  s=[%s] f=[%s] g=[%s]\n",s,f,g);

  return 0;
}

char * asm_strcpy(char *dst, char *src){
  int rsrc, rdst;

  __asm__ 
    __volatile__( 
		 "1:\tlodsb\n\t;"
		 "stosb\n\t;"
		 "testb %%al,%%al\n\t;"
		 "jne 1b;"
		 : "=&S" (rsrc), "=&D" (rdst)
		 : "0" (src),"1" (dst) 
		  );
  
  return dst;
}

