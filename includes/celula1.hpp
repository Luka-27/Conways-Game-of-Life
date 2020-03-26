#pragma once
#include "celula.hpp"
#define SURVIVE_TYPE_1 (nvivas_ == 2 || nvivas_ == 3)


class celula1 : public celula{

    public:
        celula1(int i,int j):
            celula(i,j) {}

        inline int getEstado() const;
        int actualizarEstado(); //Reglas de nacimiento
        std::ostream& mostrar(std::ostream&) const;

};