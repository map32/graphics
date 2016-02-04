#include <fcntl.h>
#include <stdin.h>
#include <stdout.h>
#include <strlib.h>

int main(){
  int filey;
  int r, g, b;
  char* header = "P3 100 100 255\n";

  filey = open( "newpix.ppm", O_CREAT | O_TRUNC | O_RDWR );

  write (filey, header, strlen(header) );
  
  for (int i=0;i<100;i++){
    for (int j=0;j<100;j++){
      r += i;
      r = r % 255;
      g = (int)(r *
      sprintf (filey, "%d %d %d", 
    }
  }

}
