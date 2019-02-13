#include <iostream>
#include <cmath>
#include <cstring>

struct charte{
  int stepcount;
  bool chart [5][5]={{false, false, false, false, false},
                     {false, false, false, false, false},
                     {false, false, false, false, false},
                     {false, false, false, false, false},
                     {false, false, false, false, false}};

  charte();
  void printe();
  int pri(int x, int y);
  void touch(int x, int y);
  void toggle(int x,int y);
  bool range(int x, int y);

  void reset_all();
  void reset_counter();
  void reset_chart();
  void shell();
};
