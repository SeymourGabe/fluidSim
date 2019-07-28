#ifndef FLUID_H
#define FLUID_H

typedef struct FluidCube {

// VARIABLES
	int size;
	float dt;
	float diff;
	float visc;

	float *s;
	float *density;

	float *Vx;
	float *Vy;
	float *Vz;

	float *Vx0;
	float *Vy0;
	float *Vz0;

// FUNCTIONS
	void AddDensity(int x, int y, int z, float amount);
	void AddVelocity(int x, int y, int z, float amountX, float amountY, float amountZ);



// CONSTRUCTOR AND DESTRUCTOR
	FluidCube(int size, int diffusion, int viscosity, float dt);
	~FluidCube();

} FluidCube;


#endif
