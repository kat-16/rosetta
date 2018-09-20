/*===============================================================*/
/*                                                               */
/*                          kernel.h                             */
/*                                                               */
/*        Defines types and constants for host function          */
/*                                                               */
/*===============================================================*/

#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__
//#include "ap_fixed.h"
const int MAX_HEIGHT = 436;
const int MAX_WIDTH = 1024;

#define SDSOC

// basic typedefs
#ifdef SDSOC
	#include "ap_fixed.h"
	typedef ap_fixed<32,12> pixel_t;
	//typedef float pixel_t;
#endif
#ifdef OCL
	#include "ap_fixed.h"
	typedef ap_fixed<48,40> pixel_t;
#endif
#ifdef SW
	typedef float pixel_t;
#endif
typedef struct{
    pixel_t x;
    pixel_t y;
    pixel_t z;
}gradient_t;

typedef struct{
    pixel_t val[6];
}outer_t; 

typedef struct{
    pixel_t val[6];
}tensor_t;

typedef struct{
    pixel_t x;
    pixel_t y;
}velocity_t;

#ifndef SW
  #include "ap_int.h"
  // for data packing
  typedef ap_uint<64> frames_t;
#endif

#ifdef OCL
  #include <string>
  // change the target device here
  const std::string TARGET_DEVICE = "xilinx:aws-vu9p-f1:4ddr-xpr-2pr:4.0";
#endif

#endif
