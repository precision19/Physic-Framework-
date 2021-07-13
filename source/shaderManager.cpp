#include "shaderManager.h"
ShaderManager* ShaderManager::s_Instance = NULL;
ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

GLuint ShaderManager::LoadShader(GLenum shaderType, const char* pSource)
{
	GLuint shader = glCreateShader(shaderType);
	if (shader)
	{
		glShaderSource(shader, 1, &pSource, NULL);
		glCompileShader(shader);
		GLint compiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled)
		{
			GLint infoLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
			if (infoLen)
			{
				char* buf = (char*)malloc(infoLen);
				if (buf)
				{
					glGetShaderInfoLog(shader, infoLen, NULL, buf);
					LOGE("Could not compile shader %d:\n%s\n", shaderType, buf);
					free(buf);
				}
				glDeleteShader(shader);
				shader = 0;
			}
		}
	}
	return shader;
}

GLuint ShaderManager::CreateProgram(const char* pVertexSource, const char* pFragmentSource)
{
	GLuint vertexShader = ShaderManager::LoadShader(GL_VERTEX_SHADER, pVertexSource);
	if (!vertexShader)
	{
		return 0;
	}

	GLuint pixelShader = ShaderManager::LoadShader(GL_FRAGMENT_SHADER, pFragmentSource);
	if (!pixelShader)
	{
		return 0;
	}

	GLuint program = glCreateProgram();
	if (program)
	{
		glAttachShader(program, vertexShader);
		glAttachShader(program, pixelShader);

		glBindAttribLocation(program, ATT_POSITION, "a_Position");
		glBindAttribLocation(program, ATT_TEXCOORD, "a_Texcoord");
		glBindAttribLocation(program, ATT_COLOR, "a_Color");
		glBindAttribLocation(program, ATT_NORMAL, "a_Normal");

		glLinkProgram(program);
		GLint linkStatus = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
		if (linkStatus != GL_TRUE)
		{
			GLint bufLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
			if (bufLength)
			{
				char* buf = (char*)malloc(bufLength);
				if (buf)
				{
					glGetProgramInfoLog(program, bufLength, NULL, buf);
					LOGE("Could not link program:\n%s\n", buf);
					free(buf);
				}
			}
			glDeleteProgram(program);
			program = 0;
		}
	}
	if (!program)
	{
		LOGI("Could not create program.");
		exit(0);
	}
	return program;
}

ShaderManager* ShaderManager::GetInstance()
{
	if (!s_Instance)
		s_Instance = new ShaderManager();

	return s_Instance;
}