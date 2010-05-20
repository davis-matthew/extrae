/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                  MPItrace                                 *
 *              Instrumentation package for parallel applications            *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- *\
 | @file: $HeadURL$
 | @last_commit: $Date$
 | @version:     $Revision$
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef MPI_INTERFACE_H_INCLUDED
#define MPI_INTERFACE_H_INCLUDED

#include <config.h>

/**** Create synonims of the very same routine using replication of code! ****/

#if !defined(IS_CELL_MACHINE)
# define EXPAND_ROUTINE_WITH_PREFIXES(x) \
   x(OMPI); \
   x(MPI); \
   x(OMP); \
   x(SEQ);
# define EXPAND_F_ROUTINE_WITH_PREFIXES(x) \
   x(ompi); \
   x(mpi); \
   x(omp); \
   x(seq);
#else
# define EXPAND_ROUTINE_WITH_PREFIXES(x) \
   x(OMPI); \
   x(MPI); \
   x(OMP); \
   x(SEQ); \
   x(PPU);
# define EXPAND_F_ROUTINE_WITH_PREFIXES(x) \
   x(ompi); \
   x(mpi); \
   x(omp); \
   x(seq); \
   x(ppu);
#endif

/**** Create synonims of the very same routine using 'alias' of the same routine (preferred) ****/

#if !defined(IS_CELL_MACHINE)
# define INTERFACE_ALIASES_C(base,orig,params) \
  void OMP##base params  __attribute__ ((alias (#orig))); \
  void OMPI##base params __attribute__ ((alias (#orig))); \
	void SEQ##base params  __attribute__ ((alias (#orig)));
#else
# define INTERFACE_ALIASES_C(base,orig,params) \
  void OMP##base params  __attribute__ ((alias (#orig))); \
  void OMPI##base params __attribute__ ((alias (#orig))); \
	void SEQ##base params  __attribute__ ((alias (#orig))); \
	void PPU##base params  __attribute__ ((alias (#orig))); 
#endif

#if !defined(IS_CELL_MACHINE)
# define INTERFACE_ALIASES_F(base_lo,base_up,orig,params) \
  void mpi##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo##__ params __attribute__ ((alias (#orig))); \
  void seq##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void mpi##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo##_ params __attribute__ ((alias (#orig))); \
  void seq##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo params __attribute__ ((alias (#orig))); \
  void seq##base_lo params  __attribute__ ((alias (#orig))); \
  void MPI##base_up params  __attribute__ ((alias (#orig))); \
  void OMP##base_up params  __attribute__ ((alias (#orig))); \
  void OMPI##base_up params __attribute__ ((alias (#orig))); \
  void SEQ##base_up params  __attribute__ ((alias (#orig)));
#else
# define INTERFACE_ALIASES_F(base_lo,base_up,orig,params) \
  void mpi##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo##__ params __attribute__ ((alias (#orig))); \
  void seq##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void ppu##base_lo##__ params  __attribute__ ((alias (#orig))); \
  void mpi##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo##_ params __attribute__ ((alias (#orig))); \
  void seq##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void ppu##base_lo##_ params  __attribute__ ((alias (#orig))); \
  void omp##base_lo params  __attribute__ ((alias (#orig))); \
  void ompi##base_lo params __attribute__ ((alias (#orig))); \
  void seq##base_lo params  __attribute__ ((alias (#orig))); \
  void ppu##base_lo params  __attribute__ ((alias (#orig))); \
  void MPI##base_up params  __attribute__ ((alias (#orig))); \
  void OMP##base_up params  __attribute__ ((alias (#orig))); \
  void OMPI##base_up params __attribute__ ((alias (#orig))); \
  void SEQ##base_up params  __attribute__ ((alias (#orig))); \
  void PPU##base_up params  __attribute__ ((alias (#orig)));
#endif

#endif /* MPI_INTERFACE_H_INCLUDED */
