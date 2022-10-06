#include <stdio.h>
#include <stdlib.h>

#define ERROR (printf("ERROR\n"))



int main(int argc, char **argv) {
  if (argc <= 1) return 0;

  char arr[4] = {0,0,0,0};
  for (int i = 1 ; i < argc ; ++i) {
    int j = 0;
    for (; j < 4 ; ++j) {
      if (arr[j] == 0) {
        arr[j] = argv[i][0];
        break;
      }
      if (arr[j] == argv[i][0]) break;
    }
    if (j == 4) {
      //make stack
      char pos[4] = {-1,-1,-1,-1};
      char stack[9999];
      int stack_size = 0;
      for (int p = i + 1; p < argc - 1 ; ++p) {
        int k = p + 1;
        for (; k < argc ; ++k) {
          if (argv[p][0] == argv[k][0]) {
            break;
          }
        }
        if (k == argc) continue;
        else stack[stack_size++] = argv[p][0];
      }
      for (int p = 0 ; p < 4 ; ++p) {
        int k = 0;
        for (; k < stack_size ; ++k) {
          if (arr[p] == stack[k]) {
            pos[p] = k;
            break;
          }
        }
        if (k == stack_size) {
          for (int o = j ; o >= 0 ; ++o) {
            if (argv[o][0] == arr[p])
              pos[p] -= o;
          }
        }
      }
      //set pos
      int minpos = 0;
      int minval = 999;
      for (int v = 0 ; v < 4 ; ++v) {
        if (pos[v] < minval) minpos = v;
      }
      arr[minpos] = argv[j][0];
    }
    printf("%c %c %c %c\n", arr[0],arr[1],arr[2],arr[3]);
  }

}
