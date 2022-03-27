#include <string>
#include "cLaboratorio.h"

cLaboratorio::cLaboratorio(unsigned int IDLaboratorio, string Nombre, string Comuna)
{
	//Inicializo todas las variables!
	this->IDLaboratorio = IDLaboratorio;
	this->Nombre = Nombre;
	this->Comuna = Comuna;
	Completo = false;
	Paciente1 = NULL;
	Paciente2 = NULL;
}

cLaboratorio::~cLaboratorio()
{
	//Nada que borrar
}

void cLaboratorio::RecibirMuestra(cPaciente* paciente)
{
	//Pregunto si el laboratorio no se encuentra lleno
	if (!Completo) 
	{
		//Verifico si existe lugar en Paciente1 y si no es el mismo que 
		//se encuentra almacenado en Paciente2
		if (Paciente1 == NULL && Paciente2 != NULL) 
		{
			if (paciente->GetDNI() != Paciente2->GetDNI()){
				Paciente1 = paciente;
				cout << "Se recibio la muestra de " + Paciente1->ToString() << endl;
				return;
			}
		}
		
		//Verifico si existe lugar en Paciente2 y si no es el mismo que 
		//se encuentra almacenado en Paciente1
		else if (Paciente1 != NULL && Paciente2 == NULL)
		{
			if (paciente->GetDNI() != Paciente1->GetDNI()) {
				Paciente2 = paciente;
				cout << "Se recibio la muestra de " + Paciente2->ToString() << endl;
				return;
			}
		}

		//Pregunto si existe algun espacio libre
		else if (Paciente1 == NULL || Paciente2 == NULL){
			if (Paciente1 == NULL) {
				Paciente1 = paciente;
				cout << "Se recibio la muestra de " + Paciente1->ToString() << endl;
				return;
			}
			if (Paciente2 == NULL) {
				Paciente2 = paciente;
				cout << "Se recibio la muestra de " + Paciente2->ToString() << endl;
				return;
			}
		}

		//Si no se cumplio ninguna condicion quiere decir que la muestra
		//ya se encuentra en el laboratorio
		else
		{
			cout << "La muestra del paciente ya se encuentra en el laboratorio" << endl;
			return;
		}

	}
	else{
		cout << "No hay lugar para recibir la muestra. Intente mas tarde. " << endl;
		return;
	}

}

void cLaboratorio::AnalisisMuestra()
{
	//Verifico que existe un Paciente1 y que no tiene resultado de testeo
	if (Paciente1 != NULL && Paciente1->GetResultadoTesteo() == eResultado::SinResultado) { 
		//Si la cantidad de sintomas positivos es mayor a 2 -> Covid positivo
		if (Paciente1->GetCantSintomas() > 2)
			Paciente1->SetResultadoTesteo(eResultado::Positivo);
		else
			Paciente1->SetResultadoTesteo(eResultado::Negativo);
	}

	//Verifico que existe un Paciente2 y que no tiene resultado de testeo
	if (Paciente2 != NULL && Paciente2->GetResultadoTesteo() == eResultado::SinResultado) {
		//Si la cantidad de sintomas positivos es mayor a 2 -> Covid positivo
		if (Paciente2->GetCantSintomas() > 2)
			Paciente2->SetResultadoTesteo(eResultado::Positivo);
		else
			Paciente2->SetResultadoTesteo(eResultado::Negativo);
	}

	//Llamo a la funcion AvisarPacientes que se encarga de mandar un msg
	//y de eliminar las muestras del laboratorio
	AvisarPacientes();
}

void cLaboratorio::AvisarPacientes()
{
	if (Paciente1 != NULL && Paciente1->GetResultadoTesteo() != eResultado::SinResultado) {
		if (Paciente1->GetResultadoTesteo() == eResultado::Positivo)
			cout << "Se ha mandado un mensaje a " + Paciente1->ToString() + " COVID: Positivo" << endl;
		else
			cout << "Se ha mandado un mensaje a " + Paciente1->ToString() + " COVID: Negativo" << endl;

		Paciente1 = NULL;
	}
	
	if (Paciente2 != NULL && Paciente2->GetResultadoTesteo() != eResultado::SinResultado) {
		if (Paciente2->GetResultadoTesteo() == eResultado::Positivo)
			cout << "Se ha mandado un mensaje a " + Paciente2->ToString() + " COVID: Positivo" << endl;
		else
			cout << "Se ha mandado un mensaje a " + Paciente2->ToString() + " COVID: Negativo" << endl;

		Paciente2 = NULL;
	}
}

unsigned int cLaboratorio::GetIDLaboratorio()
{
	return IDLaboratorio;
}

string cLaboratorio::GetNombre()
{
	return Nombre;
}

bool cLaboratorio::IsCompleto()
{
	return Completo;
}

string cLaboratorio::ToString() 
{
	string text = "";

	text += "Datos del Laboratorio \n";

	text += Nombre + " ID:" + to_string(IDLaboratorio) + " " + Comuna + "\n";

	if (Paciente1 != NULL) {
		text += "Se tiene la muestra de " + Paciente1->GetNombre();
	}
	if (Paciente2 != NULL) {
		text += "Se tiene la muestra de " + Paciente2->GetNombre();
	}

	return text;
}