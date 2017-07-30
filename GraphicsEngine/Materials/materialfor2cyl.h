#pragma once
#include "GraphicsEngine/Materials/Material.h"


// Unlit значит "неосвещаемый",
// т.е. этот материал не освещается источниками света
class Materialfor2Cyl : public Material
{
public:
    Materialfor2Cyl();

    virtual void Init(Object * pObject);
    virtual void Deinit();

    virtual void SetMaterial();
};
