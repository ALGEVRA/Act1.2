#include <iostream>
#include <chrono>
#include <vector>
#include "SortAndSearchMethods.h"

using namespace std;

int main(void) {
  int size, ordenar, busqueda, key;
  unsigned int comparacionesOrd, swaps;

  cin >> size; 
  cout << "Size: " << size << endl;

  cin >> ordenar;

  cin >> busqueda;
  
  cin >> key;
  cout << "Key: " << key << endl;

  //Creamos nuestro vector a ordenar
  std::vector<int> Vector(size);

  // Lectura de los elementos del vector
  for(int i = 0; i < size; i++) {
    cin >> Vector[i];
  }
  cout << "\n";


  // Instancia un objeto de la clase AlgoritmoSort
  SortMethod<int> sortObj;

  if(ordenar == 1){ // Ordenamiento del Vector utilizando Bubble Sort
    //Inicio conteo de tiempo de ejecucion
    auto startTime = std::chrono::high_resolution_clock::now();
    cout << "Bubble Sort:" << endl;
    comparacionesOrd = swaps = 0;
    sortObj.Bubble(Vector, size, comparacionesOrd, swaps);
    sortObj.printVector(Vector);
    //Termina conteo de tiempo de ejecucion
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Comparaciones de Ordenamiento: " << comparacionesOrd << endl;
    cout << "Intercambios: " << swaps << endl;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << "\n" << endl;
  }

  else if(ordenar == 2){ // Ordenamiento del Vector utilizando Merge Sort
    auto startTime = std::chrono::high_resolution_clock::now();
    cout << "Merge Sort:" << endl;
    comparacionesOrd = 0;
    sortObj.MergeSort(Vector, 0, size - 1, comparacionesOrd);
    sortObj.printVector(Vector);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Comparaciones: " << comparacionesOrd << endl;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << "\n" << endl;
  }

  else if(ordenar == 3){ // Ordenamiento del Vector utilizando Quick Sort
    auto startTime = std::chrono::high_resolution_clock::now();
    cout << "Quick Sort:" << endl;
    sortObj.QuickSort(Vector, 0, size - 1, comparacionesOrd, swaps);
    sortObj.printVector(Vector);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Comparaciones: " << comparacionesOrd << endl;
    cout << "Intercambios: " << swaps << endl;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << "\n" << endl;
  }

  int comparacionesBS = 0;
  int comparacionesBB = 0;


  if(busqueda == 1){
    auto startTime = std::chrono::high_resolution_clock::now();
    cout << "Busqueda Secuencial \nKey se encuentra en indice: " << sortObj.SecuencialOrdenado(Vector, key, comparacionesBS) << endl;
    cout << "Comparaciones de Busqueda: " << comparacionesBS << endl;
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;
  } 
  if(busqueda == 2){
    auto startTime = std::chrono::high_resolution_clock::now();
    cout << "Busqueda Binaria \nKey se encuentra en indice: " << sortObj.BinariaRecursiva(Vector, 0, size-1, key, comparacionesBB) << endl;
    cout << "Comparaciones de Busqueda: " << comparacionesBB << endl;
    auto endTime = std::chrono::high_resolution_clock::now();
    auto totalTime = endTime - startTime;
    cout << "Tiempo de ejecución en ms: " << totalTime/std::chrono::milliseconds(1) << endl;
  } 
                  
  return 0;

}