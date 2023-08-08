# emissivity-profile-solar-collectors-Ansys-Fluent-UDF
This UDF defines a function that assigns an emissivity profile to a wall zone in Fluent. The UDF is related to the solar collectors, which are devices that capture and convert solar energy into heat or electricity. The UDF uses the following parameters and variables:

•  emissivity_profile: the name of the user-defined function that takes two arguments: t and i.

•  t: a pointer to the thread structure of the wall zone where the emissivity profile is applied.

•  i: an index that represents the variable ID of the emissivity.

•  d: a pointer to the domain structure of the mixture domain if multiphase.

•  t_b: a pointer to the boundary thread structure of the wall zone with a specific zone ID.

•  f: a variable that represents a face in the face loop.

•  emissivity: a scalar that represents the emissivity of the wall at the face f. It is a dimensionless parameter that measures how much a surface emits thermal radiation compared to a black body. It ranges from 0 to 1, where 0 means no emission and 1 means perfect emission.

•  t_wall: a scalar that represents the wall temperature at the face f. It has units of K.

•  Get_Domain: a macro that returns the domain pointer for a given domain ID.

•  Lookup_Thread: a macro that returns the thread pointer for a given domain pointer and zone ID.

•  F_T: a macro that returns the wall temperature at the face f and thread t_b.

•  F_PROFILE: a macro that sets the value of the emissivity at the face f and thread t_b to emissivity.

The UDF performs the following steps:


It defines some constants and variables for the simulation.
It gets the domain pointer for the mixture domain using Get_Domain and stores it in d.
It gets the boundary thread pointer for the wall zone with a specific zone ID using Lookup_Thread and stores it in t_b.
It begins a face loop over all faces in the boundary thread t_b.
It calculates
the wall temperature at
the face f using F_T and stores it in t_wall.
It calculates
the emissivity at
the face f using a function of t_wall and stores it in emissivity. The function is given by $$emissivity = \begin{cases} 0.062 + 2e-7 (t_{wall} - 273.15)^2 & \text{if } t_{wall} \leq 698.15 \ 0 & \text{otherwise} \end{cases}$$ where $t_{wall}$ is
the wall temperature
in K.
It sets
the value of
the emissivity at
the face f using F_PROFILE and assigns it to emissivity.
It ends
the face loop.

The UDF can be used to model heat transfer problems with solar collectors, such as solar water heating, solar desalination, or solar cooling systems.
