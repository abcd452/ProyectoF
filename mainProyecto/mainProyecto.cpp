// mainProyecto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include "Caja.h"
#include "Coordenadas.h"
#include "Tablero.h"
using namespace std;

//int guardarPartida();

int main()
{
	bool cerrarJuego = false;
	char menu;
	while (!cerrarJuego)
	{
		cout << " Que desea hacer? " << endl;
		cout << " Jugar (press P) " << endl;
		cout << " Cargar ultima partida (press C) " << endl;
		cout << " Salir (press E) " << endl;
		cout << " ";
		cin >> menu;
		if (menu == 'p' || menu == 'P')
		{
			int level;
			
			string nickname;
			cout << " hmm, Cual es tu nombre?" << endl;
			cout << " ";
			cin >> nickname;
			cout << " " << nickname << " Que nombre tan patetico " << endl;
			cout << endl;
			bool ciclo1 = false;
			while (!ciclo1)
			{
				cout << " Que nivel deseas jugar? no es que este interesada en tu respuesta >-< " << endl;
				cout << " 1 (facil) 2 (intermedio) " << endl;
				cout << " ";
				cin >> level;
				if (level == 1)
				{
					ciclo1 = true;
				}
				else if (level == 2)
				{
					ciclo1 = true;
				}
				else
				{
					cout << " Que ni puedes escoger el nivel que es?  " << endl;
				}
				cout << endl;
			}
			
			if (level == 1 || level == 2)
			{
				/********************************/
				/*  Puntajes                    */
				int numEvoluciones = 0;
				int numPokemon = 20;
				int scoreTotal = 0;
				int numMew = 3;
				int numMew2 = 2;
				int numPikachu = 3;
				int numRaichu = 2;
				int numKirlia = 3;
				int numGardevoir = 2;
				int numStaravia = 3;
				int numStaraptor = 2;
				int numPokebola = 0; //por ahora no
				bool ganarJuego = false;

				if (level == 2)
				{
					numEvoluciones = 0;
					numPokemon = 400;
					scoreTotal = 0;

					numMew = 60;
					numMew2 = 4;
					numPikachu = 6;
					numRaichu = 4;
					numKirlia = 6;
					numGardevoir = 4;
					numStaravia = 6;
					numStaraptor = 4;
					numPokebola = 0; //por ahora no 
				}
				/********************************/

				/********************************/
				/*  Tiempo                      */
				const time_t tiempoInicial = time(0);
				const time_t tiempoLimite = 1800;
				const time_t tiempoDeAlerta = tiempoLimite - 30;
				bool pasoTiempoDeAlerta = false;
				time_t tiempoActual = 0;

				/********************************/

				/********************************/
				/*  Decisiones de juego         */
				int xElegida, yElegida;
				char direccionCambio, parar;
				bool pararJuego = false;
				char guardar;
				bool esPrimerCiclo = true;

				/********************************/

				/********************************/
				/*  Decisiones de juego         */
				Tablero gameLvl1;
				gameLvl1.MatrizPrincipal();
				cout << endl;
				gameLvl1.HayMatchVertical();
				gameLvl1.HayMatchHorizontal();
				gameLvl1.Eliminar();
				
				/********************************/

				while (!pararJuego && (tiempoActual <= tiempoLimite) && !ganarJuego)
				{
					 if (!gameLvl1.HayJugadasPosibles())
					{
						gameLvl1.ReAcomodarTablero();
					}
					
					if ((tiempoActual >= tiempoDeAlerta) && !pasoTiempoDeAlerta)
					{
						cout << " Te quedan " << tiempoLimite - tiempoActual << " Segundos" << endl;
						pasoTiempoDeAlerta = true;
					}

					if (esPrimerCiclo)
					{
						gameLvl1.MostrarScores();
						esPrimerCiclo = false;
					}
					
					/********************************/
					/*  Ejecucion del juego         */
					gameLvl1.Eliminar();

					scoreTotal = gameLvl1.MostrarScores()[2];
					if (numPokemon - gameLvl1.MostrarScores()[1] < 0)
					{
						numPokemon =0;
					}
					else
					{
						numPokemon -= gameLvl1.MostrarScores()[1];
					}

					if (numMew - gameLvl1.MostrarScores()[3] < 0)
					{
						numMew = 0;
					}
					else
					{
						numMew -= gameLvl1.MostrarScores()[3];
					}

					if (numMew2 - gameLvl1.MostrarScores()[4] < 0)
					{
						numMew2 = 0;
					}
					else
					{
						numMew2 -= gameLvl1.MostrarScores()[4];
					}

					if (numPikachu - gameLvl1.MostrarScores()[5] < 0)
					{
						numPikachu = 0;
					}
					else
					{
						numPikachu -= gameLvl1.MostrarScores()[5];
					}

					if (numRaichu - gameLvl1.MostrarScores()[6] < 0)
					{
						numRaichu = 0;
					}
					else
					{
						numRaichu -= gameLvl1.MostrarScores()[6];
					}

					if (numKirlia - gameLvl1.MostrarScores()[7] < 0)
					{
						numKirlia = 0;
					}
					else
					{
						numKirlia -= gameLvl1.MostrarScores()[7];
					}

					if (numGardevoir - gameLvl1.MostrarScores()[8] < 0)
					{
						numGardevoir = 0;
					}
					else
					{
						numGardevoir -= gameLvl1.MostrarScores()[8];
					}

					if (numStaravia - gameLvl1.MostrarScores()[9] < 0)
					{
						numStaravia = 0;
					}
					else
					{
						numStaravia -= gameLvl1.MostrarScores()[9];
					}

					if (numStaraptor - gameLvl1.MostrarScores()[10] < 0)
					{
						numStaraptor = 0;
					}
					else
					{
						numStaraptor -= gameLvl1.MostrarScores()[10];
					}

					if (numPokebola - gameLvl1.MostrarScores()[11] < 0)
					{
						numPokebola = 0;
					}
					else
					{
						numPokebola -= gameLvl1.MostrarScores()[11];
					}

					ganarJuego = (( (numMew <= 0) && (numMew2 <= 0) &&
									(numPikachu <= 0) && (numRaichu <= 0) &&
									(numKirlia <= 0) && (numGardevoir <= 0) &&
									(numStaravia <= 0) && (numStaraptor <= 0) &&
									(numPokebola <= 0)) ||
									(numPokemon <= 0));
					gameLvl1.SetToZero();
					if (ganarJuego)
					{
						break;
					}

					/********************************/

					
					/********************************/
					/*  Interfaz                    */
					cout << " Puntuacion: " << scoreTotal << "     " <<"Pokemons: " << numPokemon << endl;
					cout << endl;
					cout << " Mew: " << numMew << "     " << "Mew2: " << numMew2 << "     " << "Pikachu: " << numPikachu << "     " << "Raichu: " << numRaichu <<  endl;
					cout << endl;
					cout << " Kirlia: " << numKirlia << "     " << "Gardevoir: " << numGardevoir << "     "  << "Staravia: " << numStaravia << "     " << "Staraptor: " << numStaraptor << endl;
					cout << endl;
					cout << " Diga la columna (1 a 7) : ";
					cout << " ";
					cin >> xElegida;
					cout << " Diga la fila (1 a 7) : ";
					cout << " ";
					cin >> yElegida;
					cout << " Decida hacia que direccion cambiara este pokemon :";
					cout << " ";
					cin >> direccionCambio;
					gameLvl1.MoverCajas(xElegida, yElegida, direccionCambio);
					cout << " Decida si va a continuar Y si, N no ";
					cout << endl;

					/********************************/

					/********************************/
					/*  Parar el juego              */
					cout << " ";
					cin >> parar;
					if (parar == 'n' || parar == 'N')
					{
						pararJuego = true;
					}
					else
					{
						pararJuego = false;
					}

					/********************************/

					tiempoActual = time(0) - tiempoInicial;	//lleva el tiempo transcurrido
				}

				if (pararJuego && !ganarJuego)
				{
					bool ciclo2 = false;
					while (!ciclo2)
					{
						cout << " Desea guardar la partida? no lo pregunto porque importes  >_< " << endl;
						cout << " Si S, No N" << endl;
						cout << " ";
						cin >> guardar;
						if (guardar == 's' || guardar == 'S')
						{
							ciclo2 = true;
							ofstream guardarPartida("saves.txt");
							if (guardarPartida.is_open())
							{
								guardarPartida << nickname << endl;			//1
								guardarPartida << tiempoActual << endl;		//2
								guardarPartida << scoreTotal << endl;		//3
								guardarPartida << numEvoluciones << endl;	//4
								guardarPartida << numPokemon << endl;		//5
								guardarPartida << numMew << endl;			//6
								guardarPartida << numMew2 << endl;			//7
								guardarPartida << numPikachu << endl;		//8
								guardarPartida << numRaichu << endl;		//9
								guardarPartida << numKirlia << endl;		//10
								guardarPartida << numGardevoir << endl;		//11
								guardarPartida << numStaravia << endl;		//12
								guardarPartida << numStaraptor << endl;		//13
								guardarPartida << numPokebola << endl;		//14
								guardarPartida << level << endl;			//15

								for (int i = 0; i < 7; ++i)
								{
									for (int j = 0; j < 7; j++)
									{
										guardarPartida << gameLvl1.BuscarCajaGuardar(j, i) << " \t";
									}
									guardarPartida << endl;
								}

								guardarPartida.close();
							}
						}
						else if (guardar == 'n' || guardar == 'N')
						{
							ciclo2 = true;
						}
						else
						{
							cout << " Que no sabes seguir simples instrucciones? bueno eres tu asi que no habia mucho que esperar" << endl;
						}
					}
				}
				cout << " Gracias por jugar! so...so....solo te lo agradesco por cortesia >//< " << endl;
			}
			else
			{
				cout << " Escribe el nivel que es idota, no es que lo que digas tenga importancia alguna >//< " << endl;
			}
			

		}

		else if (menu == 'c' || menu == 'C')
		{
			//menu de cargar partida
			cout << " Desea empesar a jugar " << endl;
		}
		else if (menu == 'e' || menu == 'E')
		{
			cerrarJuego = true;
		}
		else if (menu == 't' || menu == 'T')
		{
			int matrix[7][7];
			matrix[0][0] = 1;
			matrix[0][1] = 2;
			matrix[0][2] = 3;
			matrix[0][3] = 4;
			matrix[0][4] = 5;
			matrix[0][5] = 6;
			matrix[0][6] = 7;
			
			matrix[1][0] = 2;
			matrix[1][1] = 4;
			matrix[1][2] = 5;
			matrix[1][3] = 6;
			matrix[1][4] = 7;
			matrix[1][5] = 1;
			matrix[1][6] = 2;

			matrix[2][0] = 3;
			matrix[2][1] = 5;
			matrix[2][2] = 0;
			matrix[2][3] = 7;
			matrix[2][4] = 4;
			matrix[2][5] = 1;
			matrix[2][6] = 1;

			matrix[3][0] = 4;
			matrix[3][1] = 6;
			matrix[3][2] = 7;
			matrix[3][3] = 1;
			matrix[3][4] = 2;
			matrix[3][5] = 7;
			matrix[3][6] = 5;

			matrix[4][0] = 5;
			matrix[4][1] = 7;
			matrix[4][2] = 4;
			matrix[4][3] = 2;
			matrix[4][4] = 0;
			matrix[4][5] = 3;
			matrix[4][6] = 3;

			matrix[5][0] = 6;
			matrix[5][1] = 1;
			matrix[5][2] = 1;
			matrix[5][3] = 7;
			matrix[5][4] = 3;
			matrix[5][5] = 7;
			matrix[5][6] = 4;

			matrix[6][0] = 7;
			matrix[6][1] = 2;
			matrix[6][2] = 1;
			matrix[6][3] = 5;
			matrix[6][4] = 3;
			matrix[6][5] = 4;
			matrix[6][6] = 0;

			
			int numEvoluciones = 0;
			int numPokemon = 20;
			int scoreTotal = 0;
			int numMew = 3;
			int numMew2 = 2;
			int numPikachu = 3;
			int numRaichu = 2;
			int numKirlia = 3;
			int numGardevoir = 2;
			int numStaravia = 3;
			int numStaraptor = 2;
			int numPokebola = 0; //por ahora no
			bool ganarJuego = false;
		
		/********************************/

		/********************************/
		/*  Tiempo                      */
		const time_t tiempoInicial = time(0);
		const time_t tiempoLimite = 1800;
		const time_t tiempoDeAlerta = tiempoLimite - 30;
		bool pasoTiempoDeAlerta = false;
		time_t tiempoActual = 0;

		/********************************/

		/********************************/
		/*  Decisiones de juego         */
		int xElegida, yElegida;
		char direccionCambio, parar;
		bool pararJuego = false;
		char guardar;
		bool esPrimerCiclo = true;

		/********************************/

		/********************************/
		/*  Decisiones de juego         */
		Tablero gameLvl1(matrix);
		gameLvl1.MatrizPrincipal();
		cout << endl;
		gameLvl1.HayMatchVertical();
		gameLvl1.HayMatchHorizontal();
		gameLvl1.Eliminar();

		/********************************/

		while (!pararJuego && (tiempoActual <= tiempoLimite) && !ganarJuego)
		{
			if (!gameLvl1.HayJugadasPosibles())
			{
				gameLvl1.ReAcomodarTablero();
			}

			if ((tiempoActual >= tiempoDeAlerta) && !pasoTiempoDeAlerta)
			{
				cout << " Te quedan " << tiempoLimite - tiempoActual << " Segundos" << endl;
				pasoTiempoDeAlerta = true;
			}

			if (esPrimerCiclo)
			{
				gameLvl1.MostrarScores();
				esPrimerCiclo = false;
			}

			/********************************/
			/*  Ejecucion del juego         */
			gameLvl1.Eliminar();

			scoreTotal = gameLvl1.MostrarScores()[2];
			if (numPokemon - gameLvl1.MostrarScores()[1] < 0)
			{
				numPokemon = 0;
			}
			else
			{
				numPokemon -= gameLvl1.MostrarScores()[1];
			}

			if (numMew - gameLvl1.MostrarScores()[3] < 0)
			{
				numMew = 0;
			}
			else
			{
				numMew -= gameLvl1.MostrarScores()[3];
			}

			if (numMew2 - gameLvl1.MostrarScores()[4] < 0)
			{
				numMew2 = 0;
			}
			else
			{
				numMew2 -= gameLvl1.MostrarScores()[4];
			}

			if (numPikachu - gameLvl1.MostrarScores()[5] < 0)
			{
				numPikachu = 0;
			}
			else
			{
				numPikachu -= gameLvl1.MostrarScores()[5];
			}

			if (numRaichu - gameLvl1.MostrarScores()[6] < 0)
			{
				numRaichu = 0;
			}
			else
			{
				numRaichu -= gameLvl1.MostrarScores()[6];
			}

			if (numKirlia - gameLvl1.MostrarScores()[7] < 0)
			{
				numKirlia = 0;
			}
			else
			{
				numKirlia -= gameLvl1.MostrarScores()[7];
			}

			if (numGardevoir - gameLvl1.MostrarScores()[8] < 0)
			{
				numGardevoir = 0;
			}
			else
			{
				numGardevoir -= gameLvl1.MostrarScores()[8];
			}

			if (numStaravia - gameLvl1.MostrarScores()[9] < 0)
			{
				numStaravia = 0;
			}
			else
			{
				numStaravia -= gameLvl1.MostrarScores()[9];
			}

			if (numStaraptor - gameLvl1.MostrarScores()[10] < 0)
			{
				numStaraptor = 0;
			}
			else
			{
				numStaraptor -= gameLvl1.MostrarScores()[10];
			}

			if (numPokebola - gameLvl1.MostrarScores()[11] < 0)
			{
				numPokebola = 0;
			}
			else
			{
				numPokebola -= gameLvl1.MostrarScores()[11];
			}

			ganarJuego = (((numMew <= 0) && (numMew2 <= 0) &&
				(numPikachu <= 0) && (numRaichu <= 0) &&
				(numKirlia <= 0) && (numGardevoir <= 0) &&
				(numStaravia <= 0) && (numStaraptor <= 0) &&
				(numPokebola <= 0)) ||
				(numPokemon <= 0));
			if (ganarJuego)
			{
				break;
			}

			/********************************/


			/********************************/
			/*  Interfaz                    */
			cout << " Puntuacion: " << scoreTotal << "     " << "Pokemons: " << numPokemon << endl;
			cout << endl;
			cout << " Mew: " << numMew << "     " << "Mew2: " << numMew2 << "     " << "Pikachu: " << numPikachu << "     " << "Raichu: " << numRaichu << endl;
			cout << endl;
			cout << " Kirlia: " << numKirlia << "     " << "Gardevoir: " << numGardevoir << "     " << "Staravia: " << numStaravia << "     " << "Staraptor: " << numStaraptor << endl;
			cout << endl;
			cout << " Diga la columna (1 a 7) : ";
			cout << " ";
			cin >> xElegida;
			cout << " Diga la fila (1 a 7) : ";
			cout << " ";
			cin >> yElegida;
			cout << " Decida hacia que direccion cambiara este pokemon :";
			cout << " ";
			cin >> direccionCambio;
			gameLvl1.MoverCajas(xElegida, yElegida, direccionCambio);
			cout << " Decida si va a continuar Y si, N no ";
			cout << endl;

			/********************************/

			/********************************/
			/*  Parar el juego              */
			cout << " ";
			cin >> parar;
			if (parar == 'n' || parar == 'N')
			{
				pararJuego = true;
			}
			else
			{
				pararJuego = false;
			}

			/********************************/

				tiempoActual = time(0) - tiempoInicial;	//lleva el tiempo transcurrido
			}
		}
		else
		{
			cout << " Escribe una opcion correcta idota, no es que me importe que lo escribas bien ni nada >//< " << endl;
		}
	}
    return 0;
}

