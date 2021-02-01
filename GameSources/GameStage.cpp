/*!
@file GameStage.cpp
@brief ゲームステージ実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

    //--------------------------------------------------------------------------------------
    //    ゲームステージクラス実体
    //--------------------------------------------------------------------------------------
    void GameStage::CreateViewLight() {
        const Vec3 eye(0.0f, 5.0f, -10.0f);
        const Vec3 at(0.0f);
        auto PtrView = CreateView<SingleView>();
        //ビューのカメラの設定
        auto PtrCamera = ObjectFactory::Create<Camera>();
        PtrView->SetCamera(PtrCamera);
        PtrCamera->SetEye(eye);
        PtrCamera->SetAt(at);
        //マルチライトの作成
        auto PtrMultiLight = CreateLight<MultiLight>();
        //デフォルトのライティングを指定
        PtrMultiLight->SetDefaultLighting();
    }

    void GameStage::OnCreate() {
        try {
            auto& app = App::GetApp();
            auto path = app->GetDataDirWString();

            // テクスチャの読み込み
            auto texPath = path + L"Textures/";
            app->RegisterTexture(L"block", texPath + L"wall.jpg");
            app->RegisterTexture(L"grass", texPath + L"wall2.jpg");

            //ビューとライトの作成
            CreateViewLight();

            // ステージを管理するオブジェクトを追加する
            auto stageMap = AddGameObject<StageMap>();
            stageMap->Load(path + L"stage.stg");
            m_stageMap = stageMap;

            // プレイヤーを追加
            AddGameObject<Player>();

        }
        catch (...) {
            throw;
        }
    }

}
//end basecross