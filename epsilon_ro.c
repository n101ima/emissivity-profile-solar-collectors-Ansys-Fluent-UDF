#include "udf.h"

DEFINE_PROFILE(emissivity_profile, t, i)
{
	// get the domain pointer
	Domain* d = Get_Domain(1); // mixture domain if multiphase

	// get the boundary thread pointer
	Thread* t_b = Lookup_Thread(d, 6); // replace number with the actual zone ID

	// declare face and thread variables
	face_t f;

	// declare variables for emissivity and wall temperature
	real emissivity, t_wall;

	// loop over all faces in the boundary thread
	begin_f_loop(f, t_b)
	{
		// get the wall temperature using F_T macro
		t_wall = F_T(f, t_b);

		// calculate the emissivity using a function of wall temperature
		// replace this with your actual function
		emissivity = 0.062 + 2e-7 * pow(t_wall - 273.15, 2);

		// set the emissivity using F_PROFILE macro
		F_PROFILE(f, t_b, i) = emissivity;
	}
	end_f_loop(f, t_b)
}