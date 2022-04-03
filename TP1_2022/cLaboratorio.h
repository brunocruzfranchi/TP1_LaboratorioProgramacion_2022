#pragma once

#include <iostream>
#include <string>
#include "cPaciente.h"

using namespace std;


class cLaboratorio
{
	private:
		unsigned int IDLaboratorio;
		string Nombre;
		string Comuna;
		bool Completo;
		cPaciente* Paciente1;
		cPaciente* Paciente2;

	public:

	#pragma region Constructores y Destructores

		cLaboratorio(unsigned int IDLaboratorio,
			string Nombre,
			string Comuna);

		~cLaboratorio();

	#pragma endregion

	#pragma region Metodos

		/// <summary>
		/// Recibe un paciente y se fija si tiene lugar para analizar
		/// la muestra.
		/// </summary>
		/// <param name="paciente"></param>
		void RecibirMuestra(cPaciente* paciente);

		/// <summary>
		/// Determina a partir de los datos descriptivos del
		/// paciente si este tiene COVID o no, y cambia el atributo “Resultado testeo”
		/// a su correspondiente resultado.
		///		Positivo : Si el paciente presenta más de 2 síntomas
		///		Negativo: Si el paciente presenta menos de 2 síntomas
		/// </summary>
		void AnalisisMuestra();

		/// <summary>
		/// Manda un mensaje de texto al paciente con la
		/// información del testeo(imprimir en pantalla si se logró mandar el
		/// mensaje).Una vez que se avisa a los pacientes, se descantan las
		///	muestras.
		/// </summary>
		void AvisarPacientes();

		unsigned int GetIDLaboratorio();		
		
		string GetNombre();

		bool IsCompleto();

		string ToString();

	#pragma endregion
};

