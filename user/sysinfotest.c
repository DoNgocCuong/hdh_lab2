

#include "user/user.h"
#include "kernel/sysinfo.h"

void sysinfotest(void) {
  struct sysinfo info;

  if (sysinfo(&info) < 0) {
    printf("sysinfotest: sysinfo failed\n");
    exit(1);
  }

  if (info.freemem == 0 || info.nproc == 0) {
    printf("sysinfotest: invalid sysinfo values\n");
    exit(1);
  }

  printf("sysinfotest: OK\n");
}

int main(int argc, char *argv[]) {
  sysinfotest();
  exit(0);
}