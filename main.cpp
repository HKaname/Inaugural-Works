#include "DxLib_Setup.h"
#include "Effekseer.h"
#include <memory>

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//コピーしてはいけない場合unique_ptrを使おう
	auto draw = std::make_unique<DxLibSetup>();
	//
	std::vector<EffekseerEffectHandle> effHndle;	/*エフェクトリソース*/
	std::vector<Effects> effects;					/*エフェクト管理*/
	//事前用意
	/*エフェクトリソースの読み込み*/
	effHndle.resize(effHndle.size() + 1);
	effHndle.back() = EffekseerEffectHandle::load("test.efk");
	/*メインループで使用する際の管理クラスの用意*/
	effects.resize(effHndle.size());

	while (ProcessMessage() == 0) {
		/*演算*/
		{
			//スペースを押しているときエフェクトを設定する
			if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
				effects[0].set(VGet(0.f, 0.f, 0.f), VGet(0.f, 1.f, 0.f), 0.1f);
			}
		}
		//エフェクトの更新
		{
			for (size_t index = 0; index < effHndle.size(); ++index) {
				effects[index].put(effHndle[index]);
			}
		}
		/*描画*/
		{
			//3D(主描画)
			draw->SetDraw_Screen(VGet(0, 0, 10), VGet(0, 0, 0), VGet(0, 1, 0), DX_PI_F / 4, 0.5f, 20.f);
			Effekseer_Sync3DSetting();
			{
				UpdateEffekseer3D();
				//draw3D
				DrawEffekseer3D();
			}
			//2D(UI:ユーザーインターフェース)
			{
				DrawPixel(320, 240, GetColor(255, 255, 255));   // 点を打つ
			}
		}
		ScreenFlip();
		//
		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) {
			break;
		}
	}

	return 0;// ソフトの終了 
}