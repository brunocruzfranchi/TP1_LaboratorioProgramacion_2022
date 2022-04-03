#include <string>
#include "Enums.h"
#include "cPaciente.h"

cPaciente::cPaciente(string Nombre, string Apellido, string DNI, string Telefono, bool Fiebre, bool Tos, bool Mocos, bool ContactoEstrecho, bool DolorCabeza, bool DolorGarganta)
{
	//Inicializo todas las variables
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->DNI = DNI;
	this->Telefono = Telefono;
	this->Fiebre = Fiebre;
	this->Tos =	Tos;
	this->Mocos = Mocos;
	this->ContactoEstrecho = ContactoEstrecho;
	this->DolorCabeza =	DolorCabeza;
	this->DolorGarganta  = DolorGarganta;
	ResultadoTesteo = eResultado::SinResultado;
}

cPaciente::~cPaciente()
{
	//No tengo que eliminar nada
}

eResultado cPaciente::GetResultadoTesteo()
{
	return ResultadoTesteo;
}

void cPaciente::SetResultadoTesteo(eResultado resultado)
{
	this->ResultadoTesteo = resultado;
}

void cPaciente::ImprimirEnPantalla()
{
	cout << this->ToString() << endl;
}

string cPaciente::ToString()
{
	return " Nombre: " + Nombre + " " + Apellido + " DNI: " + DNI + " ";
}

string cPaciente::GetDNI()
{
	return DNI;
}

string cPaciente::GetNombre()
{
	return Nombre;
}

int cPaciente::GetCantSintomas()
{
	int cont = 0;

	if(Fiebre)
		cont++;
	if(Tos)
		cont++;
	if(Mocos)
		cont++;
	if(ContactoEstrecho)
		cont++;
	if(DolorCabeza)
		cont++;
	if(DolorGarganta)
		cont++;
	
	return cont;
}



