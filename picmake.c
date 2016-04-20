#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

int main(){
  int filey;
  int r, g, b;
  char *header = "P3 401 401 255\n";
  char buffer[100];

  printf("%s",header);
  filey = open( "newpix.ppm", O_CREAT | O_TRUNC | O_RDWR, 0666 );
  if (filey == -1){
    printf("error num %d: %s",errno, strerror(errno));
    return errno;
  }
  write (filey, header, strlen(header) );
  if (errno){
    printf("error num %d: %s",errno, strerror(errno));
    return errno;
  }
  for (int i=0;i<401;i++){
    for (int j=0;j<401;j++){
      r = sin((j)/5.)*cos((i)/5.)*128+127;
      b = sin((j)/5.-15.7)*cos((i)/5.-15.7/2)*128+127;
      g = sin((pow(j,2)+pow(i,2))/9)*128+127;
      int si = sprintf(buffer, "%d %d %d ", (int)r, (int)g, (int)b);
      write (filey, buffer, si);
      if (errno){
	printf("error num %d: %s",errno, strerror(errno));
	return errno;
      }
    }
  }
  printf("successsssss :)))))))))");
  close(filey);
}
