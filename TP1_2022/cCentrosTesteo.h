#pragma once

#include <iostream>
#include <string>
#include "cPaciente.h"
#include "cLaboratorio.h"

using namespace std;

class cCentrosTesteo
{
	private:
		unsigned int IDCentro;
		string Nombre;
		string Comuna;
		bool Completo;
		cLaboratorio* Laboratorio;
		cPaciente* Paciente1;
		cPaciente* Paciente2;

	public:
	//#pragma region es una forma de tener mejor estructurado el codigo 
	#pragma region Construcctores y Destructores

		//CentrosTesteo();
		/*Constructor por defecto
		* En este caso, no se encuentra declarado porque si usamos un 
		* Constructor por parametros con defecto con todos los parametros 
		* ya declarados, se tendria en definitiva un Contructor por 
		* defecto
		*/

		/* Contructor por parametros
		*CentrosTesteo(unsigned int IDCentro,
		*	string Nombre,
		*	string Comuna,
		*	bool Completo,
		*	unsigned int IDLaboratorio);
		*/

		//Contructor por parametros por defecto
		cCentrosTesteo(unsigned int IDCentro = 0, 
			string Nombre = "Test", 
			string Comuna = "Comuna Nro");

		//Destructor
		~cCentrosTesteo();

	#pragma endregion

	#pragma region Metodos
		/// <summary>
		/// Recibe un paciente, verifica que haya un espacio para 
		/// atenderlo y si lo hay se lo asigna a uno de los 2 punteros.
		/// Caso contrario, se imprime en pantalla que el centro se encuentra lleno.
		/// </summary>
		bool AltaPaciente(cPaciente* paciente);

		/// <summary>
		/// Recibe el laboratorio al que se quiere
		/// enviar la muestra para que este determine la presencia 
		/// de COVID en elpaciente
		/// </summary>
		void MandarTesteo();

		/// <summary>
		/// Si el atributo “Resultado Testeo” de los pacientes no se
		/// encuentra en “Sin resultado” se pueden poner en NULL los 
		/// punteros a los pacientes
		/// </summary>
		void BajaPaciente();

		/// <summary>
		/// Recibe el laboratorio al cual se quiere asociar
		/// el centro de testeo
		/// </summary>
		/// <param name="laboratorio">Laboratorio a ser asociado al Centro</param>
		void AsociarLaboratorio(cLaboratorio* laboratorio);

		/// <summary>
		/// Desasocia el laboratorio asignado
		/// </summary>
		/// <param name="laboratorio"></param>
		void DesasociarLaboratorio();

	#pragma endregion
};

