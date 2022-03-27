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
		/// Caso contrario, se imprime en pantalla el error que se tuvo.
		/// </summary>
		/// <param name="paciente">Paciente a ser dado de alta</param>
		bool AltaPaciente(cPaciente* paciente);

		/// <summary>
		/// Manda las muestras al laboratorio asignado
		/// para que este determine la presencia 
		/// de COVID en el paciente
		/// </summary>
		void MandarTesteo();

		/// <summary>
		/// Si el atributo “Resultado Testeo” de los pacientes es
		/// diferente a “Sin resultado”, se pueden poner en NULL 
		/// los punteros a los pacientes.
		/// </summary>
		void BajaPaciente();

		/// <summary>
		/// Recibe el laboratorio al cual se quiere asociar
		/// el centro de testeo
		/// </summary>
		/// <param name="laboratorio">Laboratorio a ser asociado al Centro</param>
		bool AsociarLaboratorio(cLaboratorio* laboratorio);

		/// <summary>
		/// Desasocia el laboratorio asignado
		/// </summary>
		void DesasociarLaboratorio();
		
		/// <summary>
		/// Imprime en pantalla la informacion 
		/// del Centro de Testeo
		/// </summary>
		void ImprimirEnPantalla();

		/// <summary>
		/// Realiza un resumen de todos los atributos
		/// del Centro y los retorna en un texto de 
		/// tipo string
		/// </summary>
		/// <returns>Informacion del centro</returns>
		string ToString();

		string GetNombre();

	#pragma endregion
};

