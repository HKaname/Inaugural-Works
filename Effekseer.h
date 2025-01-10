#pragma once

#include "DXLib_vec.hpp"
#include "EffekseerEffectHandle.hpp"
#include <memory>
#include <array>
#include <vector>
#include <cmath>

class Effects
{
public:
	bool flag = false;					/*エフェクトの表示フラグ*/
	size_t id = 0;						/*エフェクトのID*/
	Effekseer3DPlayingHandle handle;	/*エフェクトのハンドル*/
	VECTOR pos;							/*エフェクトの場所*/
	VECTOR nor;							/*エフェクトのY軸の向き*/
	float scale = 1.f;					/*エフェクトのスケール*/
	/*エフェクトの場所を指定し開始フラグを立てる*/
	void set(const VECTOR& pos_, const VECTOR& nor_, float scale_ = 1.f)
	{
		this->flag = true;
		this->pos = pos_;
		this->nor = nor_;
		this->scale = scale_;
	}
	/*エフェクトの開始フラグが立っていればエフェクトを再生*/
	void put(const EffekseerEffectHandle& handle_)
	{
		if (this->flag) {
			//再生チェック
			if (this->handle.IsPlaying()) {
				this->handle.Stop();
			}
			//再生
			this->handle = handle_.Play3D();
			//場所を指定
			this->handle.SetPos(this->pos);
			//向きを指定
			this->handle.SetRotation(atan2(this->nor.y, std::hypotf(this->nor.x, this->nor.z)), atan2(-this->nor.x, -this->nor.z), 0);
			//大きさを指定
			this->handle.SetScale(this->scale);
			//開始フラグを切る
			this->flag = false;
		}
	}
};
