#include <stdio.h>

int main() {
  int k = 1, n, m, x, y;
  int i;

  while (k != 0) {
    scanf("%d", &k);
    if (k <= 1000) {
      scanf("%d %d", &n, &m);
      if (n > -10000 && m < 10000) {
        for (i = 0; i < k; i++) {
          scanf("%d %d", &x, &y);
          if (x >= -10000 && y <= 10000) {
            if (x == n || y == m) {
              printf("divisa\n");
            }

            if (x < n && y < m) {
              printf("SO\n");
            }

            if (x < n && y > m) {
              printf("NO\n");
            }

            if (x > n && y < m) {
              printf("SE\n");
            }

            if (x > n && y > m) {
              printf("NE\n");
            }
          }
        }
      }
    }
  }

  return 0;
}