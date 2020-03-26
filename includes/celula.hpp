#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Tablero.hpp"

#define COND_FOR_TYPE_1 (nvivas_ == 3)
#define COND_FOR_TYPE_2 (nvivas_ == 3 || nvivas_ == 6 || nvivas_ == 8)
#define COND_FOR_TYPE_3 (nvivas_ == 3 || nvivas_ == 4 || nvivas_ == 6)
#define CHAR_DEAD " "
#define CHAR_CELL_TYPE_1 "1"
#define CHAR_CELL_TYPE_2 "2"
#define CHAR_CELL_TYPE_3 "3"

class Tablero;

enum TiposCelula
{
    CELL_TYPE_0,
    CELL_TYPE_1,
    CELL_TYPE_2,
    CELL_TYPE_3
};



class celula{

    public:

        celula();
        celula(int&, int&);
        ~celula();
        static celula* createCelula(int, int, int);

        virtual inline int getEstado() const;
        inline int getNvivas() const;

        void setNvivas(int);

        virtual int actualizarEstado();
        virtual void contarVecinas(Tablero&);
        virtual std::ostream& mostrar(std::ostream&) const;


    protected:

        int i_,j_,nvivas_;
};