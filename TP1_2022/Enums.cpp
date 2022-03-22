#include "Enums.h"

string ResultadoToString(eResultado resultado)
{
	switch (resultado)
	{
		case eResultado::SinResultado:
			return "SinResultado";
			break;
		case eResultado::Positivo:
			return "Positivo";
			break;
		case eResultado::Negativo:
			return "Negativo";
			break;
		default:
			return "";
			break;
	}
}
