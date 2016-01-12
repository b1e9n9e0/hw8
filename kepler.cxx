#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
//---------------------------------------
using namespace std;

void step(double* pq, double dt){

	double temp = sqrt(pq[2]*pq[2]+pq[3]*pq[3]);

	for(int i = 0 ; i < 2 ; i++){
		pq[i] -= dt*pq[i+2]/(temp*temp*temp);
		pq[i+2] += dt*pq[i];
	}
}

int main(){

	//data
	const double dt1 = 0.05;
	const double dt2 = 0.0005;
	const double e = 0.6;
	const double tEnd = 20.0 * M_PI;	

	//Variables
	double H;
	double pq[4];
	double t = 0.0;
	//functions
	H = 0;
	//Calling Functions

	pq[0] = 0.0;
	pq[1] = sqrt((1.0+e)/(1.0-e));
	pq[2] = 1.0-e;
	pq[3] = 0.0;

	ofstream out("data1");

	while(t<tEnd){
		H = 0.5*(pq[0]*pq[0] + pq[1]*pq[1]) - 1.0/sqrt(pq[2]*pq[2] + pq[3]*pq[3]);

		out << t << "\t" << H << "\t" <<  pq[0] << "\t" << pq[1] << "\t" << pq[2] << "\t" << pq[3] << endl;
		
		step(pq,dt1);
		

		t+=dt1;
	}

	out.close();
	ofstream out2("data2");

	t = 0.0;
	pq[0] = 0.0;
	pq[1] = sqrt((1.0+e)/(1.0-e));
	pq[2] = 1.0-e;
	pq[3] = 0.0;


	while(t<tEnd){
		H = 0.5*(pq[0]*pq[0] + pq[1]*pq[1]) - 1.0/sqrt(pq[2]*pq[2] + pq[3]*pq[3
			]);

		out2 << t << "\t" << H << "\t" <<  pq[0] << "\t" << pq[1] << "\t" << pq[2] << "\t" << pq[3] << endl;
		
		step(pq,dt2);
		

		t+=dt2;
	}

	out2.close();

	return 0;
}