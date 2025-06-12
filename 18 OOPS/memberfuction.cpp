#include<iostream>
using namespace std;
int main()
{
    class player
    {
        public:
        int health; // Data Members
        int score; // Data Members
        void showHealth() // Member Functions
        {
            cout<<"Health is "<<health<<endl;
        }
        void showScore() // Member Functions
        {
            cout<<"Score is "<<score<<endl;
        }
    };
    player ullas;
    ullas.score = 90;
    ullas.health = 100;
    ullas.showHealth();
    ullas.showScore();
    return 0;
}