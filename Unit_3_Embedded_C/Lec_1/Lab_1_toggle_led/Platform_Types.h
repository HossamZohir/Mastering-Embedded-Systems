/*
 * Platform_Types.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Hossam
 *
 *    It is required that all platform types files are unique within the AUTOSAR community
	  to guarantee unique types per platform and to avoid type changes when moving a
	  software module from platform A to B.
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE_8 						8
#define CPU_TYPE_16 					16
#define CPU_TYPE_32 					32
#define CPU_TYPE_64 					64
#define MSB_FIRST 						0
#define LSB_FIRST 						1
#define HIGH_BYTE_FIRST	 				0
#define LOW_BYTE_FIRST 					1

#define CPU_TYPE 						CPU_TYPE_16
#define CPU_BIT_ORDER 					LSB_FIRST
#define CPU_BYTE_ORDER 					LOW_BYTE_FIRST

#define TRUE							(uint8)0x01
#define FALSE							(uint8)0x00
#define NULLPTR							((void*)0)

/* data type */
typedef signed char 					sint8;
typedef signed short 					sint16;
typedef signed long 					sint32;
typedef signed long long 				sint64;
typedef signed short 					sint8_least;
typedef signed short 					sint16_least;
typedef signed long 					sint32_least;

typedef unsigned char 					boolean;

typedef unsigned char 					uint8;
typedef unsigned short 					uint16;
typedef unsigned long 					uint32;
typedef unsigned long long 				uint64;
typedef unsigned short 					uint8_least;
typedef unsigned short 					uint16_least;
typedef unsigned long 					uint32_least;

typedef float 							float32;
typedef double 							float64;

/* volatile data type */
typedef volatile signed char 					vsint8_t;
typedef volatile signed short 					vsint16_t;
typedef volatile signed long 					vsint32_t;
typedef volatile signed long long 				vsint64_t;
typedef volatile signed short 					vsint8_least_t;
typedef volatile signed short 					vsint16_least_t;
typedef volatile signed long 					vsint32_least_t;

typedef volatile unsigned char 					vboolean_t;

typedef volatile unsigned char 					vuint8_t;
typedef volatile unsigned short 				vuint16_t;
typedef volatile unsigned long 					vuint32_t;
typedef volatile unsigned long long 			vuint64_t;
typedef volatile unsigned short 				vuint8_least_t;
typedef volatile unsigned short 				vuint16_least_t;
typedef volatile unsigned long 					vuint32_least_t;

typedef volatile float 							vfloat32_t;
typedef volatile double 						vfloat64_t;

#endif /* PLATFORM_TYPES_H_ */
