/* Check glTF specification on Github page
 * "https://github.com/KhronosGroup/glTF/blob/master/specification/2.0/README.md"
 */

#ifndef gltf_h
#define gltf_h

#include <stddef.h>		// POSIX.1-2008, needed for standard NULL


/* Enums.
 */
enum component_type {
	BYTE		= 5120,
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	UNSIGNED_INT	= 5125,
	FLOAT
};

enum accessor_type {
	SCALAR	= 1,
	VEC2,
	VEC3,
	VEC4,
	MAT2	= 4,
	MAT3	= 9,
	MAT4	= 16
};

enum primitive_mode {
	POINTS	= 0,
	LINES,
	LINE_LOOP,
	LINE_STRIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN
};

enum bufferView_target {
	ARRAY_BUFFER	= 34962,
	ELEMENT_ARRAY_BUFFER
};

enum sampler_interpolation {
	LINEAR	= 0,		// Default
	STEP,
	CUBICSPLINE
};

/* glTF objects */
struct glTF_root;
struct accessor;
struct animation;	//
struct buffer;
struct bufferView;
struct camera;	//
struct image;	//
struct material;	//
struct mesh;
struct node;
struct sampler;	//
struct skin;	//
struct texture;	//
// These are accessible only inside they parent objects.
struct attribute;
struct channel;
struct primitive;

struct glTF_root {
	// ptr[.ptr_count]->object
	struct accessor **accessors;
	struct animation **animations;
	struct buffer **buffers;
	struct bufferView **bufferViews;
	struct camera **cameras;
	struct image **images;
	struct material **materials;
	struct mesh **meshes;
	struct node **nodes;
	struct sampler **samplers;
	struct skin **skins;
	struct texture **textures;

	size_t accessors_count,
	       animations_count,
	       buffers_count,
	       bufferViews_count,
	       cameras_count,
	       images_count,
	       materials_count,
	       meshes_count,
	       nodes_count,
	       samplers_count,
	       skins_count,
	       textures_count;
};

struct accessor {
	char *name;			// string
	struct bufferView *bufferView;
	int byteOffset;
	int count;
	float *min, *max;		// float[.type]
	enum component_type componentType;
	enum accessor_type type;
};

struct animation {
	char *name;			// string
};

struct buffer {
	int byteLength;
	char *uri;			// string

	void *data;			// Can be freed after use.
};

struct bufferView {
	struct buffer *buffer;
	int byteLength;
	int byteOffset;
	int byteStride;
	enum bufferView_target target;	// OpenGL buffer type.

	int buffer_id;			// OpenGL buffer name.
};

struct camera {};

struct image {};

struct material {};

struct mesh {
	char *name;			// string
	struct primitive **primitives;	// ptr[.ptr_count]->object
		size_t primitives_count;
	float *weights;			// float[.count]
		size_t weights_count;
};

struct node {
	char *name;			// string
	struct node **children;		// ptr[.ptr_count]->object
		size_t children_count;
	struct node *parent;		// This is not in glTF standart
	struct mesh *mesh;
	float matrix[4*4];
		// TODO: maybe do iteration instead just yes/no
		int matrix_ready;
	float translation[3],
	      rotation[4],
	      scale[3];
	float *weights;			// float[.mesh->float_count]
};

struct sampler {};

struct skin {};

struct texture {};

/* Some internal objects that don't appear in glTF_root */

// Meshes
struct primitive {
	struct attribute attributes;
	struct accessor *indices;
	struct material *material;
	enum primitive_mode mode;
	struct attribute *targets;	// count in 'parent_mesh->weights_count'
		int targets_enabled;
};

// Mesh.primitives, dictionary type object
struct attribute {
	struct accessor
		*POSITION,
		*NORMAL,
		*TANGENT,
		*TEXCOORD_0,
		*TEXCOORD_1,
		*COLOR_0,
		*JOINTS_0,
		*WEIGHTS_0;
};

// Animations
struct channel {
	struct sampler
};

// Animations
struct sampler {
	struct accessor *input, *output;
	enum sampler_interpolation interpolation;
};


#endif /* gltf_h */
