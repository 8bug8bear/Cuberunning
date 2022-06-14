// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

#define COLLISION_WEAPON ECC_GameTraceChannel1

static const FString SaveSlotName = "DefaultSlotName";

static FText IntToTimeText(int32 Value)
{
	FText Time;
	
	if(Value < 1)
	{
		Time = FText::FromString("--:--");
		return Time;
	}

	if(Value<60)
	{
		int32 Seconds = Value%60;
		Time = FText::FromString(" 0:"+FString::FromInt(Seconds));
		return Time;
	}

	int32 Minets = Value/60;
	int32 Seconds = Value%60;
	Time = FText::FromString(FString::FromInt(Minets)+":"+FString::FromInt(Seconds));
	return Time;
}