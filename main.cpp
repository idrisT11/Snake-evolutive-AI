#include <iostream>
#include "Azdviw.h"

int main(int argc, char const *argv[]) {

  int layers[4] = {400, 69, 69, 4};
  char mode;
  Azdviw smartSnake(layers, 4);

  std::cout << "==============Azrem==============" << "\n\n";
  std::cout << "  -1)----> Learning Mode." << '\n';
  std::cout << "  -2)----> Playing Mode." << '\n';
  std::cout << ">>>  " ;
  std::cin >> mode;

  if (mode == '1')
    smartSnake.evoluate(10, 100, 10, 0.05);
  else if (mode == '2')
    smartSnake.play();




  return 0;
}
