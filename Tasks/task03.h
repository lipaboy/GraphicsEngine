#pragma once
#include "GraphicsEngine/Application.h"
#include "GraphicsEngine/Camera.h"
#include "GraphicsEngine/GraphicsEngine.h"
#include "GraphicsEngine/GUI.h"
#include "GraphicsEngine/Light.h"
#include "GraphicsEngine/Materials/MaterialUnlit.h"
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


class Task03: public Task
{
private:
    int count;
    double time;
    int fps;
public:
    virtual ~Task03() { }

    virtual void Init()
    {
        Scene & scene = Application::Instance().GetScene();

        // Камера
        {
            Object * pCameraObj = new Object();
            pCameraObj->m_pTransform = new Transform( Vector3(0, 10, 5), Vector3(30.0f, 0.0f, 0.0f));
            Camera * pCamera = new Camera();
            pCamera->SetFovY(90);
            pCamera->SetNearPlane(0.01f);
            pCamera->SetFarPlane(50);
            pCameraObj->AddComponent( pCamera );

            scene.SetCamera( pCamera );
        }

        //Object * pObj1 = NULL;
        for(int j = 0; j < 30; j++){
            for(int i = -15; i < 15; i++) {
                Object * pObject = new Object();
                pObject->m_pMesh        = new MeshCube(5);
                pObject->m_pTransform	= new Transform(2 * i, 0, 2 * j);
                pObject->m_pMaterial	= new MaterialUnlit();
                pObject->AddComponent( new ObjectRotator(0, 2, 0) );

                scene.AddObject( pObject );

                //pObj1 = pObject;
            }
        }


    }

    virtual void Update()
    {
        count++;
        if(Time::GetTime() - time > 1){
            fps = count;
            count = 0;
            time = Time::GetTime();
        }
        //GUI::Label(-1, 2, 200, 100, 123);
        GUI::Label(-1, 0.9, 200, 100, ((double)fps));
    }
};























