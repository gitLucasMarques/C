#include <stdio.h>
#include <string.h>

// a b c d e f
// c d o f h i j

int main() {
  char s1[50], s2[50];
  int j, p, auxCount = 0, count = 0, i = 0, f = 0;

  fgets(s1, 50, stdin);
  s1[strlen(s1) - 1] = '\0';

  fgets(s2, 50, stdin);
  s2[strlen(s2) - 1] = '\0';

  for (j = 0; j < strlen(s1); j++) {
    for (p = 0; p < strlen(s2); p++) {
      if (s1[j] != s2[p]) {
        count = 0;
      } else {
        if (s1[j] == s2[p] && count == 0) {
          count++;
          j++;
        }
        if (s1[j] == s2[p] && count != 0) {
          count++;
          j++;
          
        }
      }
      auxCount = count;
    }
  }

  printf("%d", auxCount);

  return 0;
}