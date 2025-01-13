#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int maxNumber) {

    cout << "GAME CONSTRUCTOR: object initialized with "<<maxNumber<<" as maximum value" << endl;

    this->maxNumber=maxNumber;
    numOfGuesses = 0;
    srand(time(0));
    randomNumber = rand()%maxNumber+1;

}

Game::~Game() {

    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play(){
    do{
        cout<<"Arvaa luku valilta 1-"<<maxNumber<<":";
        cin >> playerGuess;
        numOfGuesses++;

        if(playerGuess > randomNumber){
            cout<<"Liian iso! Yrita uudelleen."<<endl;
        }
        else if(playerGuess < randomNumber){
            cout <<"Liian pieni! Yrita uudelleen."<<endl;
        }}
    while(playerGuess != randomNumber);

    printGameResult();

}

void Game::printGameResult(){
    cout<<"Arvasit oikein! Numero oli: "<<randomNumber<<endl;
    cout<<"Arvasit "<< numOfGuesses <<" kertaa."<<endl;
}
