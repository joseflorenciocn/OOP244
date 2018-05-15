// OOP244 Workshop 7: Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/08/12
// Author Jose Florencio Coelho Neto
// Description
//       This file is a header file with the functions declarations
/////////////////////////////////////////////////////

#ifndef SICT_HERO_H
#define SICT_HERO_H

const int max_rounds = 100;

namespace sict
{

    class Hero
    {

        char m_name[40];
        int m_hp;
        int m_str;

    public:
        Hero();
        Hero(const char* name, int hp, int str);
      //  ~Hero();
        void operator-=(int attack);
        bool isAlive() const;
        int attackStrength() const;


        friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

        

    };

	const Hero& operator*(const Hero& first, const Hero& second);

}

#endif //W7_HERO_H
