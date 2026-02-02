#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include <cctype>
// #include "../../../Library/Developer/CommandLineTools/SDKs/MacOSX15.4.sdk/usr/include/_ctype.h"

using namespace std;
int c1 = 0, c2 = 0, c3 = 0;

char getuserchoice()
{
    // You gonna see some magic out here :?

    char playerchoice;
    do
    {
        // dont use std::endl here as it flushes the output buffer, when that is not necessary, only a new line is needed.
        cout << "---------------------\n";
        cout << "ROCK PAPER SCISSORS\n";
        cout << "---------------------\n";
        cout << "choose one of the following:\n";
        cout << "enter 'r' for rock\n";
        cout << "enter 'p' for paper\n";
        cout << "enter 's' for scissors\n";
        cin >> playerchoice;
        playerchoice = tolower(playerchoice);
    } while (playerchoice != 'r' && playerchoice != 'p' && playerchoice != 's');

    return playerchoice;
}

// Computer logic is purely random

char getcomputerchoice()
{
    char compchoice;

    int num = ((c1 / 2) + rand() % (c1 + c2 + c3));
    if (num <= c1)
    {
        compchoice = 'r';
        c1++;
    }
    else if (num <= c1 + c2)
    {
        compchoice = 's';
        c2++;
    }
    else
    {
        compchoice = 'p';
        c3++;
    }

    return compchoice;
}
void showchoice(char choice)
{
    switch (choice)
    {
    case 'r':
        cout << "Rock\n"
             << endl;
        break;
    case 'p':
        cout << "Paper\n"
             << endl;
        break;
    case 's':
        cout << "Scissors\n"
             << endl;
        break;
    }
}
void choosewinner(char player, char computer)
{
    switch (player)
    {
    case 'r':
        if (computer == 'r')
        {
            cout << " IT'S A TIE " << endl;
        }
        else if (computer == 'p')
        {
            cout << "COMPUTER WON" << endl;
        }
        if (computer == 's')
        {
            cout << "YOU WON" << endl;
        }
        break;

    case 'p':
        if (computer == 'r')
        {
            cout << "YOU WON " << endl;
        }
        else if (computer == 'p')
        {
            cout << "IT'S A TIE" << endl;
        }
        if (computer == 's')
        {
            cout << "COMPUTER WINS" << endl;
        }
        break;

    case 's':
        if (computer == 'r')
        {
            cout << " COMPUTER WON " << endl;
        }
        else if (computer == 'p')
        {
            cout << "YOU WON " << endl;
        }
        if (computer == 's')
        {
            cout << "IT'S A TIE" << endl;
        }
        break;
    }
}

auto tolower_str(std::string& s) -> std::string {
    std::string temp{s};
    for(int i = 0; i < s.size(); i++) { // probably better not to pass by refernce here as it is only a character
        temp[i] = tolower(s[i]);
    }
    return temp;
}

int main()
{
    c1 = 1;
    c2 = 1;
    c3 = 1;
    char player;
    char computer;
    string again;
    srand(time(NULL));
    do
    {
        player = getuserchoice();
        cout << "YOUR CHOICE IS: ";
        showchoice(player);
        computer = getcomputerchoice();
        cout << "COMPUTER CHOOSES: ";
        showchoice(computer);
        cout << " " << endl;
        choosewinner(player, computer);
        cout << "\nif you wish to play again type 'yes' else 'no' " << endl;
        cin >> again;
        cout << "\n";

    } while (tolower_str(again) == "yes");

    return 0;
}
