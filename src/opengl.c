#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include "opengl.h"


#define opengl_memory_max (128 * 1024 * 1024)	// 128 MB of video-RAM


static struct {
	GLuint vertex;
	GLuint index;
} buffers;

static struct {
	GLuint position;
	GLuint color;
} vertattr = {0,1};


/* opengl extern calls.
 * 	opengl_init()
 * 	opengl_draw()	*/

int opengl_init(void)
{
	// Non-graphics checkcode
	if (glewInit() != GLEW_OK)
		return (-1);

	// Oneshot graphics preparation
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate and bind buffers
	glGenBuffers(1, &buffers.vertex);
	glBindBuffer(GL_ARRAY_BUFFER, buffers.vertex);
	glEnableVertexAttribArray(vertattr.position);
	glVertexAttribPointer(vertattr.position, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	glGenBuffers(1, &buffers.index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.index);

	// Upload data to buffers
	GLfloat verts[] =
	{
		+0.0, +0.0,
		+0.9, +0.9,
		+0.0, +0.9
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	GLushort indices[] =
	{
		0,1,2
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	return 0;
}

int opengl_draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, NULL);

	return 0;
}
