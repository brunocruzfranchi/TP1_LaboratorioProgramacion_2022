#pragma once

#include <iostream>
#include <string>
#include "Enums.h"

using namespace std;

class cPaciente
{
	private:
		string Nombre;
		string Apellido;
		string DNI;
		string Telefono;
		bool Fiebre;
		bool Tos;
		bool Mocos;
		bool ContactoEstrecho;
		bool DolorCabeza;
		bool DolorGarganta;
		eResultado ResultadoTesteo;

	public:
		
		#pragma region Constructores y Destructores

			//Constructor por parametros por defecto
			cPaciente(string Nombre, string Apellido, string DNI, string Telefono,
				bool Fiebre, bool Tos, bool Mocos, bool ContactoEstrecho, bool DolorCabeza, bool DolorGarganta);
		
			//Destructor
			~cPaciente();

		#pragma endregion

		#pragma region Metodos
		
			eResultado GetResultadoTesteo();
			
			int GetCantSintomas();

			string GetDNI();

			string GetNombre();

			void SetResultadoTesteo(eResultado resultado);
			
			string ToString();

		#pragma endregion	

};

