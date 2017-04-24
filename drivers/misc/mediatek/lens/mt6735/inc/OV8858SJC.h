#ifndef _OV8858SJC_H
#define _OV8858SJC_H

#include <linux/ioctl.h>
/* #include "kd_imgsensor.h" */

#define OV8858SJC_MAGIC 'A'
/* IOCTRL(inode * ,file * ,cmd ,arg ) */


/* Structures */
typedef struct {
/* current position */
	u32 u4CurrentPosition;
/* macro position */
	u32 u4MacroPosition;
/* Infiniti position */
	u32 u4InfPosition;
/* Motor Status */
	bool bIsMotorMoving;
/* Motor Open? */
	bool bIsMotorOpen;
/* Support SR? */
	bool bIsSupportSR;
} stOV8858SJC_MotorInfo;


/* Structures */
/* #define LensdrvCM3 */
#ifdef LensdrvCM3
typedef struct {
	/* APERTURE , won't be supported on most devices. */
	float Aperture;
	/* FILTER_DENSITY, won't be supported on most devices. */
	float FilterDensity;
	/* FOCAL_LENGTH, lens optical zoom setting. won't be supported on most devices. */
	float FocalLength;
	/* FOCAL_DISTANCE, current focus distance, lens to objects. */
	float FocalDistance;
	/* OPTICAL_STABILIZATION_MODE */
	u16 u4OIS_Mode;
	/* FACING */
	u16 Facing;
	/* Optical axis angle,  optical axis is perpendicular to LCM, usually is  {0,0}. */
	float OpticalAxisAng[2];
	/* Optical axis position (mm),  usually is  {0,0,0}. */
	float Position[3];
	/* Focus range, DOF, */
	float FocusRange;
	/* State */
	u16 State;
	/* INFO */
	float InfoAvalibleMinFocusDistance;
	float InfoAvalibleApertures;
	float InfoAvalibleFilterDensity;
	u16 InfoAvalibleOptStabilization;
	float InfoAvalibleFocalLength;
	float InfoAvalibleHypeDistance;
} stOV8858SJC_MotorMETAInfo;
#endif

/* Control commnad */
/* S means "set through a ptr" */
/* T means "tell by a arg value" */
/* G means "get by a ptr" */
/* Q means "get by return a value" */
/* X means "switch G and S atomically" */
/* H means "switch T and Q atomically" */
#define OV8858SJCIOC_G_MOTORINFO _IOR(OV8858SJC_MAGIC, 0, stOV8858SJC_MotorInfo)

#define OV8858SJCIOC_T_MOVETO _IOW(OV8858SJC_MAGIC, 1, u32)

#define OV8858SJCIOC_T_SETINFPOS _IOW(OV8858SJC_MAGIC, 2, u32)

#define OV8858SJCIOC_T_SETMACROPOS _IOW(OV8858SJC_MAGIC, 3, u32)
#ifdef LensdrvCM3
#define OV8858SJCIOC_G_MOTORMETAINFO _IOR(OV8858SJC_MAGIC, 4, stOV8858SJC_MotorMETAInfo)
#endif

#else
#endif