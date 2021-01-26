/*!
@file Player.cpp
@brief プレイヤーなど実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{
	void Player::OnCreate()
	{
		auto drawComp = AddComponent<PNTStaticDraw>();
		drawComp->SetMeshResource(L"DEFAULT_CUBE");
		drawComp->SetDiffuse(Col4(1.0f, 1.0f, 2.0f, 0.25f));

		SetAlphaActive(true);
	}

	void Player::OnUpdate()
	{
		auto& app = App::GetApp();  // アプリケーションオブジェクトを取得する

		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition();

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// プレイヤーを左に移動させる
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// プレイヤーを右に移動させる
			pos += Vec3(1.0f, 0.0f, 0.0f);
		}

		transComp->SetPosition(pos);
		if (pad.wPressedButtons & XINPUT_GAMEPAD_A)
		{
			MakeBlock(pos);
		}
	}

	void Player::MakeBlock(const Vec3& position)
	{
		auto stage = GetStage();
		auto block = stage->AddGameObject<Block>(); // �ｿｽu�ｿｽ�ｿｽ�ｿｽb�ｿｽN�ｿｽ�ｿｽX�ｿｽe�ｿｽ[�ｿｽW�ｿｽﾉ追会ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ

		auto blockTrans = block->GetComponent<Transform>();
		blockTrans->SetPosition(position); // �ｿｽu�ｿｽ�ｿｽ�ｿｽb�ｿｽN�ｿｽﾌ位置�ｿｽ�ｿｽw�ｿｽ�ｿｽﾌ位置�ｿｽﾉ移難ｿｽ�ｿｽ�ｿｽ�ｿｽ�ｿｽ
	}
}
//end basecross

