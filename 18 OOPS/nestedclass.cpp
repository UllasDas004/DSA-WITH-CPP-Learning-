#include<iostream>
using namespace std;
class Gun
{
    public:
    int ammo,damage,scope;
};
class Player
{
    private:
        int score,health,age;
        bool alive;
        Gun primaryWeapon; // Nested Class
        Gun secondaryWeapon; // Nested Class

    public:
        // SETTER
        void setScore(int score) // Member Functions
        {
            cout<<"Score is getting set."<<endl;
            this->score = score;
        }
        void setHealth(int health) // Member Functions
        {
            cout<<"Health is getting changed."<<endl;
            this->health = health;
        }
        void setAge(int age) // Member Functions
        {
            cout<<"Age is getting set."<<endl;
            this->age = age;
        }
        void isAlive(bool alive)
        {
            cout<<"Player live is getting checked"<<endl;
            this->alive = alive;
        }
        void setPrimaryWeapon(Gun primary)
        {
            primaryWeapon = primary;
        }
        void setsecondaryWeapon(Gun secondary)
        {
            secondaryWeapon = secondary;
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
        int getAge() // Member Functions
        {
            return age;
        }
        bool getAlive()
        {
            return alive;
        }
        Gun getPrimaryWeapon()
        {
            return primaryWeapon;
        }
        Gun getSecondaryWeapon()
        {
            return secondaryWeapon;
        }
};
int main()
{
    Player ullas;
    ullas.setAge(20);
    ullas.setHealth(100);
    ullas.setScore(80);
    ullas.isAlive(true);
    Gun m416,m24;
    m416.ammo = 180;
    m416.damage = 30;
    m416.scope = 6;
    m24.ammo = 30;
    m24.damage = 100;
    m24.scope = 8;

    ullas.setPrimaryWeapon(m416);
    ullas.setsecondaryWeapon(m24);
    cout<<"damage of primary weapon is "<<ullas.getPrimaryWeapon().damage<<endl;
    cout<<"damage of secondary weapon is "<<ullas.getSecondaryWeapon().damage<<endl;
    return 0;
}