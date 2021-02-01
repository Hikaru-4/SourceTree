/*!
@file Player.cpp
@brief プレイヤーなど実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {
	void Player::OnCreate()
	{
		auto drawComp = AddComponent<PNTStaticDraw>();
		drawComp->SetMeshResource(L"DEFAULT_CUBE");
		drawComp->SetDiffuse(Col4(1.0f, 1.0f, 1.0f, 0.25f));

		SetAlphaActive(true);
	}

	void Player::OnUpdate()
	{
		auto& app = App::GetApp(); // アプリケーションオブジェクトを取得する

		// ゲームパッドの参照を取得する
		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition(); // プレイヤーの座標を取得する

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// プレイヤーを左に移動させる
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// プレイヤーを右に移動させる
			pos += Vec3(+1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_UP)
		{
			// プレイヤーを上に移動させる
			pos += Vec3(0.0f, +1.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		{
			// プレイヤーを下に移動させる
			pos += Vec3(0.0f, -1.0f, 0.0f);
		}

		transComp->SetPosition(pos);

		// ブロックを置く
		if (pad.wPressedButtons & XINPUT_GAMEPAD_A)
		{
			MakeBlock<Block>(pos);
		}

		// 地面ブロックを置く
		if (pad.wPressedButtons & XINPUT_GAMEPAD_B)
		{
			MakeBlock<Grass>(pos);
		}

		// ステージのセーブ
		if (pad.wPressedButtons & XINPUT_GAMEPAD_START)
		{
			auto stageMap = GetStageMap();

			auto& app = App::GetApp();
			auto path = app->GetDataDirWString();

			stageMap->SaveTextFile(path + L"stage.txt");
			stageMap->SaveBinaryFile(path + L"stage.stg");

		}


		// ステージに追加されている全てのオブジェクトを解放する
		if (pad.wPressedButtons & XINPUT_GAMEPAD_BACK)
		{
			auto stageMap = GetStageMap();
			stageMap->Clear();
		}
	}

}
//end basecross

