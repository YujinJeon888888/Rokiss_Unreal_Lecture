// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/R1PlayerController.h"
#include "R1PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "Character/R1Character.h"

AR1PlayerController::AR1PlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void AR1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Player로부터 EnhancedInput system을 가져온다. 
	auto* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (SubSystem) {
		//mapping context를 추가해주는데, priority는 0
		SubSystem->AddMappingContext(InputMappingContext, 0);
	}
}

void AR1PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//InputComponent는 Actor의 멤버변수이다. 멤버변수를 EnhancedInput으로 캐스팅한다.
	auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (EnhancedInputComponent) {
		//액션에 대해, 트리거 되면 콜백되는 함수를 바인딩한다.
		EnhancedInputComponent->BindAction(TestAction, ETriggerEvent::Triggered, this, &ThisClass::InputTest);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::InputMove);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ThisClass::InputTurn);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::InputJump);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ThisClass::InputAttack);
	}
}

void AR1PlayerController::InputTest(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, TEXT("TEST"));
}

void AR1PlayerController::InputMove(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	if (MovementVector.X != 0) {
		/*FVector Direction = FVector::ForwardVector * MovementVector.X;
		GetPawn()->AddActorWorldOffset(Direction * 50.0f);*/
		
		//내가 바라보는 곳 기준의 앞방향을 구해줌
		FRotator Rotator = this->GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		//MovementInput에 해당 정보를 추가해줘야 함= MovementInput 컴포넌트가 존재해야함
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}
	if (MovementVector.Y != 0) {
		/*FVector Direction = FVector::RightVector * MovementVector.Y;
		GetPawn()->AddActorWorldOffset(Direction * 50.0f);*/

		//내가 바라보는 곳 기준의 앞방향을 구해줌
		FRotator Rotator = this->GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		//MovementInput에 해당 정보를 추가해줘야 함= MovementInput 컴포넌트가 존재해야함
		GetPawn()->AddMovementInput(Direction, MovementVector.Y);
	}
}

void AR1PlayerController::InputTurn(const FInputActionValue& InputValue)
{
	float Val = InputValue.Get<float>();
	AddYawInput(Val);
}

void AR1PlayerController::InputJump(const FInputActionValue& InputValue)
{
	AR1Character* _Player = Cast<AR1Character>(GetPawn());
	if (_Player) {
		//Character 에 이미 있는 기능
		_Player->Jump();
	}
}

void AR1PlayerController::InputAttack(const FInputActionValue& InputValue)
{

}
