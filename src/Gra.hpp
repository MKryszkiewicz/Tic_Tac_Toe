#include <iostream>
#include <vector>

using namespace std;


class Gra
{
    public:
        Gra();
        void zagraj();
    private:
        void ruch_gracza();
        void ruch_ai();
        void drukuj_plansze();
        bool czy_wygrana(char input);
        bool czy_remis();
        vector<vector<char>> plansza;
};

Gra::Gra() 
{
    plansza = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
}

void Gra::drukuj_plansze() 
{
    cout << "==========" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << "||";
        for (int j = 0; j < 3; j++) 
        {
            cout << plansza[i][j] << " ";
        }
        cout << "||" << endl;
    }
    cout << "==========" << endl;
}

bool Gra::czy_wygrana(char input) 
{
    
    for (int i = 0; i < 3; i++) 
    {
        if (plansza[i][0] == input && plansza[i][1] == input && plansza[i][2] == input) 
        {
            return true;
        }
    }
   
    for (int i = 0; i < 3; i++) 
    {
        if (plansza[0][i] == input && plansza[1][i] == input && plansza[2][i] == input) 
        {
            return true;
        }
    }
    
    if (plansza[0][0] == input && plansza[1][1] == input && plansza[2][2] == input)
    {
        return true;
    }
    if (plansza[0][2] == input && plansza[1][1] == input && plansza[2][0] == input) 
    {
        return true;
    }
    return false;
}

