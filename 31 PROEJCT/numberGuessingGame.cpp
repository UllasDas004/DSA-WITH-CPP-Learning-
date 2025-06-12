#include<iostream>
#include<vector>
using namespace std;
class Guesser
{
    int guessedNum;
    public:
    int guesserInput()
    {
        int x;
        cout<<"Enter the number guessed by the guesser:-";
        cin>>x;
        guessedNum = x;
        return guessedNum;
    }
};
class Player
{
    int playerNum;
    public:
    int playerInput(int pnum)
    {
        int x;
        cout<<"Enter the number guessed by the player"<<pnum<<":- ";
        cin>>x;
        playerNum = x;
        return playerNum;
    }
};
class Umpire
{
    int g;
    vector<int> playerNums;
    public:
    void takeGuesserInput()
    {
        Guesser g1;
        g = g1.guesserInput();
    }
    void takePlayersInput()
    {
        cout<<"Enter the number of players:- ";
        int n;
        cin>>n;
        if(n < 1)
        {
            cout<<"Player count cannot be "<<n<<"!"<<endl;
            return;
        }
        playerNums.clear();
        for(int i=0;i<n;i++)
        {
            Player temp;
            int x = temp.playerInput(i+1);
            playerNums.push_back(x);
        }
    }
    void printResult()
    {
        int n = playerNums.size();
        if(n == 0) return;
        bool allWon = true,allLost = true;
        for(int i=0;i<n;i++)
        {
            if(playerNums[i] == g)
            {
                cout<<"Player"<<i+1<<" won the game!"<<endl;
                allLost = false;
            }
            else
            {
                cout<<"Player"<<i+1<<" lost the game!"<<endl;
                allWon = false;
            }
        }
        if(allWon) 
        {
            if(n == 1) cout<<"All "<<n<<" player have won the game!"<<endl;
            else cout<<"All "<<n<<" players have won the game!"<<endl;
        }
        if(allLost)
        {
            if(n <= 0) cout<<"All "<<n<<" player have lost the game!"<<endl;
            else cout<<"All "<<n<<" players have lost the game!"<<endl;
        }
    }
};
int main()
{
    cout<<"--------------Let's start the Guessing Game!--------------"<<endl;
    Umpire u1;
    u1.takeGuesserInput();
    u1.takePlayersInput();
    u1.printResult();
    cout<<"-------------------------End Game!------------------------"<<endl;
    return 0;
}