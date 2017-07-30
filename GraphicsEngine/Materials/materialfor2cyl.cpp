#include "materialfor2cyl.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/MathUtils.h"
#include "GraphicsEngine/SceneUtils.h"
#include "GraphicsEngine/Time.h"

Materialfor2Cyl::Materialfor2Cyl()
{
    m_vsFileName = "Shaderfor2Cyl";
    m_psFileName = "Shaderfor2Cyl";
}

// TODO: Реализовать переключение Graphics API при нажатии на кнопки (1 - DirectX 11, 2 - OpenGL 2.0, 9 - DirectX 9)
// и отладить на этом механизм использования функций Init() и Deinit()
void Materialfor2Cyl::Init(Object * pObject)
{
    Material::Init(pObject);

    // TODO: Нужно при компиляции скопировать папку с шейдерами
    // Google it: "visual studio during build copy files into application folder"
}

void Materialfor2Cyl::Deinit()
{
    Material::Deinit();
}

void Materialfor2Cyl::SetMaterial()
{
//       std::cout << "ALLO " << std::endl ;
    // Заполняем матрицы World, View, Proj
    const Matrix4x4 & matWorld	= SceneUtils::GetMatrixWorld(m_pObject);
    const Matrix4x4 & matView	= SceneUtils::GetMatrixView();
    const Matrix4x4 & matProj	= SceneUtils::GetMatrixProj();


    const Matrix4x4 matWorldViewProjT = MathUtils::GetMatrixWorldViewProjT(matWorld, matView, matProj);

     double t = 90 * sin(10 * Time::GetTime());

//    std::cout << t << std::endl;

    SetMaterialBegin();
    {
        SetVertexShaderBegin();
        SetVertexShaderMatrix4x4("matrixWorldViewProjT", (matWorldViewProjT * Matrix4x4::RotationY(t)));
        SetVertexShaderMatrix4x4("matrixWorldViewProjT2", (matWorldViewProjT * Matrix4x4::RotationY(-t)));
        //SetVertexShaderVector4("timeVector", Vector4(t, 1, 1, 1));
        SetVertexShaderEnd();

        SetPixelShaderBegin();
        SetPixelShaderEnd();
    }
    SetMaterialEnd();
}
