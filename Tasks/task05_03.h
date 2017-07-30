#pragma once
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/materialtask05_3.h"
#include "GraphicsEngine/Light.h"


class Task05_03: public Task
{
public:
    virtual ~Task05_03() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Camera
        {
            Object * pCameraObj = new Object();
            Camera * pCamera = new Camera();
            pCameraObj->m_pTransform = new Transform( Vector3(0.0f, 0.0f, -7.0f), Vector3(0.0f, 0.0f, 0.0f) );
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        // Object #1 - Plane with sand texture (Point filter)
        {
            Object * pObject1 = new Object();

            pObject1->m_pTransform	= new Transform( 0,0,0, 0,0,0, 4,4,4 );
            //pObject1->m_pMesh		= new MeshQuad();
            pObject1->m_pMesh		= new MeshSphere(20);
            pObject1->m_pMaterial	= new MaterialTask05_3(TEXTURE_FILTER_MODE_POINT);

            pObject1->AddComponent( new ObjectRotator(0, 45, 0) );

            scene.AddObject( pObject1 );
        }

    }

    virtual void Update()
    {

    }
};
