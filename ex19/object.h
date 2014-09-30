//If the _object_h is already defined
//Begin if block
#ifndef _object_h
// And define it
#define _object_h

//Create an Object struct
typedef struct {
	char *description;
	//Function pointer
	int (*init)(void *self);
	void (*describe)(void *self);
	void (*destroy)(void *self);
	void *(*move)(void *self, Direction direction);
	int (*attack)(void *self, int damage);
} Object;

int Object_init()void *self;
void Object_destroy(void *self);
void Object_describe(void *self);
void Object_move(*void *self, int damage);
void *Object_new(size_t size, Object_proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif // End if block
