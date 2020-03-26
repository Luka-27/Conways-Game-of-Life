#pragma once
#include "../includes/celula.hpp"


//default constructor
celula::celula()
{
    i_ = 0;
    j_ = 0;
}



//creates cell object with his position ij in the container
celula::celula(int& i, int& j)
{
    i_ = i;
    j_ = j;
}



celula::~celula()
{
    i_ = 0;
    j_ = 0;
}



//getNvivas() returns the number of alive cells that has the calling object around
inline int
celula::getNvivas() const
{
    return nvivas_;
}



//setNvivas() sets the number of alive cells that has the calling object around
void
celula::setNvivas(int nvivas_)
{
    this->nvivas_ = nvivas_;
}



//Returns an integer depending of the cell type
inline int
celula::getEstado() const
{
    return TiposCelula::CELL_TYPE_0;
}



//actualizarEstado() first checks the current state of the cell(COND_FOR_TYPE_), and then return the cell type to create
int
celula::actualizarEstado()
{
    if (COND_FOR_TYPE_1) return CELL_TYPE_1;
    else if (COND_FOR_TYPE_2) return CELL_TYPE_2;
    else if (COND_FOR_TYPE_3) return CELL_TYPE_3;
    else return CELL_TYPE_0;
}



//contarVecinas() counts the number of alive cells that the calling object has around and stores
//the value increasing the attribute nvivas_
void
celula::contarVecinas(Tablero& table)
{
    this->nvivas_ = 0;
    for (auto i = -1; i <= 1; ++i){
        for (auto j = -1; j <= 1; ++j){
            if (this->i_+i == this->i_ && this->j_+j == this->j_){
                nvivas_ = nvivas_;
            } else
            {
                if (table.getPos(this->i_+i, this->j_+j)->getEstado() != CELL_TYPE_0){
                this->nvivas_++;
                }
            }
        }
    }
}



//Static member that creates a cell depending on the type needed. Returns a pointer to the object allocated dynamically
celula*
celula::createCelula(int type, int i, int j)
{
    celula* cell;
    switch(type)
    {
        case CELL_TYPE_0: cell = new celula(i,j); break;
        case CELL_TYPE_1: cell = new celula1(i,j); break;
        case CELL_TYPE_2: cell = new celula2(i,j); break;
        case CELL_TYPE_3: cell = new celula3(i,j); break;
    }
    return cell;
}



//mostrar() prints the cell
std::ostream&
celula::mostrar(std::ostream& out) const
{
    out << CHAR_DEAD;
    return out;
}