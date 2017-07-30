#pragma once
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Camera.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/materialfor2.h"
#include "GraphicsEngine/Materials/materialfor2cyl.h"
#include "GraphicsEngine/Meshes/MeshCube.h"
#include "GraphicsEngine/Meshes/MeshCylinder.h"
#include "GraphicsEngine/Meshes/MeshTriangle.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/Transform.h"
#include "Tasks/Task.h"
#include "Tasks/ObjectRotator.h"


class Task02: public Task
{
public:
    virtual ~Task02() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Камера
        {
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0, 4, -10), Vector3(20.0f, 0.0f, 0.0f));
            Camera * pCamera = new Camera();
            //pCamera->SetFovY(90);
            pCamera->SetNearPlane(0.01f);
            pCamera->SetFarPlane(100);
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        //Object * pObj1 = NULL;
        {
            Object * pObject = new Object();
            pObject->m_pMesh		= new MeshCube(10);
            pObject->m_pTransform	= new Transform(-2, 0, 0, 0, 0, 1, 2, 2, 2);
            pObject->m_pMaterial	= new Materialfor2();
            scene.AddObject( pObject );

            //pObj1 = pObject;
        }

        {
            Object * pObject = new Object();
            pObject->m_pMesh		= new MeshCylinder(10);
            pObject->m_pTransform	= new Transform(2, 0, 0, 0, 0, 1, 2, 2, 2);
            pObject->m_pMaterial	= new Materialfor2Cyl();

            scene.AddObject( pObject );
        }


    }

    virtual void Update()
    {

    }
};
