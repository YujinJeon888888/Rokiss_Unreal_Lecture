// Fill out your copyright notice in the Description page of Project Settings.



#include "MainActor.h"

#include "R1Actor.h"

// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FClassFinder<AR1Actor> FindClass((TEXT("/Script/CoreUObject.Class'/Script/MyProject.R1Actor'")));
	if (FindClass.Succeeded()) {
		//클래스정보 할당
		ActorClass = FindClass.Class;
	}
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();
	//다른 Actor를 스폰해보자
	FVector Location(0, 10, 10);
	FRotator Rotation(0, 0, 0);
	//Actor = GetWorld()->SpawnActor<AR1Actor>(Location, Rotation);
	//ActorClass의 타입으로 스폰하고 AActor*를 리턴하는데, Actor는 R1Actor타입이므로 캐스팅.
	Actor = Cast<AR1Actor>(GetWorld()->SpawnActor(ActorClass));
	//에러난다. Actor타입과 오른쪽이 안 맞아서
	//Actor =(GetWorld()->SpawnActor(ActorClass));
	
	//5초 뒤 파괴
	//Actor->SetLifeSpan(5.0f);
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

