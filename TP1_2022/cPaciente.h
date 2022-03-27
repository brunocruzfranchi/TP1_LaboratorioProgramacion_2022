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
			
			/// <summary>
			/// Cuenta la cantidad de sintomas positivos
			/// </summary>
			/// <returns>variable int representando la cant. de sintomas positivos</returns>
			int GetCantSintomas();

			string GetDNI();

			string GetNombre();

			void SetResultadoTesteo(eResultado resultado);
			
			/// <summary>
			/// Retorna un string con el siguiente formato:
			/// Nombre + Apellido + DNI 
			/// </summary>
			/// <returns>string conteniendo parametros del paciente</returns>
			string ToString();

		#pragma endregion	

};

