// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once
#include "Core/Action/BaseInfiniteAction.h"

MEDUSA_BEGIN;

template<typename T>
class IncreaseAction :public BaseInfiniteAction
{
public:
	IncreaseAction(T* data, T min, T max, T speed)
		:mData(data), mMin(min), mMax(max), mSpeed(speed)
	{

	}
	virtual ~IncreaseAction(void) {}
public:
	virtual bool Update(float dt, float blend = 1.f)override
	{
		RETURN_FALSE_IF_FALSE(BaseInfiniteAction::Update(dt, blend));
		*mData += mSpeed*dt*blend;
		*mData = Math::Clamp(*mData, mMin, mMax);
		return true;
	}

	virtual IncreaseAction* Clone()const override
	{
		return new IncreaseAction(mData, mMin, mMax, mSpeed);
	}
	virtual IncreaseAction* Reverse()const override
	{
		return new IncreaseAction(mData, mMin, mMax, -mSpeed);
	}

	static IncreaseAction* Create(T* data, T min, T max, T speed)
	{
		return new IncreaseAction(data, min, max, speed);
	}
private:
	T mMin;
	T mMax;
	T* mData;
	T mSpeed;
};

MEDUSA_END;
