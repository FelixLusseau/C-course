#include <tps.h>

int main(void) {
  tps_createWindow("Titre", 800, 600);
  while(tps_isRunning()) {
    tps_background(255,255,255);
    tps_setColor(0,0,0);
    int k=20;
    for (int i=20; i<=780; i+=20)
        tps_drawLine(i, 0, i, 600);
    for (int j=20; j<+580; j+=20)
        tps_drawLine(0, j, 800, j);
    tps_render();
  }
  tps_closeWindow();
  return 0;
}