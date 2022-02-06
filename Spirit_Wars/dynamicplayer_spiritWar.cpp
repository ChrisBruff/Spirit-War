// Spirit_Wars.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* To Do: Updated 12/15/21
*
*  !!! Bugs !!!
*
*/

#include <iostream>
using namespace std;


struct player
{
    string name;
    int life = 1;
    int charges = 0;
    int choice = 0;
    string move = " ";
};

void playerMove(string name, int charges, player& num);
void moveExecute(player& num1, player& num2);


int main()
{
    cout << "Type how many people are playing to start the game: ";
    int PLAYERAMOUNT;
    cin >> PLAYERAMOUNT;
    int* playerarr = new int(PLAYERAMOUNT);

    int PLAYERLIVES = 1;
    int PLAYERNAME = 0;
    
    player player1;
    player player2;

    player1.life = 1;
    player2.life = 1;

    player1.charges = 0;
    player2.charges = 0;


    cout << "Welcome to the Spirit War.\n \n";
    cout << " The Rules:" << endl << "You need charges to perform attacks or advance defences." << endl << " You need 1 for a shot that can be blocked with a block as well as a" << "Spirit Block(this costs 1 as well)" << endl;
    cout << "The Spirit block will defect any shot directed at you and " << "block a Spirit bomb(this requires 3 charges." << endl << "The Spirit Bomb can go through any move other than another Spirit Bomb or Spirit Block and kill your oppenant.\n\n\n";

    while (PLAYERNAME != PLAYERAMOUNT)
    {


        
        cout << "Player 1, choose your name: ";
        cin >> player1.name;
        PLAYERNAME++;

        cout << "Player 2, choose your name: ";
        cin >> player2.name;

        while (player2.name == player1.name)
        {
            cout << "Player 2 you silly goose, choose another name: ";
            cin >> player2.name;
        }
        PLAYERNAME++;
    }

    while (PLAYERLIVES == 1)
    {

        playerMove(player1.name, player1.charges, player1);
        // cout << endl << "Move for " << player1.name << " is:" << endl << player1.move << endl << endl;
        playerMove(player2.name, player2.charges, player2);
        //  cout << endl << "Move for " << player2.name << " is:" << endl << player2.move << endl << endl;

        moveExecute(player1, player2);
        PLAYERLIVES = player1.life * player2.life;

    }

    if (player1.life == 0)
    {
        cout << endl << player2.name << " Has, in cold blood, slaughted " << player1.name << " like cattle";
    }
    else if (player2.life == 0)
    {
        cout << endl << player1.name << " Has cut down " << player2.name << " like grass on a warm summer's day.";
    }

}

void playerMove(string name, int charges, player& num)// & saves the data directly to the address of player charges
{

    string charge = "C";
    string block = "B";
    string shot = "S";
    string spirit_block = "SB";
    string spirit_bomb = "S_B";

    int move = 0;

    cout << "Make your move " << name << "\n 1: charge, 2 : block, 3 : shot, 4 : spirit block, 5 : spirit bomb " << endl;
    cin >> move;

    while (move > 5 || move < 0)
    {
        cout << "try again: ";
        cin >> move;
    }

    if (move == 1)
    {
        num.move = charge;
        num.charges++;
    }

    else if (move == 2)
    {
        num.move = block;
    }

    else if (move == 3)
    {
        if (num.charges >= 1)
        {
            num.move = shot;
            num.charges -= 1;
        }
        else {
            while (move != 1 && move != 2)
            {
                cout << "You can only charge or block";
                cin >> move;
                if (move == 1)
                {
                    num.move = charge;
                    num.charges++;
                }
                else if (move == 2)
                {
                    num.move = block;
                }
            }
        }
    }

    else if (move == 4)
    {
        if (num.charges >= 1)
        {
            num.move = spirit_block;
            num.charges -= 1;
        }
        else {
            while (move != 1 && move != 2)
            {
                if (num.charges >= 1)
                {
                    cout << "You can only charge(1) or block(2)";
                    cin >> move;
                    if (move == 1)
                    {
                        num.move = charge;
                        num.charges++;
                    }
                    else if (move == 2)
                    {
                        num.move = block;
                    }
                    if (move == 3)
                    {
                        if (num.charges >= 1)
                        {
                            num.move = shot;
                            num.charges -= 1;
                        }
                    }
                }
            }
        }
    }

    else if (move == 5)
    {
        if (num.charges >= 3)
        {
            num.move = spirit_bomb;
            num.charges -= 3;
        }
        else {
            if (num.charges >= 1)
            {
                cout << "You can charge(1), block(2), shoot(3), or use spirit block(4)";
                cin >> move;
                if (move == 1)
                {
                    num.move = charge;
                    num.charges++;
                }
                if (move == 2)
                {
                    num.move = block;
                }
                if (move == 3)
                {
                    num.move = shot;
                    num.charges -= 1;
                }
                if (move == 4)
                {
                    num.move = spirit_block;
                    num.charges -= 1;
                }
            }
            else
            {
                while (move != 1 && move != 2)
                {
                    cout << "You can only charge(1) or block(2)";
                    cin >> move;
                    if (move == 1)
                    {
                        num.move = charge;
                        num.charges++;
                    }
                    else if (move == 2)
                    {
                        num.move = block;
                    }
                }
            }
        }

    }

    // cout << endl << "Charges for " << name << " are:" << endl << num.charges << endl;

}void moveExecute(player& num1, player& num2)
{
    //Player1

    //spirit bomb
    if (num1.move == "S_B" && num2.move == "C")
    {
        num2.life = 0;
    }
    else if (num1.move == "S_B" && num2.move == "B")
    {
        num2.life = 0;

    }
    else if (num1.move == "S_B" && num2.move == "S")
    {
        num2.life = 0;

    }//shot
    if (num1.move == "S" && num2.move == "C")
    {
        num2.life = 0;
    }
    else if (num1.move == "S" && num2.move == "SB")
    {
        num1.life = 0;

    }


    //Player 2

    //spirit bomb
    else if (num2.move == "S_B" && num1.move == "C")
    {
        num2.life = 0;
    }
    else if (num2.move == "S_B" && num1.move == "B")
    {
        num2.life = 0;

    }
    else if (num2.move == "S_B" && num1.move == "S")
    {
        num1.life = 0;

    }//shot
    else if (num2.move == "S" && num1.move == "C")
    {
        num1.life = 0;
    }
    else if (num2.move == "S" && num1.move == "SB")
    {
        num2.life = 0;

    }
    // cout << endl << endl << "Test: " << endl << num1.name << " lives are: " << num1.life << endl << num2.name << " lives are: " << num2.life;
   //  cout << endl << endl << "Charges for " << num1.name << " are:" << endl << num1.charges << endl;
    // cout << "Charges for " << num2.name << " are:" << endl << num2.charges << endl;
}
