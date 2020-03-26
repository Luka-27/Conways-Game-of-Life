#pragma once
#include "../includes/Tablero.hpp"



//constructor creates a vector of vectors that contains pointers to cells allocated dynamically
Tablero::Tablero(const int& m, const int& n):

    m_(m+2),
    n_(n+2)
    {
    for (auto i = 0; i < this->m_; ++i){
        std::vector<celula*> v;
        for (auto j = 0; j < this->n_; ++j){
            celula *cell = new celula(i,j);
            v.push_back(cell);
        }
        malla_.push_back(v);
    }
}



Tablero::~Tablero()
{
    for (auto i = 0; i < m_; ++i){
        for (auto j = 0; j < n_; ++j){
            delete this->malla_[i][j];
        }
    }
}



//GetM_() returns number of rows of the container
inline int
Tablero::getM_() const
{
    return m_;
}



//GetN_() returns number of columns of the container
inline int
Tablero::getN_() const
{
    return n_;
}



//setAlive() creates a new cell, specifying his type
void
Tablero::setAlive(const int i, const int j, const int type)
{
    delete this->malla_[i][j];
    this->malla_[i][j] = celula::createCelula(type,i,j);
}



//getPos() returns the pointer contained in a specified position
celula*
Tablero::getPos(int i, int j)
{
    return malla_[i][j];
}



//compute() starts to go through every stage of the implementation
void
Tablero::compute()
{
    countNeighbours();
    update();
}



//countNeighbours() calls the method contarVecinas for every cell in the container
void
Tablero::countNeighbours()
{
    for (auto i = 1; i < this->m_-1; ++i){
        for (auto j = 1; j < this->n_-1; ++j){
            this->malla_[i][j]->contarVecinas(*this);
        }
    }
}



//update() calls the method actualizarEstado for every cell contained in the board and creates
//a new cell if needed
void
Tablero::update()
{
    for (auto i = 1; i < this->m_-1; ++i){
        for (auto j = 1; j < this->n_-1; ++j){
            int newcell = malla_[i][j]->actualizarEstado();
            if (this->malla_[i][j]->getEstado() != newcell){
                this->setAlive(i,j,newcell);
            }
        }
    }
}



//write() prints the cells contained in the board
std::ostream&
Tablero::write(std::ostream& out)
{
    for (auto i = 1; i <= getM_()-1; i++)
        out << CHAR_WALL;

    out << CHAR_WALL;
    out << std::endl;
    
    for(auto i = 1; i < getM_()-1; ++i){
        out << CHAR_WALL;
        for (auto j = 1; j < getN_()-1; ++j){
            this->malla_[i][j]->mostrar(out);
        }
        out << CHAR_WALL;
        out << std::endl;
    }
        for (auto i = 0; i < getM_(); i++)
        out << CHAR_WALL;
    
    return out;
}