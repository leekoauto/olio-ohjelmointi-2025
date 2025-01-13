#include "game.h"
#include <iostream>
using namespace std;

int main()
{
    int maxNumber;
    cout<<"Anna maksimiarvo arvauspelille: ";
    cin >> maxNumber;

    Game game(maxNumber);
    game.play();

    return 0;
}
