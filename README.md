# Cerebrum

Fast and flexible Deep Learning platform written in C++

The platform is under **intensive** development. Version 0.1 is scheduled for
Thursday, 23rd of April. Stay tuned!

## Using BLAS

Cerebrum can use BLAS to speed up computation. BLAS is not a mandatory
dependency, but we recommend you to use it.

You can use any CBLAS implementation, (e.g.
 [ATLAS](http://math-atlas.sourceforge.net/),
 [OpenBLAS](www.openblas.net)), but you have to let the compiler know about
the specific flags and the location of the libraries to be linked.

### Compiling with BLAS

You have two options to send the compiler the flags needed in order to use
BLAS.

#### Using configuration files

1.  Create a file named `cblas.cflags` with the needed pre-processor, an