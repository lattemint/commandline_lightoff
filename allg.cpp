#include "allg.h"

charte::charte():stepcount(0)
 {}

void charte::printe(){
  std::cout << "Step: " << stepcount << '\n';
  for (int i = 0; i < 5; i++) {
    std::cout << i << ":\t";
    for (int j = 0; j < 5; j++) {
      //std::cout << this->chart[i][j] << "|";
      std::cout << pri(i,j) << " | ";
    }
    std::cout << '\n';
  }
}

int charte::pri(int x, int y) {
  if (chart[x][y]) {
    return 1;
  } else {
    return 0;
  }
}

void charte::touch(int x, int y){
  if (range(x,y)) {
    toggle(x,y);
  }
  if (range(x-1,y)) {
    toggle(x-1,y);
  }
  if (range(x+1,y)) {
    toggle(x+1,y);
  }
  if (range(x,y-1)) {
    toggle(x,y-1);
  }
  if (range(x,y+1)) {
    toggle(x,y+1);
  }
  stepcount ++;
}

void charte::toggle(int x,int y){
  if (chart[x][y]) {
    chart[x][y] = false;
  } else {
    chart [x][y] = true;
  }
}

bool charte::range(int x, int y){
    if (x > -1 && x < 5) {
      if (y > -1 && y < 5) {
        return true;
      }
    }
  return false;
}


void charte::reset_all(){
  reset_chart();
  reset_counter();
}

void charte::reset_counter(){
  stepcount = 0;
}

void charte::reset_chart(){
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      chart [i][j] = false;
    }
  }
}

void charte::shell(){
  int x, y;
  std::string ins = "";
  while (true) {
    std::cout << '\n';
    printe();
    std::cout << "instruction: ";
    //getline(std::cin, ins);
    std::cin >> ins;
    //std::cout << "*" << ins << "*" << '\n';
    if (ins == "quit" || ins == "q") {
      break;
    } else if (ins == "touch" || ins == "t") {
      std::cout << "touch anyone, in x y" << '\n';
      std::cout << "x y: ";
      std::cin >> x >> y;
      if (range(x,y)) {
        touch(x,y);
      } else {
        std::cout << "fail to touch.." << '\n';
      }
    } else if (ins == "re") {
      std::cout << "reseting counter..." << '\n';
      reset_counter();
    } else if (ins == "set") {
      std::cout << "reset board..." << '\n';
      reset_chart();
    } else if (ins == "reset") {
      std::cout << "reset all..." << '\n';
      reset_all();
    } else if (ins == "help") {
      std::cout << "Avaliable instruction:" << '\n';
      std::cout << "quit: quit this game. " << '\n';
      std::cout << "touch x y: touch x,y to see changes. " << '\n';
      std::cout << "re: reset counter. " << '\n';
      std::cout << "set: reset board. " << '\n';
      std::cout << "reset: reset counter and board. " << '\n';
      std::cout << "help: print this message. " << '\n';
    }
    std::cout << '\n';
  }
}
