#include "cCentrosTesteo.h"
#include "Enums.h"

cCentrosTesteo::cCentrosTesteo(unsigned int IDCentro, string Nombre, string Comuna)
{
	//Inicializo las variables!
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
	//Nada que borrar
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
	//En el caso que no haya lugar en el Centro retorno false
	return false;
}

void cCentrosTesteo::MandarTesteo()
{
	//Verifico que tenga un laboratorio asignado
	if (Laboratorio != NULL){
		//Pregunto si el laboratorio se encuentra lleno
		if (!(Laboratorio->IsCompleto())) {
			//Mando la muestra del paciente 1 si es que la hay
			if (Paciente1 != NULL) {
				Laboratorio->RecibirMuestra(Paciente1);
			}
			//Mando la muestra del paciente 2 si es que la hay
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
	//Pregunto si ya se tienen los resultado de 
	//los pacientes para realizar la baja en el sistema
	if (Paciente1->GetResultadoTesteo() != eResultado::SinResultado) 
	{
		cout << "Se dio de baja a" << Paciente1->ToString() << endl;
		Paciente1 = NULL;
	}
	if (Paciente2->GetResultadoTesteo() != eResultado::SinResultado)
	{
		cout << "Se dio de baja a" << Paciente2->ToString() << endl;
		Paciente2 = NULL;
	}
}

bool cCentrosTesteo::AsociarLaboratorio(cLaboratorio* laboratorio)
{
	if (Laboratorio == NULL) {
		this->Laboratorio = laboratorio;
		return true;
	}
	else
		return false;
}

void cCentrosTesteo::DesasociarLaboratorio()
{
	Laboratorio = NULL;
}

void cCentrosTesteo::ImprimirEnPantalla()
{
	cout << this->ToString() << endl;
}

string cCentrosTesteo::ToString()
{
	string text = "\n";

	text += "Datos Centro de Testeo \n";

	text += Nombre + " " + Comuna + "\n";

	if (Laboratorio != NULL){
		text += "Laboratorio Asociado: " + Laboratorio->ToString() + "\n";
	}
	else
		text += "No hay un laboratorio asociado \n";

	if (Paciente1 != NULL) {
		text += "Paciente Asociado: " + Paciente1->ToString() + "\n";
	}
	if (Paciente2 != NULL) {
		text += "Paciente Asociado: " + Paciente2->ToString() + "\n";
	}

	return text;
}

string cCentrosTesteo::GetNombre()
{
	return Nombre;
}
