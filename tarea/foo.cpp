#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    this->filas = 3;
    this->columnas = 3;
    this->ptr = new float*[3];

    for(int i = 0; i < 3; i++){
        this->ptr[i] = new float[3];
        }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //Genera valores entre 0 y 1
            this->ptr[i][j] = rand() / static_cast<double>(RAND_MAX);
            }
        }
}

Matriz2D::Matriz2D(int n){
    this->filas = n;
    this->columnas = n;
    ptr = new float*[n];
    // Constructor con un parametro
    for(int i = 0; i < n; i++){
        this->ptr[i] = new float[n];
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //Genera valores entre 0 y 1
            this->ptr[i][j] = rand() / static_cast<double>(RAND_MAX);
            }
        }
}


Matriz2D::Matriz2D(int n, int m){
    this->filas = n;
    this->columnas = m;
    ptr = new float*[n];
    // Constructor con dos parametros
    for(int i=0; i<n; i++){
        this->ptr[i] = new float[m]; //crea una matriz de n filas y m columnas
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            //Genera valores entre 0 y 1
            this->ptr[i][j] = rand() / static_cast<double>(RAND_MAX);
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    //Constructor de copia
    this->filas = m.filas;
    this->columnas = m.columnas;
    this->ptr = new float*[m.filas]; // se crea una nueva matriz
    for(int i=0; i<m.filas; i++){
        this->ptr[i] = new float[m.columnas];
        for(int j=0; j<m.columnas; j++){
            this->ptr[i][j] = m.ptr[i][j]; // se copian los valores de la matriz original a la nueva matriz
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m) {
    // Constructor de movimiento
    this->filas = m.filas;
    this->columnas = m.columnas;
    this->ptr = new float*[m.filas]; // se crea una nueva matriz
    for(int i=0; i<m.filas; i++){
        this->ptr[i] = new float[m.columnas];
        for(int j=0; j<m.columnas; j++){
            this->ptr[i][j] = m.ptr[i][j];
        }
    }
    m.ptr = nullptr; // se libera la memoria de la matriz original
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D m2(m.getColumnas(), m.getFilas());
    for(int i=0; i<m.getFilas(); i++) {
        for (int j = 0; j < m.getColumnas(); j++) {
            m2.ptr[j][i] = m.ptr[i][j]; // se intercambian las filas por las columnas
        }
    }
    return m2;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D m3(m1.filas, m1.columnas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j]; //suma las matrices
        }
    }
    return m3;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D m3(m1.filas, m1.columnas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j]; //resta las matrices
        }
    }
    return m3;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m3(m1.filas, m1.columnas);
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m3.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j]; //suma las matrices
        }
    }
    return m3;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D m2(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] + n; //suma un numero a la matriz
        }
    }
    return m2;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D m2(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] - n; //resta un numero a la matriz
        }
    }
    return m2;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D m2(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] * n; //multiplica un numero a la matriz
        }
    }
    return m2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D m2(m.filas, m.columnas);
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m2.ptr[i][j] = m.ptr[i][j] / n; //divide un numero a la matriz
        }
    }
    return m2;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}