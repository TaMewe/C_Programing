#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct elem_s {
	int *pos;
	int room;

	struct elem_s *next; 
} elem_t;

#endif
