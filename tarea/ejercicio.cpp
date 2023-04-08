#include <iostream>

using namespace std;
/*Implementar la Clase Matriz2D para generar matrices de dos dimensiones y realizar operaciones aritméticas entre ellas.
Los elementos de la matriz deben ser números aleatorios entre 0 y 1 (float).
Constructores por defecto, de copia, y movimiento:
 */

class Matriz2D{
    friend Matriz2D t(Matriz2D&);
    friend ostream& operator<<(ostream&, const Matriz2D&);
    friend Matriz2D operator+(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator-(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator*(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator+(const Matriz2D&, float);
    friend Matriz2D operator-(const Matriz2D&, float);
    friend Matriz2D operator*(const Matriz2D&, float);
    friend Matriz2D operator/(const Matriz2D&, float);
public:
    Matriz2D();
    Matriz2D(int);
    Matriz2D(int, int);
    Matriz2D(const Matriz2D&);
    Matriz2D(Matriz2D&&);

    float get(int, int);
    int getFilas();
    int getColumnas();
private:
    float** ptr;
    int filas = 3;
    int columnas = 3;
};


Matriz2D::Matriz2D(){
    // Constructor por defecto
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        this->ptr[i] = new float[columnas];
    }
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            this->ptr[i][j] = rand() % 1; //genera una matriz de 3x3
        }
    }
}

Matriz2D::Matriz2D(int n){
    ptr = new float*[n];
    // Constructor con un parametro
    for(int i = 0; i < n; i++){
        this->ptr[i] = new float[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            this->ptr[i][j] = rand() % 1; //genera una matriz de nxn
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    ptr = new float*[n];
    // Constructor con dos parametros
    for(int i=0; i<n; i++){
        this->ptr[i] = new float[m]; //crea una matriz de n filas y m columnas
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            this->ptr[i][j] = rand() % 1; //genera una matriz de nxm
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this->filas = m.filas;
    this->columnas = m.columnas;
    this->ptr = m.ptr;

    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            this->ptr[i][j] = m.ptr[i][j]; //copia la matriz
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this->filas = m.filas;
    this->columnas = m.columnas;
    this->ptr = m.ptr;
    m.ptr = nullptr;

    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            this->ptr[i][j] = m.ptr[i][j]; //mueve la matriz
        }
    }
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m.ptr[i][j] = m.ptr[i][j]; //transpone la matriz
        }
    }
    return m;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m) {
    // Sobrecarga del operador <<
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            os << m.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}


Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m1.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j]; //suma las matrices
        }
    }
    return m1;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m1.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j]; //resta las matrices
        }
    }
    return m1;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    for(int i=0; i<m1.filas; i++){
        for(int j=0; j<m1.columnas; j++){
            m1.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j]; //suma las matrices
        }
    }
    return m1;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m.ptr[i][j] = m.ptr[i][j] + n; //suma un numero a la matriz
        }
    }
    return m;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m.ptr[i][j] = m.ptr[i][j] - n; //resta un numero a la matriz
        }
    }
    return m;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m.ptr[i][j] = m.ptr[i][j] * n; //multiplica un numero a la matriz
        }
    }
    return m;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    for(int i=0; i<m.filas; i++){
        for(int j=0; j<m.columnas; j++){
            m.ptr[i][j] = m.ptr[i][j] / n; //divide un numero a la matriz
        }
    }
    return m;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas() {
    return columnas;
}


int main(){
    Matriz2D m1;            // Matriz cuadrada de 3x3
    cout << m1 << endl;


    return 0;

}

