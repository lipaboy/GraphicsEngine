#include "materialtask05_3.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialTask05_3::MaterialTask05_3(TextureFilterMode filterMode)
{
    m_vsFileName = "ShaderTask05_3";
    m_psFileName = "ShaderTask05_3";

    m_pTexture1 = NULL;
    m_filterMode = filterMode;
}

void MaterialTask05_3::Init(Object * pObject)
{
    Material::Init(pObject);

    m_pTexture1 = new Texture2D("Earth_Albedo.jpg");

    m_pTexture1->SetFilterMode(m_filterMode);
}

void MaterialTask05_3::Deinit()
{
    delete m_pTexture1;
    m_pTexture1 = NULL;

    Material::Deinit();
}

void MaterialTask05_3::SetMaterial()
{
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();

    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", matWorldViewProjT);
        SetVertexShaderVector4("constColor", Vector4(1, 1, 1, 1));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderTexture2d("texture1", m_pTexture1);
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
