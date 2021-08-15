#ifndef opengl_data_h
#define opengl_data_h
#include <stdbool.h>

/* Check glTF specification on Github page
 * "https://github.com/KhronosGroup/glTF/blob/master/specification/2.0/README.md"
 */


/* All objects, that specified in glTF.
 */
struct node;
struct accessor;
struct mesh;
struct buffer;
struct bufferView;


/* Enumirations.
 */
enum componentType {
	BYTE = 5120, UNSIGNED_BYTE,
	SHORT, UNSIGNED_SHORT,
	UNSIGNED_INT = 5125,
	FLOAT
};

enum sizeof_type {
	SCALAR = 1,
	VEC2, VEC3, VEC4,
	MAT2 = 4,
	MAT3 = 9,
	MAT4 = 16
};

/* Declarations.
*/

struct node {
	char *name;	// string

	int children_num;
	struct node *children;
	struct node *parent;

	/* Transformations.
		Only matrix or TRS can be used at the same time */
	bool transformation_is_matrix;
	union {
		float matrix[4*4];
		struct { float translation[3], rotation[4], scale[3]; };
	};
};

struct accessor {
	char *name;	// string
	struct bufferView *bufferView;
	int byteOffset;
	int count;
	enum componentType componentType;
	enum sizeof_type type;
};

struct buffer {
	int byteLength;
	char *uri;

	void *data;	// Can be freed after use.
};

struct bufferView {
	struct buffer *buffer;
	int byteLength;
	int byteOffset;
	int byteStride;
	int target;

	int buffer_id;	// OpenGL buffer name.
};

struct mesh {
	char *name;	// string

	int v_len;	// Overall size of verts
	void *data;
};


#endif /* opengl_data_h */
