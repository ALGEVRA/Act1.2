#ifndef _SORT_METHODS_H_
#define _SORT_METHODS_H_

#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

template <class T> class SortMethod {
private:
  void Merge(std::vector<T> &vector, int low, int mid, int high, unsigned int &compara);
  int partition(std::vector<T> &vector, int low, int high, unsigned int &compara, unsigned int &swaps);

public:
  SortMethod();
  ~SortMethod();
  void Bubble(std::vector<T> &vector, int size, unsigned int &compara, unsigned int &swaps);
  void MergeSort(std::vector<T> &vector, int low, int high, unsigned int &compara);
  void QuickSort(std::vector<T> &vector, int low, int high, unsigned int &compara, unsigned int &swaps);

  int SecuencialOrdenado(std::vector<T> &vector, int key, int &compara);
  int BinariaRecursiva(std::vector<T> &vector, int low, int high, int key, int &compara);

  void printVector(std::vector<T> vector);
  

};
template <class T> 
SortMethod<T>::SortMethod(){

}
template <class T> 
SortMethod<T>::~SortMethod(){

}

template <class T>
void SortMethod<T>::printVector(std::vector<T> vector){
    cout << "Los elementos del vector ordenado son: " << endl;
    for(int i = 0; i < (int)vector.size(); i++){
    cout << vector[i] << " ";
  }
  cout << endl;
}

template <class T> 
void SortMethod<T>::Bubble(std::vector<T> &vector, int size, unsigned int &compara, unsigned int &swaps){
  compara = swaps = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      compara++;
      if (vector[j] > vector[j+1]){
        std::swap(vector[j], vector[j+1]);
        swaps++;
      }
    }
  }
}


template <class T>
void SortMethod<T>::MergeSort(std::vector<T> &vector, int low, int high, unsigned int &compara){
  if(low < high){
    //encontrar punto medio
    int mid = low + (high - low) / 2;
    //ordenar dos mitades
    MergeSort(vector, low, mid, compara);
    MergeSort(vector, mid + 1, high, compara);
    //fusionar ambas mitades
    Merge(vector, low, mid, high, compara);    
  }
}

template <class T>
void SortMethod<T>::Merge(std::vector<T> &vector, int low, int mid, int high, unsigned int &compara){
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;
  //creamos los vectores auxiliares L y R
  std::vector<T> L(n1);
  std::vector<T> R(n2);
  for(i = 0; i < n1; i++) L[i] = vector[low + i];
  for(j = 0; j < n2; j++) R[j] = vector[mid + 1 + j];

  //fusionar los vecotres auxiliados L y R ordenados
  i = 0;
  j = 0;
  k = low;
  while(i < n1 && j < n2){
    compara++;
    if(L[i] < R[j]){
      vector[k] = L[i];
      i++;
    }
    else{
      vector[k] = R[j];
      j++;
    }
    k++;
  }
  //Copia los elementos restantes
  while(i < n1){
    vector[k] = L[i];
    i++;
    k++;
  }
  while(j < n2){
    vector[k] = R[j];
    j++;
    k++;
  }
}

template <class T>
void SortMethod<T>::QuickSort(std::vector<T> &vector, int low, int high, unsigned int &compara, unsigned int &swaps){
  if (low < high) {
    // encontrar la particion
    int pivot = partition(vector, low, high, compara, swaps);
    // ordenar la mitad izquierda y derecha
    QuickSort(vector, low, pivot - 1, compara, swaps);
    QuickSort(vector, pivot + 1, high, compara, swaps);
  }
}

template <class T>
int SortMethod<T>::partition(std::vector<T> &vector, int low, int high, unsigned int &compara, unsigned int &swaps){
  int pivot = vector[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    compara++;
    if (vector[j] < pivot) {
      i++;
      std::swap(vector[i], vector[j]);
      swaps++;
    }
  }
  std::swap(vector[i + 1], vector[high]);
  return i + 1;
}


template <class T>
int SortMethod<T>::SecuencialOrdenado(std::vector<T> &vector, int key, int &compara){
  compara = 0;
  for (int i = 0; i < (int)vector.size(); ++i){
    ++compara;
    if (key <= vector[i]){
      if (key == vector[i])
        return i;
      else
        return -1;
    }
  }
  return -1;
}
template <class T>
int SortMethod<T>::BinariaRecursiva(vector<T> &vector, int low, int high, int key, int &compara){
  int m;
  if (low > high) return -1;
  m = low + (high -low)/2;
  compara++;
  if (key == vector[m]) return m;
  else if (key < vector[m])
    return BinariaRecursiva(vector, low, m - 1, key, compara);
  else 
    return BinariaRecursiva(vector, m + 1, high, key, compara);
}

#endif
