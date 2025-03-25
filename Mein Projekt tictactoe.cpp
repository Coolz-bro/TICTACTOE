

#include <iostream>
using namespace std;

struct player
{
    int number;
    char name[30];
    int age;


};
void play(char field[3][3], int length, struct player* spieler);
void input_player(struct player* spieler);
bool draw_game(char field[3][3]);
void drewField(char* p_field);

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

    play(field, length, spieler);

}


void input_player(struct player* spieler)
{
    for (int i = 0;i < 2;i++)
    {
        cout << " \nYou are player (1) or (2)";
        cin >> spieler->number;
        cout << "Enter your name: ";
        cin >> spieler->name;
        cout << "Enter your age : ";
        cin >> spieler->age;
        spieler++;

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
bool checkWin(char field[3][3])
{
    for (int i = 0;i < 3;i++)
    {
        if (field[i][0] || field[i][1] || field[i][2]) return true;
        if (field[0][i] || field[1][i] || field[2][i]) return true;
       
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

void play(char field[3][3], int length, struct player* spieler)
{
    system("cls");  // Beachte: Funktioniert nur unter Windows
    drewField(&field[0][0]);

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
        

        cout << "Player " << spieler->number << " enter the row: ";
        cin >> row;
        cout << "Player " << spieler->number << " enter the column: ";
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

        if (spieler->number == 1)
        {
            field[row][column] = 'X';
            spieler->number = 2;
        }
        else if (spieler->number == 2)
        {
            field[row][column] = 'O';
            spieler->number = 1;
        }
        drewField(&field[0][0]);

    }
}
