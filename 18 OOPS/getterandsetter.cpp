#include<iostream>
using namespace std;
int main()
{
    class player
    {
        private:
        int health; // Data Members
        int score; // Data Members

        public:
        // SETTER
        void setSore(int s) // Member Functions
        {
            cout<<"Score is getting set."<<endl;
            score = s;
        }
        void setHealth(int h) // Member Functions
        {
            cout<<"Health is getting changed."<<endl;
            health = h;
        }
        // GETTER
        int getHealth() // Member Functions
        {
            return health;
        }
        int getScore() // Member Functions
        {
            return score;
        }
    };
    player ullas;
    ullas.setHealth(100);
    ullas.setSore(90);
    cout<<"Health is "<<ullas.getHealth()<<endl;
    cout<<"Score is "<<ullas.getScore()<<endl;
    return 0;
}