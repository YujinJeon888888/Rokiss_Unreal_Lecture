// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MainActor.generated.h"

class AR1Actor;

UCLASS()
class MYPROJECT_API AMainActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY()
	TObjectPtr<AR1Actor> Actor;
	UPROPERTY()
	//해당 클래스 또는 하위 클래스만 할당가능. (안전성up) 객체가 아니라 클래스정보를 할당받는 애.
	TSubclassOf<AR1Actor> ActorClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
