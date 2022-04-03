// TP1_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cPaciente.h"
#include "cLaboratorio.h"
#include "cCentrosTesteo.h"

using namespace std;

int main()
{
	//Creo mis variables a utilizar
	cPaciente* miPaciente1 = new cPaciente("Bruno", "Cruz Franchi", "45612318", "1164951234", 
		true, true, true, false, false, false);
	cPaciente* miPaciente2 = new cPaciente("Taylor", "Swift", "95789456", "1111111111",
		false, false, false, false, false, false);
	cPaciente* miPaciente3 = new cPaciente("Julieta", "Di Marco", "43254954", "1145689125",
		false, false, true, true, false, false);

	cCentrosTesteo* Centro1 = new cCentrosTesteo(1, "Centro Jesus", "Comuna 5");
	cCentrosTesteo* Centro2 = new cCentrosTesteo(2, "Centro Maria", "Comuna 15");

	cLaboratorio* Laboratorio1 = new cLaboratorio(1, "Laboratorio Jesus", "Comuna 5");
	cLaboratorio* Laboratorio2 = new cLaboratorio(2, "Laboratorio Maria", "Comuna 15");


	//Doy de alta a mi primer paciente
	if (Centro1->AltaPaciente(miPaciente1))
		cout << "Se ha dado de alta a " + miPaciente1->GetNombre() << endl;
	else
		cout << "No se logro dar de alta a " + miPaciente1->GetNombre() << endl;

	//Doy de alta a mi segundo paciente
	if (Centro1->AltaPaciente(miPaciente2))
		cout << "Se ha dado de alta a " + miPaciente2->GetNombre() << endl;
	else
		cout << "No se logro dar de alta a " + miPaciente2->GetNombre() << endl;

	cout << "================================================================" << endl;

	Centro1->ImprimirEnPantalla();

	//Envio las muestras al laboratorio pero en este caso 
	//al no tener un lab asociado me va a tirar un msg de error
	Centro1->MandarTesteo();

	//asocio el centro1 a uno de los 2 laboratorios
	if (Centro1->AsociarLaboratorio(Laboratorio1))
		cout << "Se asocio el " + Laboratorio1->GetNombre() + " al centro " + Centro1->GetNombre() << endl;
	else
		cout << "No se logro asociar el laboratorio al Centro" << endl;
	
	//Pruebo si funciona el control de errores de la funcion AltaPaciente
	if (Centro1->AltaPaciente(miPaciente3))
		cout << "Se ha dado de alta a " + miPaciente3->GetNombre() << endl;
	else
		cout << "No se logro dar de alta a " + miPaciente3->GetNombre() << endl;

	//asocio el centro2 al laboratorio restante
	if (Centro2->AsociarLaboratorio(Laboratorio2))
		cout << "Se asocio el " + Laboratorio2->GetNombre() + " al centro " + Centro2->GetNombre() << endl;
	else
		cout << "No se logro asociar el laboratorio al Centro" << endl;

	//Doy de alta a mi tercer paciente en el centro2
	if (Centro2->AltaPaciente(miPaciente3))
		cout << "Se ha dado de alta a " + miPaciente3->GetNombre() << endl;
	else
		cout << "No se logro dar de alta a " + miPaciente3->GetNombre() << endl;

	cout << "\n================= Envio las muestras =================" << endl;

	//Envio las muestras a los laboratorio 
	Centro1->MandarTesteo();
	Centro2->MandarTesteo();

	cout << "================= Analisis muestras =================" << endl;

	//Realizo el analisis de las muestras de cada laboratorio
	Laboratorio1->AnalisisMuestra();
	Laboratorio2->AnalisisMuestra();

	//Hago los deletes de cada uno de los objetos dinamicos
	delete miPaciente1;
	delete miPaciente2;
	delete miPaciente3;
	
	delete Centro1;
	delete Centro2;

	delete Laboratorio1;
	delete Laboratorio2;

	return 0;
}
