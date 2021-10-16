#include <tps.h>

int main(void) {
  tps_createWindow("Titre", 800, 600);
  while(tps_isRunning()) {
    tps_background(255,255,255);
    tps_setColor(0,155,0);
    tps_fillRect(0, 350, 800, 300);
    tps_setColor(200,200,0);
    tps_fillRect(150, 200, 400, 300);
    tps_setColor(255,0,0);
    tps_fillTriangle(150, 200, 550, 200, 350, 50);
    tps_render();
  }
  tps_closeWindow();
  return 0;
}