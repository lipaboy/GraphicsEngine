#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "GraphicsEngine/Texture2D.h"


class MaterialTask05_2 : public Material
{
public:
    MaterialTask05_2(TextureFilterMode filterMode);

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();

private:
    Texture2D *	m_pTexture1;
    Texture2D *	m_pTexture2;
    Texture2D *	m_pTexture3;
    TextureFilterMode m_filterMode;
};
