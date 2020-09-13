#include <iostream>
#include <fstream>
#include <set>
#include "windows.h"
#include <sys/time.h>
#include <ctime>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

string GetSample(const std::set<string>& s) {
  double r = rand() % s.size();
  std::set<string>::iterator it = s.begin();
  for (; r != 0; r--) it++;
  return *it;
}

int main() {
  
	set<string>a1;
	ifstream fe("english3.txt"); 
	clock_t t_ini, t_fin;
  	ofstream file;
  	file.open("tiempo_set.txt");
	while(!fe.eof()){
		string aux;
		fe >>aux;
		t_ini = clock();
	    a1.insert(aux);
	    t_fin = clock();
	    double secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
		file<<secs<<endl;
	}
	fe.close();



 	string aleatorio[100];
 	for(int i=0; i<100; i++){
		aleatorio[i]=GetSample(a1);
	}
	//busqueda
	time_t start, end;
	time(&start);
	for(int i=0; i<100; i++){
		
		auto search=a1.find(aleatorio[i]);
		//cout<<i<<" "<<*search<<endl;

	}

	time(&end);
	double time_taken = double(end - start); 
    cout << "tiempo de busqueda " <<fixed <<time_taken << setprecision(5); 
	cout << " sec " << endl;cout << "tiempo de busqueda promedio " <<time_taken/a1.size() << setprecision(5); 
	cout << " sec " << endl;
	//eliminación
	time_t start2, end2;
	time(&start2);
	srand(time(0));
	for(int i=0; i<100; i++){
		auto search=a1.erase(aleatorio[i]);	
	}
	
	time(&end2);
	double time_taken2 = double(end2 - start2); 
    cout << "tiempo de eliminacion " <<fixed <<time_taken2 << setprecision(5); 
	cout << " sec " << endl;
	cout << "tiempo de eliminacion promedio " <<time_taken2/a1.size() << setprecision(5); 
	cout << " sec " << endl;
	//calcular la ram
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	cout<<"RAM: "<<physMemUsed<<" bits"<<endl;
   	return 0;
   	
}

