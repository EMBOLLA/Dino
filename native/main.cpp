#include <iostream>
#include <conio.h> 
#include <windows.h> 



const int LARGEUR = 30;
const int HAUTEUR = 10;
int positionDinosaure = HAUTEUR - 2;
bool saut = false;


void gererSaut();
void afficherJeu(int positionObstacle);


int main(int argc , char** argv) {
    int positionObstacle = LARGEUR - 1;
    std::cout << "Appuie sur ESPACE pour sauter !\n";
    
    while (true) {
        if (_kbhit()) 
        {
            char touche = _getch();
            if (touche == ' ') saut = true;
        }

        gererSaut();
        afficherJeu(positionObstacle);

        if (positionObstacle == 5 && positionDinosaure == HAUTEUR - 2) 
        {
            std::cout << "\nGame Over !\n";
            break;
        }

        positionObstacle--;
        if (positionObstacle < 0) positionObstacle = LARGEUR - 1;
        Sleep(100);
    }
    
    return 0;
}


void afficherJeu(int positionObstacle) {
    system("cls");
    for (int i = 0; i < HAUTEUR; i++) 
    {
        for (int j = 0; j < LARGEUR; j++)
         {
            if (i == positionDinosaure && j == 5) std::cout << "D"; 
            else if (i == HAUTEUR - 1) std::cout << "_"; 
            else if (j == positionObstacle && i == HAUTEUR - 2) std::cout << "O"; 
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void gererSaut() {
    if (saut)
     {
        positionDinosaure = HAUTEUR - 5;
        Sleep(500);
        positionDinosaure = HAUTEUR - 2;
        saut = false;
    }
}
