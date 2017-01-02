#include "thinker.h"

void think(int sig){
  sig = 0;
  if(serverinfo->startcalc == 1){
    printf("Thinker\n");
    //printServerInfo();
    serverinfo->startcalc = 0;
  }
}

void printServerInfo(void){
  printf("gamename: %s\n",serverinfo->gamename);
  printf("clientname: %s\n",serverinfo->clientname);
  printf("clientplayernr: %i\n",serverinfo->clientplayernr);
  printf("totalplayers: %i\n",serverinfo->totalplayers);
  printf("pid Connector: %i\n",serverinfo->pid_connector);
  printf("pid Thinker: %i\n",serverinfo->pid_thinker);

  for (int i = 0; i < serverinfo->totalplayers-1; i++) {
    printf(" playername %s\n",serverinfo->otherplayers[i]->playername);
    printf(" playernr %i\n",serverinfo->otherplayers[i]->playernr);
    printf(" playerready %i\n",serverinfo->otherplayers[i]->ready);
  }

  printfield();
}