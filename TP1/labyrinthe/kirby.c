#include <kirby.h>

int main(void) {
  createWorld("maze.kirby-map");
  setSpeed(100);
  turnLeft();
  turnLeft();
  move();
  move();
  move();
  turnLeft();
  move();
  move();
  turnLeft();
  turnLeft();
  turnLeft();
  move();
  turnLeft();
  move();
  move();
  turnLeft();
  move();
  move();
  turnLeft();
  move();
  turnLeft();
  turnLeft();
  turnLeft();
  move();
  move();
  turnLeft();
  move();
  getFruit();
  cleanWorld();
  return 0;
}
