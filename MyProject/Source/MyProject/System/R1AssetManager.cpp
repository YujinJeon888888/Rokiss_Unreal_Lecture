// Fill out your copyright notice in the Description page of Project Settings.


#include "System/R1AssetManager.h"
#include "R1LogChannels.h"
UR1AssetManager::UR1AssetManager(): Super()
{
}

UR1AssetManager& UR1AssetManager::Get()
{
	// TODO: 여기에 return 문을 삽입합니다.
	UR1AssetManager* Singleton = Cast<UR1AssetManager>(GEngine->AssetManager);
	if (Singleton) {
		return *Singleton;
	}

	UE_LOG(LogR1, Fatal, TEXT("I can't find UR1AssetManager"));
	return *NewObject<UR1AssetManager>();
}
