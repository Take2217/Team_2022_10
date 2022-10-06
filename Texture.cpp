#include "Texture.h"

Texture::Texture(int width,int height)
: width(width),height(height),handle(-1)
{
}

void Texture::SetHandle(int _handle){
    handle = _handle;
}