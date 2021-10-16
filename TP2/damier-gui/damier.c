#include <tps.h>

int main(void) {
  tps_createWindow("Titre", 800, 600);
  while(tps_isRunning()) {
    tps_background(255,255,255);
    tps_setColor(0,0,0);
    int k=20;
    int  l=20;
    for (int i=20; i<=780; i+=40)
    {
        for (int m=20; m<=780; m+=40)
            tps_fillRect(i, m, 20, 20);
    }
    for (int i=0; i<=780; i+=40)
    {
        for (int m=0; m<=780; m+=40)
            tps_fillRect(i, m, 20, 20);
    }
    tps_render();
  }
  tps_closeWindow();
  return 0;
}