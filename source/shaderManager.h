#ifndef __SHADER_H__
#define __SHADER_H__

#include <openGLESv2.h>
#include <stdio.h>
#include <stdlib.h>
#include <log.h>
#include <define.h>

enum Attribute
{
	ATT_POSITION,
	ATT_NORMAL,
	ATT_COLOR,
	ATT_TEXCOORD
};

class ShaderManager
{
private:
	static ShaderManager* s_Instance;
public:
	ShaderManager();
	virtual ~ShaderManager();
	GLuint LoadShader(GLenum shaderType, const char* pSource);
	GLuint CreateProgram(const char* pVertexSource, const char* pFragmentSource);
	static ShaderManager* GetInstance();
};

#endif