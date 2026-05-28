#include <stdlib.h>
#include <cerrno>
#include <exception>
#include <iostream>
#include <vector>


struct ErrorParDominio : public std::exception {
private:
    std::string mensaje;

public:
    ErrorParDominio(int p1, int p2) {
        mensaje = "Por lo menos una de las siguientes ids no está en los datos:  " 
                + std::to_string(p1) + ", " + std::to_string(p2);
    }

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

typedef struct Pair{
    int x;
    int y;
} Pair;

class BDD {
    int* personas;
    Pair* relaciones;
    int size_personas = 0;
    int size_relaciones = 0;
private:
    void mas_personas(){
        this->personas = (int *)realloc(this->personas, ++size_personas * sizeof(int));
    }
    void mas_relaciones(){
        this->relaciones = (Pair *)realloc(this->relaciones, ++size_relaciones * sizeof(Pair));
    }
public:
    BDD(){ 
       this->personas = (int *)calloc(1, sizeof(int)); 
       this->relaciones = (Pair *)calloc(1, sizeof(Pair)); 
    }
    void agregar_persona(int persona){
        if (this->existe_persona(persona))
            throw std::invalid_argument("Persona ya existente: "+ std::to_string(persona));
        this->mas_personas();
        this->personas[this->size_personas - 1] = persona;
    }
    void agregar_relacion(int persona1, int persona2){
        if (this->existe_persona(persona1) && this->existe_persona(persona2)){
            this->mas_relaciones();
            this->relaciones[this->size_relaciones - 1].x = persona1;
            this->relaciones[this->size_relaciones - 1].y = persona2;
        }
        else throw ErrorParDominio(persona1, persona2);
        
    }
    bool existe_persona(int persona){
        for (int i=0; i < this->size_personas; i++)
            if (persona == this->personas[i]) return true;
        return false;
    }
    ~BDD() { free(personas), free(relaciones); }
};


int main(){
    try{
        BDD datos = BDD();
        datos.agregar_persona(1);
        datos.agregar_persona(2);
        datos.agregar_persona(2);
        datos.agregar_relacion(1, 2);
        datos.agregar_relacion(3, 2);
    }
    catch (ErrorParDominio &error){
        std::cout << error.what() << std::endl;
        return -2;
    }
    catch (std::invalid_argument & error){
        std::cout << error.what() << std::endl;
        return -1;
    }

    return 0;
}