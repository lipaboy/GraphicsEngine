#include "MaterialTask05_2.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"


MaterialTask05_2::MaterialTask05_2(TextureFilterMode filterMode)
{
    m_vsFileName = "ShaderTask05_2";
    m_psFileName = "ShaderTask05_2";

    m_pTexture1 = NULL;
    m_pTexture2 = NULL;
    m_pTexture3 = NULL;
    m_filterMode = filterMode;
}

void MaterialTask05_2::Init(Object * pObject)
{
    Material::Init(pObject);

    m_pTexture1 = new Texture2D("road_1.jpg");
    m_pTexture2 = new Texture2D("road_2.jpg");
    m_pTexture3 = new Texture2D("road_3.jpg");

    m_pTexture1->SetFilterMode(m_filterMode);
}

void MaterialTask05_2::Deinit()
{
    delete m_pTexture1;
    m_pTexture1 = NULL;

    Material::Deinit();
}

void MaterialTask05_2::SetMaterial()
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
        SetPixelShaderTexture2d("texture2", m_pTexture2);
        SetPixelShaderTexture2d("texture3", m_pTexture3);
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