bool Gra::czy_remis() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (plansza[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void Gra::zagraj() 
{
    char input;
    int row, col;
    while (true) 
    {
        //Ruch gracza
        input = 'X';
        ruch_gracza();
        if (czy_wygrana(input)) 
        {
            drukuj_plansze();
            cout << "Wygral symbol  " << input << "!" << endl << endl;
            break;
        }

        //Ruch AI
        input = 'O';
        ruch_ai();

        //Sprawdzanie win condition
        if (czy_wygrana(input)) 
        {
            drukuj_plansze();
            cout << "Wygral symbol  " << input << "!" << endl << endl;
            break;
        }

        //Sprawdzanie remisu
        if (czy_remis()) 
        {
            drukuj_plansze();
            cout << "Remis!" << endl << endl;
            break;
        }

        // if (input == 'X') 
        // {
        //     input = 'O';
        // } 

        // else 
        // {
        //     input = 'X';
        // }   

    }
}

void Gra::ruch_gracza()
{
    char input = 'X';
    int row, col;
    drukuj_plansze();

        cout << endl << "Wprowadz rzad: ";
        cin >> row;
        row = row - 1;

        if (row < 0 || row > 2) 
        {
            cout << "Nieprawidlowy ruch!!! Poza plansza." << endl;
            return;
        }

        cout << endl << "Wprowadz kolumne: ";
        cin >> col;
        cout << endl;
        col = col - 1;

        if (col < 0 || col > 2) 
        {
            cout << "Nieprawidlowy ruch!!! Poza plansza." << endl;
            return;
        }

        if (plansza[row][col] != ' ') 
        {
            cout << "Nieprawidlowy ruch!!! Miejsce zajete." << endl;
            return;
        }

        plansza[row][col] = input;
}

void Gra::ruch_ai()
{
    //ZEROWY POZIOM - jezeli sa gdzies dwa O to dostaw tak nastepne O zebys wygral od razu
        for (int i = 0; i < 3; i++) //WIERSZE
    {
        if (plansza[i][0] == 'O' && plansza[i][1] == 'O' && plansza[i][2] == ' ')
        {
            plansza[i][2] = 'O';
            return;
        }
        if (plansza[i][0] == 'O' && plansza[i][1] == ' ' && plansza[i][2] == 'O')
        {
            plansza[i][1] = 'O';
            return;
        }
        if (plansza[i][0] == ' ' && plansza[i][1] == 'O' && plansza[i][2] == 'O')
        {
            plansza[i][0] = 'O';
            return;
        }
    }

    for (int i = 0; i < 3; i++) //KOLUMNY
    {
        if (plansza[0][i] == 'O' && plansza[1][i] == 'O' && plansza[2][i] == ' ')
        {
            plansza[2][i] = 'O';
            return;
        }
        if (plansza[0][i] == 'X' && plansza[1][i] == ' ' && plansza[2][i] == 'O')
        {
            plansza[1][i] = 'O';
            return;
        }
        if (plansza[0][i] == ' ' && plansza[1][i] == 'O' && plansza[2][i] == 'O')
        {
            plansza[0][i] = 'O';
            return;
        }
    }
    //Jedna przekatna
    if (plansza[0][0] == ' ' && plansza[1][1] == 'O' && plansza[2][2] == 'O')
    {
        plansza[0][0] = 'O';
        return;
    }
    if (plansza[0][0] == 'O' && plansza[1][1] == ' ' && plansza[2][2] == 'O')
    {
        plansza[1][1] = 'O';
        return;
    }
    if (plansza[0][0] == 'O' && plansza[1][1] == 'O' && plansza[2][2] == ' ')
    {
        plansza[2][2] = 'O';
        return;
    }
    //Druga przekatna
    if (plansza[0][2] == ' ' && plansza[1][1] == 'O' && plansza[2][0] == 'O') 
    {
        plansza[0][2] = 'O';
        return;
    }
    if (plansza[0][2] == 'O' && plansza[1][1] == ' ' && plansza[2][0] == 'O') 
    {
        plansza[1][1] = 'O';
        return;
    }
    if (plansza[0][2] == 'O' && plansza[1][1] == 'O' && plansza[2][0] == ' ') 
    {
        plansza[2][0] = 'O';
        return;
    }    
    //PIERWSZY POZIOM - jezeli sa gdzies dwa X to dostaw O tak zeby przeciwnik nie wygral w nastepnym ruchu
    for (int i = 0; i < 3; i++) //WIERSZE
    {
        if (plansza[i][0] == 'X' && plansza[i][1] == 'X' && plansza[i][2] == ' ')
        {
            plansza[i][2] = 'O';
            return;
        }
        if (plansza[i][0] == 'X' && plansza[i][1] == ' ' && plansza[i][2] == 'X')
        {
            plansza[i][1] = 'O';
            return;
        }
        if (plansza[i][0] == ' ' && plansza[i][1] == 'X' && plansza[i][2] == 'X')
        {
            plansza[i][0] = 'O';
            return;
        }
    }

    for (int i = 0; i < 3; i++) //KOLUMNY
    {
        if (plansza[0][i] == 'X' && plansza[1][i] == 'X' && plansza[2][i] == ' ')
        {
            plansza[2][i] = 'O';
            return;
        }
        if (plansza[0][i] == 'X' && plansza[1][i] == ' ' && plansza[2][i] == 'X')
        {
            plansza[1][i] = 'O';
            return;
        }
        if (plansza[0][i] == ' ' && plansza[1][i] == 'X' && plansza[2][i] == 'X')
        {
            plansza[0][i] = 'O';
            return;
        }
    }
    //Jedna przekatna
    if (plansza[0][0] == ' ' && plansza[1][1] == 'X' && plansza[2][2] == 'X')
    {
        plansza[0][0] = 'O';
        return;
    }
    if (plansza[0][0] == 'X' && plansza[1][1] == ' ' && plansza[2][2] == 'X')
    {
        plansza[1][1] = 'O';
        return;
    }
    if (plansza[0][0] == 'X' && plansza[1][1] == 'X' && plansza[2][2] == ' ')
    {
        plansza[2][2] = 'O';
        return;
    }
    //Druga przekatna
    if (plansza[0][2] == ' ' && plansza[1][1] == 'X' && plansza[2][0] == 'X') 
    {
        plansza[0][2] = 'O';
        return;
    }
    if (plansza[0][2] == 'X' && plansza[1][1] == ' ' && plansza[2][0] == 'X') 
    {
        plansza[1][1] = 'O';
        return;
    }
    if (plansza[0][2] == 'X' && plansza[1][1] == 'X' && plansza[2][0] == ' ') 
    {
        plansza[2][0] = 'O';
        return;
    }
    //DRUGI POZIOM - gra tak, zeby nie storzyc okazji do tzw. widelek 
    //Założenie #1 - zawsze staraj sie zajac srodek
    if (plansza[1][1] == ' ')
    {
        plansza[1][1] = 'O';
        return;
    }
    //Założenie #2 - jak to możliwe to zajmuj rogi
    if (plansza[0][0] == ' ')
    {
        plansza[0][0] = 'O';
        return;
    }
    if (plansza[0][2] == ' ')
    {
        plansza[0][2] = 'O';
        return;
    }
    if (plansza[2][0] == ' ')
    {
        plansza[2][0] = 'O';
        return;
    }
    if (plansza[2][2] == ' ')
    {
        plansza[2][2] = 'O';
        return;
    }
    //Stawianie kolka w pierwszej wolnej komorce
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (plansza[i][j] == ' ') 
            {
                plansza[i][j] = 'O';
                return;
            }
        }
    }   
}