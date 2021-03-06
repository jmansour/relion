#include "src/local_symmetry_mpi.h"

int main(int argc, char *argv[])
{
	local_symmetry_parameters_mpi prm;

	try
    {
		prm.read(argc, argv);

		prm.run();
    }

    catch (RelionError XE)
    {
    	if (prm.verb > 0)
    		prm.usage();
        std::cerr << XE;
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    return 0;

}
