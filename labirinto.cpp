#include <iostream>

using namespace std;

const char WIDTH = 20, HEIGHT = 10;
unsigned char player = {'*'};
int posX = 1, posY = 1;
unsigned char action;

void playerAction();

struct enemies{
  char symbol;
  bool active;
  int x;
  int y;
};

unsigned char maze[HEIGHT][WIDTH] = {
{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
{'0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '1', '0', '1', '0', '0', '1', '0'},
{'0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1', '0', '0'},
{'0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '0', '0', '0'},
{'0', '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '0', '0'},
{'0', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '0', '0', '1', '0', '0', '0', '0', '0'},
{'0', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1', '1', '0', '0'},
{'0', '1', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0'},
{'0', '1', '0', '1', '0', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '2', '0'},
{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, };


  void playerAction(){
    cout << "\nAction: ";
    cin >> action;

    int prevposX = posX;
    int prevposY = posY;
    unsigned char space = {32};

    switch(action){
      case 'a':
        if(maze[posX][posY-1] != '0'){
          posY--;
       // cout << posX << ',' << posY << endl;
        maze[prevposX][prevposY] = space;
        }
      system("clear");
      break;

      case 'd':
        if(maze[posX][posY+1] != '0'){
          posY++;
       // cout << posX << ',' << posY << endl;
        maze[prevposX][prevposY] = space;
        }
      system("clear");
      break;

      case 's':
        if(maze[posX+1][posY] != '0'){
          posX++;
       // cout << posX << ',' << posY << endl;
        maze[prevposX][prevposY] = space;
        }
      system("clear");
      break;

      case 'w':
        if(maze[posX-1][posY] != '0'){
          posX--;
       // cout << posX << ',' << posY << endl;
        maze[prevposX][prevposY] = space;
        }
      system("clear");
      break;

      default:
      cout << "Incorrect action!" << endl;
      break;
      }
    }

int main(){
  int s = 2, saiu = 0;
  while(saiu==0){
    cout << "Controle o seu jogador usando WASD." << endl;
    cout << "Cuidado com os INIMIGOS: X, Y, Z" << endl;
    cout << endl;

    maze[posX][posY] = player;

    for(int y=0; y < HEIGHT; y++){
      cout << endl;
      for(int x = 0; x < WIDTH; x++){
        cout << maze[y][x];
      }

    //first list enemy  
    enemies enemy1;
    enemy1.symbol = 'X';
    enemy1.active = true;
    enemy1.x = 3;
    enemy1.y = 6;
    maze[enemy1.y][enemy1.x] = enemy1.symbol;

    //second list enemy  
    enemies enemy2;
    enemy2.symbol = 'Y';
    enemy2.active = true;
    enemy2.x = 8;
    enemy2.y = 1;
    maze[enemy2.y][enemy2.x] = enemy2.symbol;

    //three list enemy  
    enemies enemy3;
    enemy3.symbol = 'Z';
    enemy3.active = true;
    enemy3.x = 17;
    enemy3.y = 8;
    maze[enemy3.y][enemy3.x] = enemy3.symbol;
  }
      playerAction();
    if(maze[posX][posY] == '2'){
      saiu++;
      cout << "Voce conseguiu sair do labrinto!";
    }
    if(maze[posX][posY] == 'X'){
      saiu++;
      cout << "que pena! Você perdeu!";
    }
    if(maze[posX][posY] == 'Y'){
      saiu++;
      cout << "que pena! Você perdeu!";
    }
    if(maze[posX][posY] == 'Z'){
      saiu++;
      cout << "que pena! Você perdeu!";
    }
  }
    return 0;
}




