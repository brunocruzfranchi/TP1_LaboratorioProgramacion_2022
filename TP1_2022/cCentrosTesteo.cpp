#include "cCentrosTesteo.h"
#include "Enums.h"

cCentrosTesteo::cCentrosTesteo(unsigned int IDCentro, string Nombre, string Comuna)
{
	this->IDCentro = IDCentro;
	this->Nombre = Nombre;
	this->Comuna = Comuna;
	Completo = false;
	Laboratorio = NULL;
	Paciente1 = NULL;
	Paciente2 = NULL;
}

cCentrosTesteo::~cCentrosTesteo()
{

}

bool cCentrosTesteo::AltaPaciente(cPaciente* paciente)
{
	//Verifico que exista algun espacio para colocar al paciente
	if (Completo == false) {
		if (Paciente1 == NULL) {
			Paciente1 = paciente;
		}
		else if (Paciente2 == NULL) {
			Paciente2 = paciente;
		}
		//En el caso que se encuentre el centro lleno, cambio la variable Completo a True
		if (Paciente1 != NULL && Paciente2 != NULL)
			Completo = true;
		return true;
	}
	//En el caso que no haya lugar en el Centro
	return false;
}

void cCentrosTesteo::MandarTesteo()
{
	//Verifico que el laboratorio pasado es el correspondiente al que se tiene asignado
	if (Laboratorio != NULL){
		if (!(Laboratorio->IsCompleto())) {
			if (Paciente1 != NULL) {
				Laboratorio->RecibirMuestra(Paciente1);
			}
			if (Paciente2 != NULL) {
				Laboratorio->RecibirMuestra(Paciente2);
			}
		}
	}
	else
		cout << "No se tiene un laboratorio asociado" << endl;
}

void cCentrosTesteo::BajaPaciente()
{
	if (Paciente1->GetResultadoTesteo() != eResultado::SinResultado) 
	{
		cout << "Se dio de baja a" << Paciente1->ToString() << endl;
		Paciente1 = NULL;
	}
	if (Paciente1->GetResultadoTesteo() != eResultado::SinResultado)
	{
		cout << "Se dio de baja a" << Paciente1->ToString() << endl;
		Paciente1 = NULL;
	}
}

void cCentrosTesteo::AsociarLaboratorio(cLaboratorio* laboratorio)
{
	this->Laboratorio = laboratorio;
	cout << "Se asocio el " + Laboratorio->ToString() + " al centro " + Nombre << endl;
}

void cCentrosTesteo::DesasociarLaboratorio()
{
	Laboratorio = NULL;
}
