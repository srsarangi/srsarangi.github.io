typedef struct {
	char op;
	int level;
} oplevel_t;

typedef union {
	oplevel_t oplevel;	 
	int num;
} opnum;

#define DTYPE opnum
