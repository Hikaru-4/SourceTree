/*!
@file Player.cpp
@brief ƒvƒŒƒCƒ„[‚È‚ÇÀ‘Ì
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
		auto& app = App::GetApp();  // ƒAƒvƒŠƒP[ƒVƒ‡ƒ“ƒIƒuƒWƒFƒNƒg‚ğæ“¾‚·‚é

		auto device = app->GetInputDevice();
		const auto& pad = device.GetControlerVec()[0];

		auto transComp = GetComponent<Transform>();
		auto pos = transComp->GetPosition();

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			// ƒvƒŒƒCƒ„[‚ğ¶‚ÉˆÚ“®‚³‚¹‚é
			pos += Vec3(-1.0f, 0.0f, 0.0f);
		}

		if (pad.wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			// ƒvƒŒƒCƒ„[‚ğ‰E‚ÉˆÚ“®‚³‚¹‚é
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
		auto block = stage->AddGameObject<Block>(); // ï¿½uï¿½ï¿½ï¿½bï¿½Nï¿½ï¿½Xï¿½eï¿½[ï¿½Wï¿½É’Ç‰ï¿½ï¿½ï¿½ï¿½ï¿½

		auto blockTrans = block->GetComponent<Transform>();
		blockTrans->SetPosition(position); // ï¿½uï¿½ï¿½ï¿½bï¿½Nï¿½ÌˆÊ’uï¿½ï¿½wï¿½ï¿½ÌˆÊ’uï¿½ÉˆÚ“ï¿½ï¿½ï¿½ï¿½ï¿½
	}
}
//end basecross

