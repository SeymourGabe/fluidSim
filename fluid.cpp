#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

#include "fluid.hpp"
#define IX(x, y, z) ((x) + (y) * N + (z) * N * N)
using namespace std;

void FluidCube::AddDensity(int x, int y, int z, float amount) {

	int N = this->size;
	this->density[IX(x, y, z)] += amount;
}

void FluidCube::AddVelocity(int x, int y, int z, float amountX, float amountY, float amountZ) {

	int N = this->size;
	int index = IX(x, y, z);

	this->Vx[index] += amountX;
	this->Vy[index] += amountY;
	this->Vz[index] += amountZ;

}


FluidCube::FluidCube(int size, int diffusion, int viscosity, float dt) {

	int N = size;

	this->size = size;
        this->dt = dt;
        this->diff = diffusion;
        this->visc = viscosity;

        this->s = (float*)calloc(N * N * N, sizeof(float));
        this->density = (float*)calloc(N * N * N, sizeof(float));

        this->Vx = (float*)calloc(N * N * N, sizeof(float));
        this->Vy = (float*)calloc(N * N * N, sizeof(float));
        this->Vz = (float*)calloc(N * N * N, sizeof(float));

        this->Vx0 = (float*)calloc(N * N * N, sizeof(float));
        this->Vy0 = (float*)calloc(N * N * N, sizeof(float));
        this->Vz0 = (float*)calloc(N * N * N, sizeof(float));
	cout << "FluidCube constructor used and finished.\n" << endl;

}

FluidCube::~FluidCube() {

	free(this->s);
	free(this->density);

	free(this->Vx);
        free(this->Vy);
        free(this->Vz);

        free(this->Vx0);
        free(this->Vy0);
        free(this->Vz0);

	
}

