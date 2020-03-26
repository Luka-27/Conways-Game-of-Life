#pragma once
#include "celula.hpp"
#define SURVIVE_TYPE_2 (nvivas_ == 2 || nvivas_ == 4 || nvivas_ == 5)

class celula2 : public celula{

    public:
        celula2(int i,int j):
            celula(i,j){}

        inline int getEstado() const;
        int actualizarEstado();    //Reglas de supervivencia
        std::ostream& mostrar(std::ostream&) const;

};