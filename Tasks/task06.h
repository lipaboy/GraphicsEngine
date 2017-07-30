#pragma once
#include "Tasks/Task.h"
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Meshes/MeshQuad.h"
#include "GraphicsEngine/Meshes/MeshSphere.h"
#include "GraphicsEngine/Transform.h"
#include "GraphicsEngine/Object.h"
#include "GraphicsEngine/Scene.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/Materials/materialtask06.h"
#include "GraphicsEngine/Materials/MaterialDiffuse.h"
#include "GraphicsEngine/Light.h"


class Task06: public Task
{
public:
    virtual ~Task06() { }

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
            pObject1->m_pMaterial	= new MaterialTask06(TEXTURE_FILTER_MODE_POINT);
            //pObject1->m_pMaterial	= new MaterialDiffuse();

            pObject1->AddComponent( new ObjectRotator(0, 45, 0) );

            scene.AddObject( pObject1 );
        }

        // Источник света #1
        {
                Light * pLight = new Light(LightType::LIGHT_DIRECTIONAL);
                pLight->SetColor(0,2,3);
                pLight->SetIntensity(10);

                Object * pLightObject = new Object();
                pLightObject->m_pTransform	= new Transform(1,0,0, 0,90,0, 1,1,1);
                pLightObject->AddComponent(pLight);

                scene.AddLight(pLight);
        }

    }

    virtual void Update()
    {

    }
};
