/*!
@file GameStage.cpp
@brief �Q�[���X�e�[�W����
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

    //--------------------------------------------------------------------------------------
    //    �Q�[���X�e�[�W�N���X����
    //--------------------------------------------------------------------------------------
    void GameStage::CreateViewLight() {
        const Vec3 eye(0.0f, 5.0f, -10.0f);
        const Vec3 at(0.0f);
        auto PtrView = CreateView<SingleView>();
        //�r���[�̃J�����̐ݒ�
        auto PtrCamera = ObjectFactory::Create<Camera>();
        PtrView->SetCamera(PtrCamera);
        PtrCamera->SetEye(eye);
        PtrCamera->SetAt(at);
        //�}���`���C�g�̍쐬
        auto PtrMultiLight = CreateLight<MultiLight>();
        //�f�t�H���g�̃��C�e�B���O���w��
        PtrMultiLight->SetDefaultLighting();
    }

    void GameStage::OnCreate() {
        try {
            auto& app = App::GetApp();
            auto path = app->GetDataDirWString();

            // �e�N�X�`���̓ǂݍ���
            auto texPath = path + L"Textures/";
            app->RegisterTexture(L"block", texPath + L"wall.jpg");
            app->RegisterTexture(L"grass", texPath + L"wall2.jpg");

            //�r���[�ƃ��C�g�̍쐬
            CreateViewLight();

            // �X�e�[�W���Ǘ�����I�u�W�F�N�g��ǉ�����
            auto stageMap = AddGameObject<StageMap>();
            stageMap->Load(path + L"stage.stg");
            m_stageMap = stageMap;

            // �v���C���[��ǉ�
            AddGameObject<Player>();

        }
        catch (...) {
            throw;
        }
    }

}
//end basecross