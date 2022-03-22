#include <string>
#include "cLaboratorio.h"


cLaboratorio::cLaboratorio(unsigned int IDLaboratorio, string Nombre, string Comuna)
{
	this->IDLaboratorio = IDLaboratorio;
	this->Nombre = Nombre;
	this->Comuna = Comuna;
	Completo = false;
	Paciente1 = NULL;
	Paciente2 = NULL;
}

cLaboratorio::~cLaboratorio()
{
}

void cLaboratorio::RecibirMuestra(cPaciente* paciente)
{
	if (!Completo) 
	{
		if (Paciente1 == NULL && Paciente2 != NULL) 
		{
			if (paciente->GetDNI() != Paciente2->GetDNI()){
				Paciente1 = paciente;
				cout << "Se recibio la muestra de " + Paciente1->ToString() << endl;
				return;
			}
		}
		else if (Paciente1 != NULL && Paciente2 == NULL)
		{
			if (paciente->GetDNI() != Paciente1->GetDNI()) {
				Paciente2 = paciente;
				cout << "Se recibio la muestra de " + Paciente2->ToString() << endl;
				return;
			}
		}
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
	if (Paciente1 != NULL && Paciente1->GetResultadoTesteo() == eResultado::SinResultado) { 
		if (Paciente1->GetCantSintomas() > 2)
			Paciente1->SetResultadoTesteo(eResultado::Positivo);
		else
			Paciente1->SetResultadoTesteo(eResultado::Negativo);
	}

	if (Paciente2 != NULL && Paciente2->GetResultadoTesteo() == eResultado::SinResultado) {
		if (Paciente2->GetCantSintomas() > 2)
			Paciente2->SetResultadoTesteo(eResultado::Positivo);
		else
			Paciente2->SetResultadoTesteo(eResultado::Negativo);
	}

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

bool cLaboratorio::IsCompleto()
{
	return Completo;
}

string cLaboratorio::ToString() 
{
	return Nombre + " IDLaboratorio:" + to_string(IDLaboratorio) + " " + Comuna;
}