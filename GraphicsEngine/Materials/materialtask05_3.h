#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "GraphicsEngine/Texture2D.h"


class MaterialTask05_3 : public Material
{
public:
    MaterialTask05_3(TextureFilterMode filterMode);

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();

private:
    Texture2D *	m_pTexture1;
    TextureFilterMode m_filterMode;
};
