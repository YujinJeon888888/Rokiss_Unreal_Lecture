// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "R1Actor.generated.h"

UCLASS()
class MYPROJECT_API AR1Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AR1Actor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:	
	UPROPERTY(EditAnywhere, Category = "Battle")
	TObjectPtr<AActor> Target;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Box;
};
