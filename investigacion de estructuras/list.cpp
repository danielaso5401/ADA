#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include "windows.h"
#include <sys/time.h>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
string GetSample(std::list<string>& s) {
  double r = rand() % s.size();
  std::list<string>::iterator it = s.begin();
  for (; r != 0; r--) it++;
  return *it;
}
int main() {
  
	list<string>a1;
	ifstream fe("english3.txt"); 
	clock_t t_ini, t_fin;
	ofstream file;
  	file.open("tiempo_list.txt");
  	
	while(!fe.eof()){
		string aux;
	    fe >>aux;
	    t_ini = clock();
	    a1.push_back(aux);
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
	for(int j=0; j<100; j++){
		auto n=find(a1.begin(), a1.end(), aleatorio[j]);
		//cout<<*n<<endl;
	}
	time(&end);
	double time_taken = double(end - start); 
    cout << "tiempo de busqueda " <<fixed <<time_taken << setprecision(5); 
	cout << " sec " << endl;
	cout << "tiempo de busqueda promedio " <<time_taken/a1.size() << setprecision(5); 
	cout << " sec " << endl;
	//eliminación
	time_t start2, end2;
	time(&start2);
	srand(time(0));
	for (auto it = a1.begin(); it != a1.end(); ) {
        for(int j=0; j<100; j++){
        	if(*it==aleatorio[j]){
        		it=a1.erase(it);
        		break;
			}
		}
		++it;
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
	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
	cout<<"RAM: "<<totalPhysMem<<" bits"<<endl;	
	return 0;
   	
}
