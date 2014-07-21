#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define P_MAX 3

int main() {
  int pid[P_MAX];
  int status, i;

  for (i = 0; i < P_MAX; i++) {
    pid[i] = fork();
    if (pid[i] == 0) {
      printf("子プロセス No.%d: 開始\n", i);
      sleep(i+1);
      printf("子プロセス No.%d: 終了\n", i);
      exit(0);
    } else {
      printf("親プロセス: 子プロセス No.%d(pid=%d)を開始\n", i, pid[i]);
    }
  }
  printf("すべての子プロセスの終了を待ちます\n");
  for (i = 0; i < P_MAX; i++) {
    wait(&status);
  }
  return 0;
}
