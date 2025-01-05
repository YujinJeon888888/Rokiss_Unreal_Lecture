// Fill out your copyright notice in the Description page of Project Settings.


#include "R1Actor.h"
#include "Components/StaticMeshComponent.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AR1Actor::AR1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Engine/EditorMeshes/ArcadeEditorSphere.ArcadeEditorSphere'"));
	if (FindMesh.Succeeded()) {
		Box->SetStaticMesh(FindMesh.Object);
	}

}

// Called when the game starts or when spawned
void AR1Actor::BeginPlay()
{
	Super::BeginPlay();

	/*target찾기*/
	Target = UGameplayStatics::GetActorOfClass(GetWorld(), AR1Actor::StaticClass());

}

// Called every frame
void AR1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*단순이동*/
	////속력*시간 = 거리
	//float Speed=500.0f;
	////deltatime: 틱마다의 시간
	//float Distance = DeltaTime*Speed;

	////틱마다 (거리*방향)을 현재 위치에 더해줌 = 이동 
	//FVector MyLocation=GetActorLocation();
	// Unreal forward vector (1,0,0) 
	//FVector NewLocation = MyLocation+(FVector::ForwardVector*Distance);
	//
	////SetActorLocation(NewLocation);

	////현재위치+벡터
	//AddActorWorldOffset(FVector::ForwardVector * Distance);

	/*target으로 이동*/
	if (Target != nullptr) {
		float Speed = 500.0f;
		float Distance = DeltaTime * Speed;

		//상대로 가는 방향
		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();

		//틱마다 움직이도록 내 위치에 새로운 방향과 크기 더해주기
		//방향*크기 = 방향으로 크기만큼 움직여라
		AddActorWorldOffset(DirectionVector * Distance);
	}
}

