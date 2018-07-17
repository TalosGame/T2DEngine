#include "texture2d.h"
#include <GLES3/gl3.h>
#include <string>
#include <string.h>
#include "common/xlog.h"

Texture2D::Texture2D() {

}

Texture2D::~Texture2D(){

}

ubool Texture2D::LoadData(const uint8 *data, uint32 width, uint32 height, GLsizei size1){
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &id_);
	glBindTexture(GL_TEXTURE_2D, this->id_);

	this->width_ = width;
	this->height_ = height;

	int bw = (int)ceil(width / 4);
	int	bh = (int)ceil(height / 4);

	bw = (this->width_ + 3) / 4;
	bh = (this->height_ + 3) / 4;
	//GLsizei size = bw * bh * 16;

	GLsizei size = bw * bh * 16;

// 	const char * extensions = (const char*)glGetString(GL_EXTENSIONS);
// 	printf("%s", extensions);
// 	bool support = (strstr(extensions, "GL_COMPRESSED_RGBA8_ETC2_EAC") ? true : false);

	GL_CHECK(glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA8_ETC2_EAC, this->width_, this->height_, 0, size, data));
// 	GLenum err = glGetError();
// 	if (err != GL_NO_ERROR)
// 	{
// 		log_error("Texture2D: Error uploading compressed texture glError");
// 		return FALSE;
// 	}

	// Set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);
	return TRUE;
}

uint32 Texture2D::Id(){
	return -1;
}

/*
void Texture2D::LoadData(const uint8 *data, ETC2HeaderPtr header){
	
    this->width_ = header->m_u32PixelWidth;
    this->height_ = header->m_u32PixelHeight;

	glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, this->id_);

    int bw = (this->width_+ 3) / 4, bh = (this->height_ + 3) / 4;
    GLsizei size = bw * bh * 16;

    //qDebug() << data[1];
    //qDebug() << data[size - 1];

	glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA8_ETC2_EAC, this->width_, this->height_, 0, size, data);

    GLenum err = glGetError();
    if (err != GL_NO_ERROR)
    {
       // qDebug() <<"Texture2D: Error uploading compressed texture glError:" << err;
        return;
    }

    // Set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);
}
*/
