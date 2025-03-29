
#include <iostream>
using namespace std;

struct player
{
    int number;
    string name;
    int age;
};

void play(char field[3][3], struct player* spieler);
void input_player(struct player* spieler);
bool draw_game(char field[3][3]);
void drewField(char* p_field);
bool checkWin(char field[3][3]);

int main()
{
    char field[3][3]
    {
        {' ',' ',' '},
         {' ',' ',' '},
          {' ',' ',' '},
    };
    int length = sizeof(field) / sizeof(field[0][0]);

    struct player spieler[2];
    input_player(spieler);

    play(field, spieler);

    return 0;

}


void input_player(struct player spieler[])
{
    for (int i = 0; i < 2; i++)
    {
        cout << " \nYou are player (1) or (2)? ";
        cin >> spieler[i].number;

        if (spieler[i].number != 1 && spieler[i].number != 2)
        {
            cout << "Invalid, try again!!\n";
            i--;
            continue;
        }

        cout << "Enter your name: ";
        cin >> spieler[i].name;
        cout << "Enter your age: ";
        cin >> spieler[i].age;
    }
}

void drewField(char* p_field)
{
    cout << "---------------\n";
    for (int r = 0;r < 3;r++)
    {
        cout << " | ";
        for (int c = 0;c < 3;c++)
        {
            cout << *p_field << " | ";
            p_field++;

        }
        cout << "\n---------------\n";

    }
}
bool checkWin(char field[3][3])// rules
{
    for (int z = 0;z < 3;z++)
    {
        for (int s = 0;s < 3;s++)
        {
            if (field[z][0] == 'X' && field[z][1] == 'X' && field[z][2] == 'X')return true;
            else if (field[0][s] == 'X' && field[1][s] == 'X' && field[2][s] == 'X')return true;
            else  if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X')return true;
            else  if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')return true;
            else if (field[z][0] == 'O' && field[z][1] == 'O' && field[z][2] == 'O')return true;
            else if (field[0][s] == 'O' && field[1][s] == 'O' && field[2][s] == 'O')return true;
            else if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O')return true;
            else if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')return true;
        }
    }

    return false;
}
bool draw_game(char field[3][3])
{
    for (int r = 0;r < 3;r++)
    {
        for (int c = 0;c < 3;c++)
        {
            if (field[r][c] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void play(char field[3][3], struct player spieler[2])
{

    system("cls"); // to clear the screen
    cout << "\033[6;31;43m Welcome to TICTACTOE\033[0m\n\n"; //for the color 
    drewField(&field[0][0]);
    int i = 0;
    /*if (spieler[i].number == 2)
    {
        i++;
    }*/
    int row, column;
    bool draw = false;
    
    while (true)
    {
        draw = draw_game(field);
        if (draw)
        {
            cout << "DRAW!!\n";
            break;
        }
        cout << "Player " << spieler[i].number << " enter the row: ";
        cin >> row;
        cout << "Player " << spieler[i].number << " enter the column: ";
        cin >> column;

        if (row >= 3 || row < 0 || column >= 3 || column < 0)
        {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (field[row][column] != ' ')
        {
            cout << "Your field is already set!!\n";
            continue;
        }

        if (spieler[i].number == 1)
        {
            field[row][column] = 'X';
            if (checkWin(field))
            {
                cout <<endl<< spieler[i].name << "  has won!!";
                break;
            }
            i++;

        }
        else if (spieler[i].number == 2)
        {
            field[row][column] = 'O';
            if (checkWin(field))
            {
                cout <<endl << spieler[i].name << "  has won!!";
                break;
            }
            i--;
        }
   
        drewField(&field[0][0]);

    }
}
