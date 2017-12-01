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
#include <Windows.h>
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
				/*  Tiempo                      */
				const time_t tiempoInicial = time(0);
				const time_t tiempoLimite = 1800;
				const time_t tiempoDeAlerta = tiempoLimite - 30;
				bool pasoTiempoDeAlerta = false;
				time_t tiempoActual = 0;
				Timer ft;
				const float dt = ft.Mark();

				/********************************/

				/********************************/
				/*  Decisiones de juego         */
				int xElegida, yElegida;
				char direccionCambio, parar;
				bool pararJuego = false;
				char guardar;
				bool ganarJuego;

				/********************************/

				/********************************/
				/*  Instrucciones de juego      */
				Tablero pokemonGame;
				pokemonGame.SetLevel(level);
				pokemonGame.MatrizPrincipal();
				cout << endl;
				pokemonGame.HayMatchVertical();
				pokemonGame.HayMatchHorizontal();
				pokemonGame.Eliminar();
				
				/********************************/

				while (!pararJuego && (tiempoActual <= tiempoLimite) && !(pokemonGame.TerminaJuego()))
				{
					 if (!pokemonGame.HayJugadasPosibles())
					{
						pokemonGame.ReAcomodarTablero();
					}
					
					if ((tiempoActual >= tiempoDeAlerta) && !pasoTiempoDeAlerta)
					{
						cout << " Te quedan " << tiempoLimite - tiempoActual << " Segundos" << endl;
						pasoTiempoDeAlerta = true;
					}

					
					
					/********************************/
					/*  Ejecucion del juego         */
					pokemonGame.Eliminar();
					ganarJuego = pokemonGame.TerminaJuego();
					
					if (ganarJuego)
					{
						break;
					}

					/********************************/

					
					/********************************/
					/*  Interfaz                    */
					
					cout << " Puntuacion: " << pokemonGame.MostrarScores(2) << "     " <<"Pokemons: " << pokemonGame.MostrarScores(1) << endl;
					cout << endl;
					cout << " Mew: " << pokemonGame.MostrarScores(3) << "     " << "Mew2: " << pokemonGame.MostrarScores(4)
						 << "     " << "Pikachu: " << pokemonGame.MostrarScores(5) << "     " << "Raichu: " << pokemonGame.MostrarScores(6) <<  endl;
					cout << endl;
					cout << " Kirlia: " << pokemonGame.MostrarScores(7) << "     " << "Gardevoir: " << pokemonGame.MostrarScores(8) << "     "  
						 << "Staravia: " << pokemonGame.MostrarScores(9) << "     " << "Staraptor: " << pokemonGame.MostrarScores(10) << endl;
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
					pokemonGame.MoverCajas(xElegida, yElegida, direccionCambio);
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
							ofstream guardarNombre("saves_nick.txt");
							if (guardarNombre.is_open())
							{
								guardarNombre << nickname << endl;
								guardarNombre.close();
							}

							ofstream guardarPuntajes("saves_puntajes.txt");
							if (guardarPuntajes.is_open())
							{
								guardarPuntajes << level << " ";					//1
								guardarPuntajes << tiempoActual << " ";		//2
								guardarPuntajes << pokemonGame.MostrarScores(2) << " ";		//3	score
								guardarPuntajes << pokemonGame.MostrarScores(1) << " ";		//4 numPokemon
								guardarPuntajes << pokemonGame.MostrarScores(3) << " ";		//5	mew
								guardarPuntajes << pokemonGame.MostrarScores(4) << " ";		//6
								guardarPuntajes << pokemonGame.MostrarScores(5) << " ";		//7
								guardarPuntajes << pokemonGame.MostrarScores(6) << " ";		//8
								guardarPuntajes << pokemonGame.MostrarScores(7) << " ";		//9
								guardarPuntajes << pokemonGame.MostrarScores(8) << " ";		//10
								guardarPuntajes << pokemonGame.MostrarScores(9) << " ";		//11
								guardarPuntajes << pokemonGame.MostrarScores(10) << " ";	//12
								guardarPuntajes << pokemonGame.MostrarScores(11) << " ";	//13

								guardarPuntajes.close();

							}

							ofstream guardarMatriz("saves_matriz.txt");
							if (guardarMatriz.is_open())
							{
								for (int i = 0; i < 7; ++i)
								{
									for (int j = 0; j < 7; j++)
									{
										guardarMatriz << pokemonGame.BuscarCajaGuardar(j, i) << " ";
									}
									guardarMatriz << endl;
								}

								guardarMatriz.close();
							}
							cout << " Has guardado la partida, no...no....nooo lo digo porque te quiera volver a ver " << endl;
						}
						else if (guardar == 'n' || guardar == 'N')
						{
							ciclo2 = true;
						}
						else
						{
							cout << " Que no sabes seguir simples instrucciones? bueno eres tu asi que no habia mucho que esperar ^_^" << endl;
						}
					}
				}
				cout << " Gracias por jugar! so...so....solo te lo agradezco por cortesia >//< " << endl;
			}
			else
			{
				cout << " Escribe el nivel que es idota, no es que lo que digas tenga importancia alguna >//< " << endl;
			}
			

		}

		else if (menu == 'c' || menu == 'C')
		{
			//menu de cargar partida
			char empezar;
			bool ciclo3 = true;
			while (ciclo3)
			{
				cout << " Desea empezar a jugar la partida cargada? S si, N no, solo lo digo porque es mi deber no te confundas " << endl << " ";
				cin >> empezar;
				if (empezar == 's' || empezar == 'S')
				{
					/********************************/
					/*  Cargar matriz               */
					ifstream cargarJuego("saves_matriz.txt");
					//ifstream cargarJuego("lvl_1.txt");
					int matrizPokemon[7][7];
					int contenedor[7];
					int contador = 0;

					while (cargarJuego >> contenedor[0] >> contenedor[1] >> contenedor[2] >> contenedor[3] >> contenedor[4] >> contenedor[5] >> contenedor[6])
					{
						for (int i = 0; i < 7; ++i)
						{
							matrizPokemon[contador][i] = contenedor[i];
						}
						++contador;
					}
					contador = 0;

					/********************************/
					

					/********************************/
					/*  Cargar puntajes             */
					Tablero pokemonGame(matrizPokemon);
					ifstream cargarPuntajes("saves_puntajes.txt");
					int contenedor2[13];

					cargarPuntajes >> contenedor2[0] >> contenedor2[1] >> contenedor2[2] >> contenedor2[3] >> contenedor2[4] >> contenedor2[5] >>
					contenedor2[6] >> contenedor2[7] >> contenedor2[8] >> contenedor2[9] >> contenedor2[10] >> contenedor2[11] >> contenedor2[12];
				
					string nickname;
					int level = contenedor2[0];
					pokemonGame.SetScores(contenedor2);
					
					 
					/********************************/

					/********************************/
					/*  Tiempo                      */
					const time_t tiempoInicial = time(0);
					const time_t tiempoLimite = 1800;
					const time_t tiempoDeAlerta = tiempoLimite - 30;
					bool pasoTiempoDeAlerta = false;
					time_t tiempoActual = contenedor2[1];
					float dt = pokemonGame.DarTiempo().Mark();

					/********************************/
			
					/********************************/
					/*  Decisiones de juego         */
					int xElegida, yElegida;
					char direccionCambio, parar;
					bool pararJuego = false;
					char guardar;
					bool ganarJuego;
	

					/********************************/

					/********************************/
					/*  Instrucciones de juego      */
					pokemonGame.MatrizPrincipal();
					cout << endl;
					pokemonGame.HayMatchVertical();
					pokemonGame.HayMatchHorizontal();
					pokemonGame.Eliminar();

					/********************************/

					while (!pararJuego && (tiempoActual <= tiempoLimite) && !(pokemonGame.TerminaJuego()))
					{
						if (!pokemonGame.HayJugadasPosibles())
						{
							pokemonGame.ReAcomodarTablero();
						}
						dt = pokemonGame.DarTiempo().Mark();
						tiempoActual = time(0) - tiempoInicial;
						if ((tiempoActual >= tiempoDeAlerta) && !pasoTiempoDeAlerta)
						{
							cout << " Te quedan " << tiempoLimite - tiempoActual << " Segundos" << endl;
							pasoTiempoDeAlerta = true;
						}


						/********************************/
						/*  Ejecucion del juego         */
						pokemonGame.Eliminar();
						ganarJuego = pokemonGame.TerminaJuego();

						if (ganarJuego)
						{
							break;
						}

						/********************************/


						/********************************/
						/*  Interfaz                    */
						MessageBox(nullptr, L"Hola ", L"Bienvenido al juego",MB_OK);
						
						cout << " Puntuacion: " << pokemonGame.MostrarScores(2) << "     " << "Pokemons: " << pokemonGame.MostrarScores(1) << "    " << dt << "    " << tiempoActual << endl;
						cout << endl;
						cout << " Mew: " << pokemonGame.MostrarScores(3) << "     " << "Mew2: " << pokemonGame.MostrarScores(4)
							<< "     " << "Pikachu: " << pokemonGame.MostrarScores(5) << "     " << "Raichu: " << pokemonGame.MostrarScores(6) << endl;
						cout << endl;
						cout << " Kirlia: " << pokemonGame.MostrarScores(7) << "     " << "Gardevoir: " << pokemonGame.MostrarScores(8) << "     "
							<< "Staravia: " << pokemonGame.MostrarScores(9) << "     " << "Staraptor: " << pokemonGame.MostrarScores(10) << endl;
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
						pokemonGame.MoverCajas(xElegida, yElegida, direccionCambio);
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
						dt = pokemonGame.DarTiempo().Mark();
					}

					if (pararJuego && !ganarJuego)
					{
						bool ciclo5 = false;
						while (!ciclo5)
						{
							cout << " Desea guardar la partida? no lo pregunto porque importes  >_< " << endl;
							cout << " Si S, No N" << endl;
							cout << " ";
							cin >> guardar;
							if (guardar == 's' || guardar == 'S')
							{
								ciclo5 = true;
								ofstream guardarNombre("saves_nick.txt");
								if (guardarNombre.is_open())
								{
									guardarNombre << nickname << endl;
									guardarNombre.close();
								}

								ofstream guardarPuntajes("saves_puntajes.txt");
								if (guardarPuntajes.is_open())
								{
									guardarPuntajes << level << endl;					//1
									guardarPuntajes << tiempoActual << endl;		//2
									guardarPuntajes << pokemonGame.MostrarScores(2) << endl;		//3	score
									guardarPuntajes << pokemonGame.MostrarScores(1) << endl;		//4 numPokemon
									guardarPuntajes << pokemonGame.MostrarScores(3) << endl;		//5	mew
									guardarPuntajes << pokemonGame.MostrarScores(4) << endl;		//6
									guardarPuntajes << pokemonGame.MostrarScores(5) << endl;		//7
									guardarPuntajes << pokemonGame.MostrarScores(6) << endl;		//8
									guardarPuntajes << pokemonGame.MostrarScores(7) << endl;		//9
									guardarPuntajes << pokemonGame.MostrarScores(8) << endl;		//10
									guardarPuntajes << pokemonGame.MostrarScores(9) << endl;		//11
									guardarPuntajes << pokemonGame.MostrarScores(10) << endl;	//12
									guardarPuntajes << pokemonGame.MostrarScores(11) << endl;	//13
													
									guardarPuntajes.close();

								}

								ofstream guardarMatriz("saves_matriz.txt");
								if (guardarMatriz.is_open())
								{
									for (int i = 0; i < 7; ++i)
									{
										for (int j = 0; j < 7; j++)
										{
											guardarMatriz << pokemonGame.BuscarCajaGuardar(j, i) << " ";
										}
										guardarMatriz << endl;
									}

									guardarMatriz.close();
								}
								cout << " Has guardado la partida, no...no....nooo lo digo porque te quiera volver a ver " << endl;
							}
							else if (guardar == 'n' || guardar == 'N')
							{
								ciclo5 = true;
							}
							else
							{
								cout << " Que no sabes seguir simples instrucciones? bueno eres tu asi que no habia mucho que esperar ^_^" << endl;
							}
						}
					}
					cout << " Gracias por jugar! so...so....solo te lo agradezco por cortesia >//< " << endl;
				}
				else if (empezar == 'n' || empezar == 'N')
				{
					ciclo3 = false;
				}
				else
				{
					cout << " Que tan dificl es escribir las opciones que son " << endl;
				}
			}
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


		}
		else
		{
			cout << " Escribe una opcion correcta idiota, no es que me importe que lo escribas bien ni nada >//< " << endl;
		}
	}
    return 0;
}

