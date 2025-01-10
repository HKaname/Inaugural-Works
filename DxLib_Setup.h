#pragma once

#include "DxLib.h"
#include "EffekseerForDXLib.h"

class DxLibSetup
{
public:
	DxLibSetup()
	{
		SetOutApplicationLogValidFlag(FALSE);							/*log*/
		SetMainWindowText("game title");								/*タイトル*/
		ChangeWindowMode(TRUE);										/*窓表示*/
		SetUseDirect3DVersion(DX_DIRECT3D_11);							/*directX ver*/
		SetGraphMode(640, 480, 32);		/*解像度*/
		SetUseDirectInputFlag(TRUE);									/*DirectInput使用*/
		SetDirectInputMouseMode(TRUE);									/*DirectInputマウス使用*/
		SetWindowSizeChangeEnableFlag(FALSE, FALSE);			/*ウインドウサイズを手動変更不可、ウインドウサイズに合わせて拡大もしないようにする*/
		SetUsePixelLighting(TRUE);									/*ピクセルライティングの使用*/
		SetFullSceneAntiAliasingMode(4, 2);				/*アンチエイリアス*/
		SetEnableXAudioFlag(TRUE);										/*XAudioを用いるか*/
		Set3DSoundOneMetre(1.0f);								/*3Dオーディオの基準距離指定*/
		SetWaitVSyncFlag(TRUE);											/*垂直同期*/
		DxLib_Init();													/*ＤＸライブラリ初期化処理*/
		Effekseer_Init(8000);									/*Effekseerの初期化*/
		SetSysCommandOffFlag(TRUE);										/*タスクスイッチを有効にするかどうかを設定する*/
		SetChangeScreenModeGraphicsSystemResetFlag(FALSE);				/*Effekseer用*/
		Effekseer_SetGraphicsDeviceLostCallbackFunctions();				/*Effekseer用*/
		SetAlwaysRunFlag(TRUE);											/*background*/
		SetUseZBuffer3D(TRUE);										/*zbufuse*/
		SetWriteZBuffer3D(TRUE);									/*zbufwrite*/
		MV1SetLoadModelPhysicsWorldGravity(-9.8f);						/*重力*/
		SetWindowSize(640, 480);								/*表示するウィンドウサイズ*/
	}

	~DxLibSetup()
	{
		DxLib_End();	// ＤＸライブラリ使用の終了処理
	}

	//裏画面のセッティング
	void SetDraw_Screen(const bool& clear = true)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		if (clear) {
			ClearDrawScreen();
		}
	}

	//裏画面のカメラ情報付きセッティング
	void SetDraw_Screen(const VECTOR& campos, const VECTOR& camvec, const VECTOR& camup, const float& fov, const float& near_, const float& far_)
	{
		SetDraw_Screen(true);
		SetCameraNearFar(near_, far_);
		SetupCamera_Perspective(fov);
		SetCameraPositionAndTargetAndUpVec(campos, camvec, camup);
	}
};
