// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/R1Player.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"

AR1Player::AR1Player()
{

	//캡슐 콜라이더 산하 컴포넌트
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(this->GetCapsuleComponent());
	//스프링암 산하 컴포넌트
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

}

void AR1Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AR1Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AR1Player::BeginPlay()
{
	Super::BeginPlay();
}
