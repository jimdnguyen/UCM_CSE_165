#include "Texture.h"

Texture::Texture(const char *imageLocation, GLenum textureType, GLenum slot)
{
    type = textureType;
    int width, height, nrChannels;
    //pick which image u want to load
    unsigned char *image = SOIL_load_image(imageLocation, &width, &height, &nrChannels, SOIL_LOAD_RGBA);
    //unsigned char *image = SOIL_load_image("texture/pressEnter.png", &width, &height, &nrChannels, SOIL_LOAD_RGBA);
    //std::cout << nrChannels << std::endl;
    glGenTextures(1, &id);
    glActiveTexture(slot);
    glBindTexture(textureType, id);

    glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);

    glTexImage2D(textureType, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(textureType);

    SOIL_free_image_data(image);
    glBindTexture(textureType, 0);
}

void Texture::bind()
{
    glBindTexture(type, id);
}

void Texture::unbind()
{
    glBindTexture(type, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &id);
}