#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void introduction();

int main()
{
    string name; // Name of player.
    int balance; // Balance of money player input.
    int bet; // Player's bet amount.
    int guess; // Player's guess #.
    int winning_num; // The winning #.
    char choice; // Play again? Y/N.

    srand(time(0)); // Random # generator.
    introduction();

    cout << "---------- C A S I N O  G A M E ----------" << endl;
    cout << endl << "Enter Your Name: ";
    getline(cin, name);

    cout << "Amount You Want to Deposit to Play: $";
    cin >> balance;

    do 
    {
        do 
        {
            // system("cls");
            cout << name << ", please enter the amount you want to bet: $";
            cin >> bet;

            if (bet > balance)
            {
                cout << "Sorry, the amount you want to bet is greater than your balance. Try again." << endl;
            }
        } while (bet > balance);

        do
        {
            cout << "Guess your number between 1 to 10 to place bet: ";
            cin >> guess;

            if (guess <= 0 || guess > 10)
            {
                cout << "Please reenter a betting number between 1 and 10..." << endl;
            }
        } while (guess <= 0 || guess > 10);

        winning_num = rand()%10 + 1; // This math will assure that randomly generated # is between 1 and 10.

        if (winning_num == guess)
        {
            cout << "CONGRATULATIONS! You won $" << bet * 10 << "!" << endl;
            balance += bet * 10;
        }
        else
        {
            cout << "BAD LUCK THIS TIME! You lost $" << bet << "!" << endl;
            balance -= bet;
        }

        cout << "The winning number was: " << winning_num << "!" << endl;
        cout << name << ", your new balance is $" << balance << "!" << endl;

        if (balance == 0)
        {
            cout << "OH NO! Your account balance is $0." << endl;
        }

        cout << "Do you want to play again (Y/N)? ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y' && balance <= 0)
        {
            cout << "Amount You Want to Deposit to Play: $";
            cin >> balance;
        }
    } while (choice == 'Y' || choice == 'y');

    cout << "THANKS FOR PLAYING! Your final balance is $" << balance << "!" << endl;

    return 0;
}

void introduction()
{
    cout << "---------- R U L E S  T O  P L A Y ----------" << endl;
    cout << "1. Select any number from 1 to 10." << endl;
    cout << "2. If your number matches the winning number, you will win 10x the amount that you bet." << endl;
    cout << "3. If you bet the wrong number, you will lose the amount you bet." << endl << endl;
}