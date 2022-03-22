#pragma once

#include <string>

using namespace std;

enum class eResultado { SinResultado, Positivo, Negativo };

/// <summary>
/// Permite retornar un string determinado segun el 
/// enum que se le envia como parametro
/// </summary>
/// <param name="resultado"></param>
/// <returns></returns>
string ResultadoToString(eResultado resultado);
