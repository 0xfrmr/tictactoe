#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// variables
int choice;
int row, col;
char turn = 'X';
bool draw = false;
bool mov = false;

// shows the board

void print_board()
{
    cout << "\t\tPLAYER 1 [X] \t PLAYER [O] \n\n ";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
};

// function that updates the board

void update_board()
{
    if (turn == 'X')
    {
        cout << "PLAYER [X] INPUT : \n ";
    }
    else
    {
        cout << "PLAYER [O] INPUT : \n";
    };
    cin >> choice;

    // setting the row and column

    switch (choice)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout << "invalid position try again";
    };

    // update with X OR O

    if ((board[row][col] != 'X') && (board[row][col] != 'O'))
    {
        if (turn == 'X')
        {
            board[row][col] = 'X';
            turn = 'O';
        }
        else
        {
            board[row][col] = 'O';
            turn = 'X';
        };
        mov = true;
    }
    // case of choice already occupied
    else
    {
        cout << "box already occupied , try again ! \n";
        mov = false;
    };
    // displaying the updated board
    print_board();
};

// function that determines the game status (draw,win,continue)
// returns true if the game is over and false if it's still going

bool gameover()
{
    // checking for wins
    // simple rows and columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    };
    // diagonals win

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    // checking if game still continuing

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        };

    // if there is no win and the game isn't in continue mode

    draw = true;
    return true;
};

int main()
{
    cout << "\t\t WELCOME TO TIC-TAC-TOE \n\n";
    print_board();

    while (!gameover()) // as long as game continues
    {
        while (!mov) // repeat until correct move
        {
            update_board();
        }
        mov = false;
    };
    if (draw)
    {
        cout << "--DRAW-- \n";
    }
    else
    {
        if (turn == 'X')
        {
            cout << "--PLAYER 2 [O] IS THE WINNER \n";
        }
        else
        {
            cout << "--PLAYER 1 [X] IS THE WINNER \n";
        };
    };
}