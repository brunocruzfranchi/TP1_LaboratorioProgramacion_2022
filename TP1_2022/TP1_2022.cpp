// TP1_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cPaciente.h"
#include "cLaboratorio.h"
#include "cCentrosTesteo.h"

using namespace std;

int main()
{
	//Creo mis variables a utilizar, siempre DINAMICAS
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

	if (Centro1->AltaPaciente(miPaciente1))
		cout << "Se ha dado de alta a " + miPaciente1->GetNombre() << endl;

	if (Centro1->AltaPaciente(miPaciente2))
		cout << "Se ha dado de alta a " + miPaciente2->GetNombre() << endl;

	Centro1->AltaPaciente(miPaciente2);

	Centro1->MandarTesteo();

	Centro1->AsociarLaboratorio(Laboratorio1);

	if (Centro1->AltaPaciente(miPaciente3))
		cout << "Se ha dado de alta a " + miPaciente3->GetNombre() << endl;
	else
		cout << "No se logro dar de alta a " + miPaciente3->GetNombre() << endl;

	Centro2->AsociarLaboratorio(Laboratorio2);

	if (Centro2->AltaPaciente(miPaciente3))
		cout << "Se ha dado de alta a " + miPaciente3->GetNombre() << endl;

	Centro1->MandarTesteo();

	Centro2->MandarTesteo();

	Laboratorio1->AnalisisMuestra();

	Laboratorio2->AnalisisMuestra();
	
	return 0;
}
