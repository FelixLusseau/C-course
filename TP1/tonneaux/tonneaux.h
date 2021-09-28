#include <stdlib.h>

int _tonneau3;
int _tonneau5;

void debug() {
  printf("[");
  for(int i = 0; i < 3; ++i) {
    printf("%c", i < _tonneau3 ? '#' : ' ');
  }
  printf("] ");
  printf("[");
  for(int i = 0; i < 5; ++i) {
    printf("%c", i < _tonneau5 ? '#' : ' ');
  }
  printf("]\n");
}

void remplir(int t) {
  switch(t) {
    case 3:
      _tonneau3 = 3; break;
    case 5:
      _tonneau5 = 5; break;
    default:
      printf("Tonneau %i inconnu\n", t); exit(1);
  }
  debug();
}
void transferer(int t1, int t2)
{
  if(t1 != 3 && t1 != 5) {
    printf("Tonneau %i inconnu\n", t1);
    exit(1);
  }
  if(t2 != 3 && t2 != 5) {
    printf("Tonneau %i inconnu\n", t2);
    exit(1);
  }
  if(t1 == t2){
    printf("Impossible de verser un tonneau dans lui-même\n");
    exit(1);
  }
  if(t1 == 3) {
    int m = _tonneau5 + _tonneau3 > 5 ? 5 - _tonneau5 : _tonneau3;
    _tonneau5 += m;
    _tonneau3 -= m;
  } else {
    int m = _tonneau5 + _tonneau3 > 3 ? 3 - _tonneau3 : _tonneau5;
    _tonneau3 += m;
    _tonneau5 -= m;
  }
  debug();
}
void vider(int t) {
  switch(t) {
    case 3:
      _tonneau3 = 0; break;
    case 5:
      _tonneau5 = 0; break;
    default:
      printf("Tonneau %i inconnu\n", t); exit(1);
  }
  debug();
}
