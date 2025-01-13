// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "R1PlayerController.generated.h"

/**
 * 
 */

UCLASS()
class MYPROJECT_API AR1PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AR1PlayerController(const FObjectInitializer& ObjectInitializer);
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
protected:
	UPROPERTY(EditAnyWhere,Category = "Input")
	TObjectPtr<class UInputMappingContext> InputMappingContext;
	UPROPERTY(EditAnyWhere, Category = "Input")
	TObjectPtr<class UInputAction> TestAction;
	UPROPERTY(EditAnyWhere, Category = "Input")
	TObjectPtr<class UInputAction> MoveAction;
	UPROPERTY(EditAnyWhere, Category = "Input")
	TObjectPtr<class UInputAction> TurnAction;
	UPROPERTY(EditAnyWhere, Category = "Input")
	TObjectPtr<class UInputAction> JumpAction;
	UPROPERTY(EditAnyWhere, Category = "Input")
	TObjectPtr<class UInputAction> AttackAction;
private:
	void InputTest(const struct FInputActionValue& InputValue);
	void InputMove(const struct FInputActionValue& InputValue);
	void InputTurn(const struct FInputActionValue& InputValue);
	void InputJump(const struct FInputActionValue& InputValue);
	void InputAttack(const struct FInputActionValue& InputValue);
};
