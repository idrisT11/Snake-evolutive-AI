
int play(Azdviw snaku, bool show){
  int grille[20][20] = {0},
      taille = 1;

  bool continue = true;

  point tete;
  tete.x = 10,
  tete.y =10,

  grille[10][10] = 1;

  while ( continue ) {

    spawnFruit(grille);

    int result = snaku.getParsesOutput(grille, tete);

    switch ( result ) {
      case HAUT:
      if (  tete.y  < 20 - 1 ) {
        if ( grille[tete.x][tete.y+1] == 0 ){
          grille[tete.x][tete.y+1] = taille;
          fruit = false;
        }else if ( grille[tete.x][tete.y+1] == -1 ){
          taille++;
          grille[tete.x][tete.y+1] = taille;
        }
      }

      case BAS:
      if (  tete.y  > 0 ) {
        if ( grille[tete.x][tete.y-1] == 0 ){
          grille[tete.x][tete.y-1] = taille;
          fruit = false;
        }else if ( grille[tete.x][tete.y-1] == -1 ){
          taille++;
          grille[tete.x][tete.y-1] = taille;
        }
      }
      case GAUCHE:
      if (  tete.x  > 0 ) {
        if ( grille[tete.x-1][tete.y] == 0 ){
          grille[tete.x-1][tete.y] = taille;
          fruit = false;
        }else if ( grille[tete.x-1][tete.y] == -1 ){
          taille++;
          grille[tete.x-1][tete.y] = taille;
        }
      }
      case DROITE:
      if (  tete.x  < 20 - 1 ) {

        if ( grille[tete.x+1][tete.y] == 0 ){
          grille[tete.x+1][tete.y] = taille;
          fruit = false;
        }else if ( grille[tete.x+1][tete.y] == -1 ){
          taille++;
          grille[tete.x+1][tete.y] = taille;
        }
      }
    }

    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++)
        if (grille[i][j] > 0)
          grille[i][j]--;


    if (show) {
      system('cls');
      for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++)
          if ( grille[i][j] == -1 ) {
            printf("X");
          }
          else if ( grille[i][j] > 0 ) {
            printf("O");
          }
        printf("\n");
      }

      sleep(1000);
    }

  }

}

point spawnFruit(int grille[20][20]){
  point fruit;
  do {
    fruit.x = rand()%20;
    fruit.y = rand()%20;
  } while(grille[fruit.x][fruit.y] != 0);

  grille[fruit.x][fruit.y] = -1;

  return fruit;
}
