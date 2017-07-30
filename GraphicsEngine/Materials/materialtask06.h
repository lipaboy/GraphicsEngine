#pragma once
#include "GraphicsEngine/Materials/Material.h"
#include "GraphicsEngine/Texture2D.h"


class MaterialTask06 : public Material
{
public:
    MaterialTask06(TextureFilterMode filterMode);

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();

private:
    Texture2D *	m_pTexture1;
    Texture2D *	m_pTexture2;
    TextureFilterMode m_filterMode;
};
