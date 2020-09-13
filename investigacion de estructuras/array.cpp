#include <iostream>
#include <fstream>
#include <array>
#include <sys/time.h>
#include <ctime>
#include "windows.h"

using namespace std;

int main() {
  
	array<string,194434>a1;

	ifstream fe("english3.txt"); 
	
	clock_t t_ini, t_fin;
	
  	ofstream file;
  	file.open("tiempo_array.txt");
	
	for(int i=0;!fe.eof();i++){
	    t_ini = clock();
		fe >>a1[i];
		t_fin = clock();
		double secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		file<<secs<<endl;
	}

	fe.close();
	srand(time(0));
	
	string aleatorio[100];
	for(int i=0; i<100; i++){
		int aux = (1 + rand() % 194432);
		aleatorio[i]=a1[aux];
	}
	
	//busqueda
	clock_t t_ini2, t_fin2;
	t_ini2 = clock();
	for(int i=0; i<100;i++){
		for(int j=0; j<a1.size();j++){
			if(aleatorio[i]==a1[j]){
				break;
			}
		}
	}
	t_fin2 = clock();
	double secs2 = (double)(t_fin2 - t_ini2) / CLOCKS_PER_SEC;
	cout<<"tiempo de busqueda "<<secs2<<endl;
	cout<<"tiempo de busqueda promedio "<<secs2/a1.size()<<endl;

	//eliminar
	clock_t t_ini3, t_fin3;
	t_ini3 = clock();
	for(int i=0; i<100;i++){
		for(int j=0; j<a1.size();j++){
			if(aleatorio[i]==a1[j]){
				for(int l=j; l<a1.size()-1;l++){
					a1[l]=a1[l+1];
				}
				break;
			}
		}
	}
	t_fin3 = clock();
	double secs3 = (double)(t_fin3 - t_ini3) / CLOCKS_PER_SEC;
	cout<<"tiempo  de eliminacion "<<secs3<<endl;
	cout<<"tiempo de eliminación promedio "<<secs3/a1.size()<<endl;
	//calcular la ram
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	cout<<"RAM: "<<physMemUsed<<" bits"<<endl;	
   	return 0;
   	
}
