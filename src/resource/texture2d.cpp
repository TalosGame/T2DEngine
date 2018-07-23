#include "texture2d.h"
#include <GLES3/gl3.h>
#include <string>
#include <string.h>
#include "utility/log/xlog.h"

Texture2D::Texture2D() {

}

Texture2D::~Texture2D(){

}

bool Texture2D::LoadData(const uint8 *data, uint32 width, uint32 height, GLsizei size){
	glGenTextures(1, &texture_id_);
	glBindTexture(GL_TEXTURE_2D, this->texture_id_);

	this->width_ = width;
	this->height_ = height;

// 	const char * extensions = (const char*)glGetString(GL_EXTENSIONS);
// 	printf("%s", extensions);
// 	bool support = (strstr(extensions, "GL_COMPRESSED_RGBA8_ETC2_EAC") ? true : false);

	glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_RGBA8_ETC2_EAC, this->width_, this->height_, 0, size, data);
	GLenum glError = glGetError();
	if (glError != GL_NO_ERROR) {
		log_error("glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__);
		return false;
	}

	// Set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);
	return true;
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
