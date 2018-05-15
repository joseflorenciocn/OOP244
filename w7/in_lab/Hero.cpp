// OOP244 Workshop 7: Derived Classes
// File w7_athome.cpp
// Version 2.0
// Date 2017/08/12
// Author Jose Florencio Coelho Neto
// Description
//       This file is a source code for the functions
/////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict
{

    Hero::Hero()
    {

		m_name[0] = '\0';
        m_hp=0;
        m_str=0;

    }

    Hero::Hero(const char* name, int hp, int str)
    {
        if (name[0] == '\0' || hp < 0 || str < 0)
        {
            m_name[0] = '\0';
            m_hp = 0;
            m_str = 0;
        }

        else
        {
            strcpy(m_name, name);
            m_hp=hp;
            m_str=str;

        }


    }


    void Hero::operator-=(int attack)
    {
        if (attack >= 0)
        {
            m_hp-=attack;

            if (m_hp < 0) m_hp=0;
        }
    }

    bool Hero::isAlive() const
    {
        if (m_hp > 0) return 1;
        else return 0;
    }

    int Hero::attackStrength() const
    {
        if (m_name[0] !=  '\0')
        {
            return m_str;
        }

        else return 0;
    }

    std::ostream& operator<<(std::ostream& os, const Hero& hero)
    {
        if (hero.m_name[0] == '\0') os << "No hero";
        else os<< hero.m_name;
		return os;
    }

    const Hero& operator*(const Hero& first, const Hero& second)
    {
	
        Hero tmp_fst = first, tmp_sec = second;

		int round = 0;
        for (; round<=max_rounds && tmp_fst.isAlive() && tmp_sec.isAlive(); round++)
        {
			tmp_sec -= tmp_fst.attackStrength();
			tmp_fst -= tmp_sec.attackStrength();
        }

		if (tmp_sec.isAlive())
		{
			std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << second << " in " << round << " rounds." << std::endl;
			return second;
		}

		else
		{
			std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << round << " rounds." << std::endl;
			return first;
		}
		
    }

}



