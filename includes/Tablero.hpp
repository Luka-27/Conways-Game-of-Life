#pragma once
#include <exception>

#include "celula1.hpp"
#include "celula2.hpp"
#include "celula3.hpp"
#include <vector>
#define CHAR_WALL "█"
typedef std::vector<std::vector<celula*>> tablero;
class celula;


class Tablero{
    
    public:

        Tablero(const int&, const int&);
        ~Tablero();


        inline int getM_() const;
        inline int getN_() const;

        void setAlive(const int, const int, const int);
        celula* getPos(int, int);

        void compute();
        void countNeighbours();
        void update();
        

        std::ostream& write(std::ostream&);

    private:
    
        tablero malla_;
        int m_,n_;
};