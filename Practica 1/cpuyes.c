#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define CICLOS 50000000

int main(int argc, char *argv[]) {
  long long start_ts;
  long long stop_ts;
  float elapsed_time;
  struct timeval ts;
  int i, j;
  int porc;

  if (argc<2)
       porc = 100;

  else
      porc = atoi(argv[1]);

  printf("CPU=%d, E/S=%d\n", porc, 100 - porc);

  gettimeofday(&ts, NULL);
  start_ts = ts.tv_sec*1000000.0 + ts.tv_usec; // Tiempo inicial

  for (i = 0; i<porc; i++) // Ejecutar instrucciones del CPU
             for (j = 0; j<CICLOS; j++); // Uso intensivo del CPU


  usleep((100 - porc) * 100000);

  gettimeofday(&ts, NULL);
  stop_ts = ts.tv_sec*1000000.0 + ts.tv_usec; // Tiempo inicial

  elapsed_time = (float) (stop_ts - start_ts) /1000000.0;
  printf("proceso %d, %2.2f segundos\n", (int) getpid(), elapsed_time);
}
