// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "R1Pawn.generated.h"
/**
 * @author 전유진
 * 
 * @brief Pawn 예제입니다. 
 */
UCLASS()
class MYPROJECT_API AR1Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AR1Pawn();
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	/**
	 * @brief 루트컴포넌트입니다.
	 */
	UPROPERTY(Category = "Character",VisibleAnywhere,BlueprintReadOnly)
	TObjectPtr<class UCapsuleComponent> CapsuleComponent;
	/**
	 * @brief 컴포넌트입니다.
	 */
	UPROPERTY(Category = "Character", VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USkeletalMeshComponent> SkeletalMeshComponent;
	/**
	 * @brief 컴포넌트입니다.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArmComponent;
	/**
	 * @brief 컴포넌트입니다.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> CameraComponent;
};
